#include <condition_variable>
#include <iostream>
#include <mutex>
#include <optional>
#include <queue>
#include <thread>

constexpr static int productsCount = 1000;

namespace cv {

	class Queue {
	public:
		void push(int value) {
			std::unique_lock lock{mutex};
			queue.push(value);
			cv.notify_one();
		}

		/** @brief Takes entry with waiting is case of empty queue.
		 *  @param entry result entry.
		 *  @note This is blocking function!
		 *  @return false in case of empty stopped queue
		 */
		bool pop(int &value) {
			std::unique_lock lock{mutex};
			cv.wait(lock, [this]() {
				return !queue.empty() || stopped;
			});

			bool noMore = queue.empty() && stopped;

			if (!queue.empty()) {
				value = queue.front();
				queue.pop();
			}
			return !noMore;
		}

		/** @brief Notificates all threads to unblock them.
		 */
		void stop() {
			std::unique_lock lock{mutex};
			stopped = true;
			cv.notify_all(); // (!) all
		}

	private:
		std::condition_variable cv;
		std::mutex mutex;
		std::queue<int> queue;
		bool stopped{};
	};

	void example() {
		Queue queue;
		int total{};

		auto producer = std::thread([&]() {
			for (int i = 0; i < productsCount; ++i) {
				queue.push(i);
			}
			queue.stop();
		});

		std::vector<std::thread> consumers;
		for (int i = 0; i < 10; ++i) {
			consumers.emplace_back(std::thread([&]() {
				int value{};

				while (queue.pop(value)) {
					total += value;
				}
			}));
		}

		producer.join();
        for(auto& c : consumers)
		    c.join();

		std::cout << total << std::endl;
		std::cout << productsCount * (productsCount - 1) / 2 << std::endl;
	}
}

int main() {
	cv::example();
}