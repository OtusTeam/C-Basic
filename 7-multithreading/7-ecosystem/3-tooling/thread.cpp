// clang++ -fsanitize=thread thread.cpp -lpthread -g

#include <iostream>
#include <thread>

int g_value = 42;

int do_increment(int &value) {
	++value;
	return value;
}

int main() {
	std::thread thr1{do_increment, std::ref(g_value)};
	std::thread thr2{do_increment, std::ref(g_value)};

	thr1.join();
	thr2.join();

	return 0;
}