// clang++ -fsanitize=memory -fno-omit-frame-pointer -g -O2 memory.cpp
// clang++ -fsanitize=address -fno-omit-frame-pointer -g memory.cpp

#include <iostream>

void test_func(int argc) {
	int* arr = new int[5];

	if (arr[1]) {
		std::cout << "Hello!" << std::endl;
	}

	if (argc > 1) {
		if (arr[42]) {
			std::cout << "Hello2!" << std::endl;
		}
	}
}

int main(int argc, char**) {

	test_func(argc);

	return 0;
}