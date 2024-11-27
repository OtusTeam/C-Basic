// clang++ -fsanitize=thread -g deadlock.cpp -std=c++17 -lpthread
// No, sanitizer thread could not detect a deadlock

// g++ thread -lpthread
// gdb --args ./a.out

#include <iostream>
#include <mutex>
#include <thread>

void good_function() {
	int counter = 0;
	while(true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		std::cout << "Hello from good_function!" << std::endl;
		++counter;
	}
}

void bad_function(std::mutex& m1, std::mutex& m2) {
	[[maybe_unused]] bool b1 = false;
	[[maybe_unused]] bool b2 = false;

	std::lock_guard<std::mutex> lck1{m1};
	b1 = true;

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	std::lock_guard<std::mutex> lck2{m2};
	b2 = true;

	std::cout << "Deadlock here!" << std::endl;
}

int main() {

	std::mutex m1;
	std::mutex m2;


	std::thread thr1{good_function};
	std::thread thr2{bad_function, std::ref(m1), std::ref(m2)};
	std::thread thr3{bad_function, std::ref(m2), std::ref(m1)};

	thr1.join();
	thr2.join();
	thr3.join();

	return 0;
}