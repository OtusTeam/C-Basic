// OTUS C++ basic course example
// program command line arguments and return code

#include <iostream>

int main(int argc, char *argv[]) {

	std::cout << "This program prins all passed command line arguments:" << std::endl;

	for (int i = 0; i < argc; ++i) {
		std::cout << argv[i] << "\n";
	}

	return 0;
}
