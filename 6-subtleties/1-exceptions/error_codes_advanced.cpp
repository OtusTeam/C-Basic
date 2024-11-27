#include "console_header.hpp"

#include <iostream>

// First make all possible errors as an enum
enum class Error {
	Ok,
	InvalidArgument,
	OutOfMemory,
	InvalidConfiguration
	// , ... many-many other errors
};

// Second make some function which translates error codes to the strings
struct ErrorTrait {
	static bool is_error(Error err) noexcept {
		return err != Error::Ok;
	}

	static const char *to_string(Error err) noexcept {
		switch (err) {
		case Error::Ok:
			return "Ok";
		case Error::InvalidArgument:
			return "Invalid argument";
		case Error::OutOfMemory:
			return "Out of memory";
		case Error::InvalidConfiguration:
			return "Invalid configuration";
		default:
			return "Unknown";
		}
	}
};

// Third make some wrapper, which can contain the error code
struct Result {
	explicit Result(Error err) : m_err{err} {}

	const char *what() const noexcept {
		return ErrorTrait::to_string(m_err);
	}

	bool is_error() const noexcept {
		return ErrorTrait::is_error(m_err);
	}

	Error get_error() const noexcept {
		return m_err;
	}

private:
	Error m_err;
};

namespace result {

	// Ok. Now we have the minimal objects to work with error codes
	Result division(float a, float b, float &result) {
		if (b == 0) {
			std::cerr << "[division] - The second argument is zero!" << std::endl;
			return Result{Error::InvalidArgument};
		}
		result = a / b;
		return Result{Error::Ok};
	}

	void example() {
		Header header{"result::example()"};

		float a = 42;
		float b = 0;
		float result;
		Result err = division(a, b, result);

		if (err.is_error()) {
			std::cout << "Error! What: " << err.what() << std::endl;
		} else {
			std::cout << "The result = " << result << std::endl;
		}
	}
}

// And one more class - the ResultValue
template <typename T>
struct ResultValue : Result {
	ResultValue(Error err, T value) : Result{err}, m_value{value} {}

	T get_value() const {
		return m_value;
	}

private:
	T m_value;
};

namespace result_value {

	ResultValue<float> division(float a, float b) {
		if (b == 0) {
			std::cerr << "[division] - The second argument is zero!" << std::endl;
			return ResultValue<float>{Error::InvalidArgument, 0};
		}
		return ResultValue<float>{Error::Ok, a / b};
	}

	void example() {
		Header header{"result_value::example()"};

		float a = 42;
		float b = 0;
		ResultValue<float> result = division(a, b);

		if (result.is_error()) {
			std::cout << "Error! What: " << result.what() << std::endl;
		} else {
			std::cout << "The result = " << result.get_value() << std::endl;
		}

		// But we have one problem - we can forget to check an error:
		ResultValue<float> result2 = division(a, b);
		std::cout << "The result2 = " << result2.get_value() << std::endl;
	}
}

int main() {

	result::example();

	result_value::example();

	return 0;
}
