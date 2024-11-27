#include "console_header.hpp"

#include <iostream>
#include <string>

namespace polymorphism {

	struct IException {
		explicit IException() {}
		virtual std::string what() const = 0;
	};

	struct Exception : public IException {
		explicit Exception(const char *msg) : m_msg{msg} {}
		explicit Exception(const std::string &msg) : m_msg{msg} {}
		virtual std::string what() const override {
			return m_msg;
		}

	private:
		std::string m_msg;
	};

	struct LogicError : public Exception {
		explicit LogicError(const char *msg) : Exception{msg} {}
		explicit LogicError(const std::string &msg) : Exception{msg} {}

		virtual std::string what() const override {
			return "LogicError: " + Exception::what();
		}
	};

	struct RuntimeError : public Exception {
		explicit RuntimeError(const char *msg) : Exception{msg} {}
		explicit RuntimeError(const std::string &msg) : Exception{msg} {}

		virtual std::string what() const override {
			return "RuntimeError: " + Exception::what();
		}
	};

	void bad_example() {
		Header header{"polymorphism::bad_example()"};

		try {
			throw RuntimeError{"Out of memory!"};
		} catch (const Exception &ex) {
			std::cout << "Caught the Exception object: " << ex.what() << std::endl;
		} catch (const LogicError &ex) {
			std::cout << "Caught the LogicError object: " << ex.what() << std::endl;
		} catch (const RuntimeError &ex) {
			std::cout << "Caught the RuntimeError object: " << ex.what() << std::endl;
		}
	}

	void bad_example2() {
		Header header{"polymorphism::bad_example2()"};

		try {
			throw RuntimeError{"Out of memory!"};
		} catch (const Exception& ex) {
			std::cout << "Caught the Exception object: " << ex.what() << std::endl;
		} catch (const LogicError& ex) {
			std::cout << "Caught the LogicError object: " << ex.what() << std::endl;
		} catch (const RuntimeError& ex) {
			std::cout << "Caught the RuntimeError object: " << ex.what() << std::endl;
		}
	}

	void good_example() {
		Header header{"polymorphism::good_example()"};

		try {
			throw RuntimeError{"Out of memory!"}; // RuntimeError*
		} catch (const RuntimeError& ex) {
			std::cout << "Caught the RuntimeError object: " << ex.what() << std::endl;
		} catch (const LogicError& ex) {
			std::cout << "Caught the LogicError object: " << ex.what() << std::endl;
		} catch (const Exception& ex) {
			std::cout << "Caught the Exception object: " << ex.what() << std::endl;
		}
	}
}

int main(int, char **) {

	polymorphism::bad_example();
	polymorphism::bad_example2();

	return 0;
}