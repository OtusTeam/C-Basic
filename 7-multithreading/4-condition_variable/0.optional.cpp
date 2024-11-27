#include <optional>
#include <iostream>

// https://en.cppreference.com/w/cpp/utility/optional

// bool read_line(const char* filepath, std::string& out);
// the same with optional:
// std::optional<std::string> read_line(const char*filepath);

int main() {

	std::optional<int> int_optional;

	std::optional<std::string> optional{"Hello, World!"};
	std::optional<std::string> empty{};

	std::cout << "Attemp to get value from `optional` variable: " << std::endl;
	try {

		if(optional.has_value()) {
			std::cout << "optional has a value" << std::endl;
		}
		else {
			std::cout << "optional does not have a value" << std::endl;
		}

		std::string str = optional.value();
		std::cout << "Value from `optional`: " << str << std::endl;

		std::string str2 = optional.value_or("Hello!");
		std::cout << "value_or from `optional`: " << str2 << std::endl;

	} catch (std::bad_optional_access& ex) {
		std::cout << "std::bad_optional_access exception! what: " << ex.what() << std::endl;
	}

	std::cout << "Attemp to get value from `empty` variable: " << std::endl;
	try {

		if(empty.has_value()) {
			std::cout << "empty has a value" << std::endl;
		}
		else {
			std::cout << "empty does not have a value" << std::endl;
		}

		std::string str = empty.value();

	} catch (std::bad_optional_access& ex) {
		std::cout << "std::bad_optional_access exception! what: " << ex.what() << std::endl;
	}

	std::string str2 = empty.value_or("Hello!");
	std::cout << "value_or from `empty`: " << str2 << std::endl;

	return 0;
}