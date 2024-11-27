#include "example.h"

#include <iostream>

void todo_move_me_out() {
	std::cout << "This function should be located in the separated source file" << std::endl;
}

int main() {
	std::cout << "Hello, World!" << std::endl;

	example_function();
	todo_move_me_out();
	
	return 0;
}