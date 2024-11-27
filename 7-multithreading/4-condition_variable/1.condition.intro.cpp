#include <atomic>
#include <iostream>
#include <mutex>
#include <optional>
#include <queue>
#include <thread>

const int productsCount = 1000;

namespace heater {

	class Queue {
	public:
		void push(int value) {
			std::lock_guard lock{mutex};
			queue.push(value);
		}

		std::optional<int> pop() {
			std::optional<int> result;
			std::lock_guard lock{mutex};

			if (!queue.empty()) {
				result = queue.front();
				queue.pop();
			}
			return result;
		}

	private:
		std::mutex mutex;
		std::queue<int> queue;
	};

	void producer_function(Queue &queue) {
		for (int i = 0; i < productsCount; ++i) {
			queue.push(i);
		}
	}

	void consumer_function(Queue &queue, int &total, std::atomic<bool> &stopped) {
		// !??
		while (!stopped) {
			auto value = queue.pop();
			if (value) {
				total += *value; // value.value()   proposal
			}
			else {
				std::this_thread::sleep_for(std::chrono::microseconds(1));
			}
		}
		while(auto value = queue.pop()) {
			total += *value; // value.value()   proposal
		}
	}

	// template <typename T>
	// struct ref {
	// 	T &data;
	// };

	void example() {
		Queue queue;
		std::atomic<bool> stopped{};
		int total{};

		// thread starts here
		auto producer = std::thread(producer_function, std::ref(queue));

		// thread starts here
		auto consumer = std::thread(consumer_function, std::ref(queue), std::ref(total), std::ref(stopped));

		producer.join();
		stopped = true;
		consumer.join();

		std::cout << total << std::endl;
		std::cout << productsCount * (productsCount - 1) / 2 << std::endl;
	}
}

int main() {
	heater::example();
}