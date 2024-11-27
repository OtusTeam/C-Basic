#include <condition_variable>
#include <mutex>
#include <thread>

#include <iostream>

std::condition_variable condition_variable;
std::mutex mutex;
bool notificated = false;

int global = 0;

// Race condition
// Состояние гонки
bool some_variable = true;

// RMW - read modify write

void worker1() {
	while (true) {
		std::unique_lock<std::mutex> lck{mutex};
		std::cout << "Before waiting!" << std::endl;

		// Пропуск уведомления (сделали notify, но никто не сделал wait)
		// Лишнее уведомление (сделали notify_all, а работы на всех не хватило)

		// spurious invocation
		// Ложное пробуждение - condition_variable.wait()

		// guarded suspension
		// spurious invocation
		while (!notificated)
			condition_variable.wait(lck);

		condition_variable.wait(lck,
			[](){ return notificated; }
		);

		notificated = false;


		std::cout << "After waiting!" << std::endl;
	}
}

void worker2() {
	std::unique_lock<std::mutex> lck{mutex};

	std::cout << "Before wake up" << std::endl;

	notificated = true;
	condition_variable.notify_one(); // .....
	// condition_variable.notify_all(); 

	std::cout << "After wake up" << std::endl;
}

void example() {

	std::thread thr1{worker1};
	std::thread thr2{worker2};

	thr1.join();
	thr2.join();
}

int main() {

	example();

	return 0;
}