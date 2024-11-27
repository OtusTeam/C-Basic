#include "console_header.hpp"

#include <iostream>
#include <string>

namespace basic_types {

	void example() {
		Header header{"basic_types::example()"};

		// We can trow exception with any type
		// For example - float
		try {
			throw 42.f;
		} catch (float err) {
			std::cout << "Float exception:" << err << std::endl;
		}

		// const char * - also
		try {
			throw "Hello, World!";
		} catch (const char *err) {
			std::cout << "const char * exception: " << err << std::endl;
		}

		// even std::string
		try {
			throw std::string{"Hello!"};
		} catch (const std::string &err) {
			std::cout << "std::string exception: " << err << std::endl;
		}

		// exception of any type could be cathed by (...)
		try {
			throw 42;
		} catch (...) {
			// But we can't take a value - because we don't know a type
			std::cout << "Unknown exception!" << std::endl;
			// Looks useless...
		}
	}
} // namespace basic_types

namespace rethrow {

	void func(int a) {
		std::string str{"trololo"};
		if (a == 0)
			throw 42;
	}

	void other_func(int a) {
		// allocate memory
		int *ptr = new int{10}; // 4 byte

		// Call the func.
		// If the func will throw an exception, the memory ptr will leake.
		// But we don't want to handle an exception.
		// So, we can just catch the "unknown" exception to clear memory
		// and rethrow it to the calling side.
		try {
			func(a);
		} catch (...) {
			std::cout << "Unknow exception!" << std::endl;
			// any exception here - just to cleanup
			delete ptr;
			// rethrow
			throw;
		}
		// do something else
		delete ptr;
	}

	// We can rethrow exception if it needed
	void example() {
		Header header{"rethrow::example()"};

		try {
			other_func(0);
		} catch (int err) {
			std::cout << "Exception! " << err << std::endl;
		}
	}
}

namespace custom_types {

	struct Exception {
		explicit Exception(const char *msg) : m_msg{msg} {}

		explicit Exception(const std::string &msg) : m_msg{msg} {}

		std::string what() const {
			return m_msg;
		}

	private:
		std::string m_msg;
	};

	void throws_int() {
		throw 42;
	}

	void throws_exception() {
		throw Exception{"Exception!"};
	}

	void example() {
		Header header{"custom_types::example()"};

		try {
			throws_int();
		} catch (int err) {
			std::cout << "Caught the int exception = " << err << std::endl;
		}

		try {
			throws_exception();
		} catch (const Exception &ex) {
			// Caught
			std::cout << "Caught the Exception object: " << ex.what() << std::endl;
			// throw 42;
		} catch (int err) {
			// Not works
			std::cout << "Caught the int exception = " << err << std::endl;
		}

		try {
			throws_exception();
		}
		// Compile error - catch-all handler must come last
		// catch (...) {
		// 	std::cout << "Caught the unknown exception!" << std::endl;
		// }
		catch (int err) {
			std::cout << "Caught the int exception = " << err << std::endl;
		} catch (const Exception &ex) {
			std::cout << "Catcher the Exception object: " << ex.what() << std::endl;
		}
		catch(...) {
			std::cout << "Caught the unknown exception!" << std::endl;
		}
	}

}

int main(int, char **) {

	basic_types::example();

	rethrow::example();

	custom_types::example();

	return 0;
}