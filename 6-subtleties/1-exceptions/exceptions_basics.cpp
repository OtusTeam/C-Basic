#include "console_header.hpp"

#include <iostream>

namespace throwing {

	float division(float a, float b) {
		if (b == 0)
			throw 42;
		return a / b;
	}

	void example() {
		Header header{"throwing::example()"};

		float a = 13;
		float b = 0;
		float result = division(13, 0);
	}

} // namespace throwing

namespace catching {

	float division(float a, float b) {
		if (b == 0)
			throw 42; // int
		return a / b;
	}

	void example1() {
		Header header{"catching::example1()"};

		float a = 13;
		float b = 0;
		try {
			float result = division(13, 0);
			std::cout << "The result = " << result << std::endl;
		} catch (int err) {
			std::cout << "Caught the exception with value: " << err << std::endl;
		}
	}

	void example2() {
		Header header{"catching::example2()"};

		float a = 13;
		float b = 0;
		try {
			float result = division(13, 0);
			std::cout << "The result = " << result << std::endl;
		} catch (...) {
			std::cout << "Caught the unknown exception!" << std::endl;
		}
	}

} // namespace catching

namespace sequential_calls {

	enum class Error {
		Ok,
		InvalidArgument
	};
	const char *to_string(Error err) noexcept {
		switch (err) {
		case Error::Ok:
			return "Ok";
		case Error::InvalidArgument:
			return "Invalid argument";
		default:
			return "Unknown";
		}
	}

	float func(float a, float b) {
		// The invariant here - b should not be zero
		if (b == 0) {
			std::cerr << "[func] - b is zero!" << std::endl;
			// logger::getInstance.error("[func] - b is zero!");
			throw Error::InvalidArgument;
		}
		return a / b;
	}

	float other_func(float a, float b) {
		// The invariant here - b should not be greater than 10.
		if (b > 10) {
			std::cerr << "[other_func] - b is greater than 10" << std::endl;
			throw Error::InvalidArgument;
		}

		float c = func(a, b);
		return a + b + c;
	}

	float and_one_more_func(float a, float b) {
		// The invariant here - a should not be 100
		if (a == 100) {
			std::cerr << "[and_one_more_func] - a is 100" << std::endl;
			throw Error::InvalidArgument;
		}

		float c = other_func(a, b);

		return a * b + c;
	}
	
	// and_one_more_func -> other_func -> func

	void example() {
		Header header{"sequential_calls::example()"};

		try {
			float a = 100;
			float b = 2;
			float result = and_one_more_func(a, b);
			std::cout << "result = " << result << std::endl;
		} catch (Error err) {
			std::cout << "Caught the error: " << to_string(err) << std::endl;
		}

		try {
			float a = 25;
			float b = 25;
			float result = and_one_more_func(a, b);
			std::cout << "result = " << result << std::endl;
		} catch (Error err) {
			std::cout << "Caught the error: " << to_string(err) << std::endl;
		}

		try {
			float a = 25;
			float b = 0;
			float result = and_one_more_func(a, b);
			std::cout << "result = " << result << std::endl;
		} catch (Error err) {
			std::cout << "Caught the error: " << to_string(err) << std::endl;
		}
	}

} // sequential_calls

int main(int, char **) {

	try {

		// throwing::example();

		catching::example1();
		catching::example2();

		sequential_calls::example();

	} catch (...) {
		std::cout << "Something happened!" << std::endl;
	}

	return 0;
}