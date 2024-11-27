#include "line_separator.h"

#include <string>
#include <unordered_map>

int main(int argc, char *argv[]) {
	std::unordered_map<std::string, std::string> numbers2words = {
		{"4", "four"},
		{"5", "five"},
	};
	print_assoc(numbers2words);

	numbers2words.insert(std::make_pair("1", "one"));
	print_assoc(numbers2words);

	numbers2words["2"] = "two";
	print_assoc(numbers2words);

	if (const auto &it = numbers2words.find("2"); it != numbers2words.cend()) {
		std::cout << it->first << ": " << it->second << '\n';
	} else {
		std::cout << "Key not found\n";
	}

	if (const auto &it = numbers2words.find("42"); it != numbers2words.cend()) {
		std::cout << it->first << ": " << it->second << '\n';
	} else {
		std::cout << "Key not found\n";
	}

	for (const auto &[key, value] : numbers2words) {
		std::cout << key << ": " << value << ", ";
	}
	std::cout << '\n';
}