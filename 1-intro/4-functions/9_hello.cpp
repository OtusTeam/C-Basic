// OTUS C++ basic course
// Default arguments example

#include <fstream>
#include <iostream>

void greetings(const std::string &name, std::ostream &out = std::cout) {
	out << "Hello, " << name << "\n";
}

int main(int argc, char *argv[]) {
	std::string name;
	std::cout << "Your name:";
	std::cin >> name;
	if (argc < 2) {
		greetings(name);
	} else {
		std::ofstream file(argv[1]);
		if (!file.is_open()) {
			std::cerr << "Failed to open " << argv[1] << "\n";
			return 1;
		}
		greetings(name, file);
	}
}
