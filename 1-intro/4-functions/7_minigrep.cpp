// OTUS C++ basic course
// pass by const reference example
// Minigrep program

#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>

// Print str and highligth with red color chars in range [from, to)
void print_red(const std::string &str, std::size_t from, std::size_t to) {
	const char *red = "\033[0;31m";
	const char *no_color = "\033[0m";
	from = std::min(from, str.size());
	to = std::min(to, str.size());
	std::cout.write(str.data(), from);
	std::cout << red;
	std::cout.write(str.data() + from, to - from);
	std::cout << no_color;
	std::cout.write(str.data() + to, str.size() - to);
}

int main(int argc, char *argv[]) {
	if (argc < 3) {
		std::cerr << "Usage: " << argv[0] << " pattern file\n";
		return 1;
	}
	std::string pattern = argv[1];
	std::ifstream infile(argv[2]);
	if (!infile.is_open()) {
		std::cerr << "Failed to open file " << argv[2] << "\n";
		return 1;
	}
	for (std::string line; std::getline(infile, line);) {
		auto pos = line.find(pattern);
		if (pos != std::string::npos) {
			print_red(line, pos, pos + pattern.size());
			std::cout << "\n";
		}
	}
	return 0;
}