#include <iostream>

// The problem here - the constructor could not return a value.

class DynamicString {
public:
	DynamicString() : m_data{nullptr}, m_size{0}, m_valid{false} {}

	explicit DynamicString(const char *str) : DynamicString{} {
		if (str == nullptr) {
			m_valid = false;
			return;
		}
		// First need to check the length of the [str]
		size_t length = std::strlen(str);
		if (!length) {
			m_valid = false;
			return;
		}

		*this = DynamicString{str, length};
	}

	DynamicString(const char *str, size_t size) : DynamicString{} {
		if (str == nullptr)
			return;
		// First need to check the length of the [str]
		size_t length = std::strlen(str);
		if (size > length) {
			m_valid = false;
			return;
		}
		length = size;
		// Now we need to allocate memory for the [length] symbols
		m_data = new char[length + 1]; // one more symbol for the zero-termination
		// And now we can copy all symbols from the [str] to the our memory;
		for (size_t i = 0; i < length; ++i) {
			m_data[i] = str[i];
		}
		// Add one more symbol for the zero-termination
		m_data[length] = '\0';
		// Set a correct [m_size] value
		m_size = length;
		// Mark the object as valid
		m_valid = true;
	}

	bool is_valid() const {
		return m_valid;
	}

private:
	char *m_data;
	size_t m_size;
	bool m_valid;
};

bool some_function(const DynamicString& first, const DynamicString& second) {
	if (!first.is_valid()) {
		std::cerr << "[some_function] - the first string is not valid!" << std::endl;
		return false;
	}

	if (!second.is_valid()) {
		std::cout << "[some_function] - the second string is not valid!" << std::endl;
		return false;
	}

	// Do something with strings
	return true;
}

void example() {

	DynamicString str1{"Hello, World!"};
	std::cout << "The str1 is_valid(): " << str1.is_valid() << std::endl;

	DynamicString str2{nullptr};
	std::cout << "The str2 is_valid(): " << str2.is_valid() << std::endl;

	DynamicString str3{"Hello!", 42};
	std::cout << "The str3 is_valid(): " << str3.is_valid() << std::endl;

	some_function(str1, str3);
}

int main() {

	example();

	return 0;
}