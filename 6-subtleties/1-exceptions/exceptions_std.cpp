#include <iostream>
#include <string>
#include <vector>

struct BadClass {
	BadClass(int a) : m_a{a} {}

	BadClass(const BadClass& other) {
		if (other.m_a == 10)
			throw 42;
		m_a = other.m_a;
	}

	int get() const noexcept { return m_a; }
private:
	int m_a;
};

void example() {

	std::string str1{"Hello!"};

	// basic_string( const basic_string& other,
	//           size_type pos,
	//           const Allocator& alloc = Allocator() );
	try {
		std::string str2{str1, 42};
	}
	catch(const std::out_of_range& ex) {
		std::cout << "Out of ranged caught! " << ex.what() << std::endl;
	}
	catch(const std::exception& ex) {
		std::cout << "Base exception caught! " << ex.what() << std::endl;
	}

	std::vector<BadClass> values{0, 1, 2, 3};
	try {
		values.push_back(BadClass{10});
	}
	catch(int a) {
		std::cout << "int exception! " << a << std::endl;
	}
	// values still valid - we can use it
	for (auto& v : values) {
		std::cout << v.get() << ' ';
	}
}

int main(int, char **) {

	example();

	return 0;
}

// noexcept
// strong - 
// basic - 
// no guarantee -
