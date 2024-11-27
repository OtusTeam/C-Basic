#include <atomic>
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

namespace list {
    constexpr static int productsCount = 1000;

    // Mutex + pointer
    template<typename T>
    struct WithMutex {
        template<class TT>
        WithMutex(TT&& ptr): ptr{std::forward<TT>(ptr)} {}

        T ptr;
        std::mutex mutex;
    };

    template<typename T>
    struct WaitingQueue {

        WaitingQueue()
            : head{new Node}, tail{head.ptr.get()}, m_stopped{false} {
        }

        /** @brief Takes entry with waiting is case of empty queue.
         *  @param entry result entry.
         *  @note This is blocking function!
         *  @return false in case of empty stopped queue
         */
        bool pop(T& entry) {
            auto wakeUpCond = [this] () {
                return m_stopped || head.ptr.get() != getTailSafe();
            };

            std::unique_lock lck{head.mutex};
            m_conditional.wait(lck, wakeUpCond);

            if (m_stopped)
                return false;
            // Take value
            entry = std::move(head.ptr->value);
            // And remove head node from the list
            takeHeadUnsafe();
            return true;
        }

        /** @brief Try to takes entry without waiting
         *  @param entry result entry.
         *  @return false in case of empty queue
         */
        bool tryPop(T& entry) {
            std::lock_guard<std::mutex> lck{head.mutex};
            if (head.get() == getTailSafe()) {
                // WaitingQueue is empty
                return {};
            }
            // Take value from the head node.
            entry = std::move(head->value);
            // And remove head node from the list.
            std::unique_ptr<Node> prevHead = takeHeadUnsafe();
            return prevHead.get() != nullptr;
        }

        template<typename TT>
        void push(TT&& value) {
            std::lock_guard<std::mutex> lck{tail.mutex};

            if (!m_stopped) {
                tail.ptr->value = std::forward<TT>(value);
                tail.ptr->next.reset(new Node);
                tail.ptr = tail.ptr->next.get();
                m_conditional.notify_one();
            }
        }

        /// @brief Notificates all threads to unblock them.
        void stop() {
            std::scoped_lock lock(head.mutex, tail.mutex);
            m_stopped = true;
            m_conditional.notify_all();
        }

    private:
        struct Node {
            T value;
            std::unique_ptr<Node> next;
        };

        Node* getTailSafe() {
            std::lock_guard<std::mutex> lck{tail.mutex};
            return tail.ptr;
        }

        std::unique_ptr<Node> takeHeadUnsafe() {
            std::unique_ptr<Node> prevHead = std::move(head.ptr);
            head.ptr = std::move(prevHead->next);
            return prevHead;
        }

        // head element of the WaitingQueue
        WithMutex<std::unique_ptr<Node>> head;
        // pointer to the tail element
        WithMutex<Node*> tail;
        // Condition for waiting data
        std::condition_variable m_conditional;
        // Stop flag
        bool m_stopped;
    };

    using WorkQueue = WaitingQueue<int>;

    void work_producer(WorkQueue& queue, std::atomic<bool>& stop_flag) {
        for (int i = 0; i < productsCount; ++i) {
            // put new work to the queue
            std::cout << "work_producer - put new value: " << i << std::endl;
            if (!stop_flag)
                queue.push(i);
            else
                break;
            // wait a bit before the next iteration
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        std::cout << "work_producer - end of cycle" << std::endl;
    }

    void work_consumer(WorkQueue& queue) {
        int value = 0;
        // make a waiting pop from the queue
        while (queue.pop(value)) {
            std::cout << "work_consumer - pop new value: " << value << std::endl;
        }
        std::cout << "work_consumer - end of cycle" << std::endl;
    }

    void example() {
        std::atomic<bool> stop_flag = false;
        WorkQueue work_queue;

        std::cout << "Launch threads!" << std::endl;

        std::thread work_producer_thread{
                work_producer,
                std::ref(work_queue),
                std::ref(stop_flag)
        };
        std::thread work_consumer_thread1{
                work_consumer,
                std::ref(work_queue)
        };
        std::thread work_consumer_thread2{
                work_consumer,
                std::ref(work_queue)
        };

        std::this_thread::sleep_for(std::chrono::seconds{5});

        std::cout << "Finish working!" << std::endl;

        // stop all threads
        stop_flag = true;
        // need this to unblock all threads, witch are waiting the queue
        work_queue.stop();
        // wait all threads
        work_producer_thread.join();
        work_consumer_thread1.join();
        work_consumer_thread2.join();

        std::cout << "Finished!" << std::endl;
    }
}

int main() {
    list::example();
}