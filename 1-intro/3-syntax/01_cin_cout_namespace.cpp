#include <iostream>
#include <string>










































namespace my_own_namespace {
	int global_variable = 42;
	std::string global_str = "String";
}

int main() {
	std::cout << "global_variable = " << my_own_namespace::global_variable << std::endl;


	using namespace my_own_namespace;
	std::cout << "global_variable (after using) = " << global_variable << std::endl;

	int global_variable = 56;

	std::cout << "global_variable (after local) = " << global_variable << std::endl;
	std::cout << "my_own_namespace::global_variable (after local) = " << my_own_namespace::global_variable << std::endl;

	int value1, value2;
	std::string name;

	std::cout << "Input your name: " << std::endl;
	std::cin >> name;

	std::cout << "Input your name (without endl): ";
	std::cin >> name;

	std::cout << "Input value1 and value2: " << std::endl;
	std::cin >> value1 >> value2;

	std::cout << "Hi (without endl), " << name << std::endl;
	std::cout << "Hi, " << name << std::endl;
	std::cout << "sum of two values is: " << value1 + value2 << std::endl;

	return 0;
}
