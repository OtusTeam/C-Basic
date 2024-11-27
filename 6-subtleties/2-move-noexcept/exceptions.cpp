#include <iostream>

namespace naive {

	unsigned int gcd(unsigned int a, unsigned int b) {
		do {
			unsigned r = a % b;
			a = b;
			b = r;
		} while(b);
		return a;
	}

	int example_main(int, char* argv[]) {
		unsigned a = std::atoi(argv[1]);
		unsigned b = std::atoi(argv[2]);

		std::cout << gcd(a, b) << "\n";

		return 0;
	}
} // namespace naive

namespace errors {

	enum class ErrorCode {
		Ok = 0,
		DivisionByZero = 1
	};

	const char* what(ErrorCode err) {
		switch(err) {
		case ErrorCode::Ok:
			return "Ok";
		case ErrorCode::DivisionByZero:
			return "Division by zero!";
		default:
			return "Unknown!";
		}
	}

	template <typename T>
	struct ResultValue {
		T value;
		ErrorCode err;
	};

	ResultValue<unsigned int> gcd(unsigned int a, unsigned int b) {
		if(b == 0) {
			return ResultValue<unsigned int>{0, ErrorCode::DivisionByZero};
		}
		do {
			unsigned r = a % b;
			a = b;
			b = r;
		} while(b);
		return ResultValue<unsigned int>{a, ErrorCode::Ok};
	}

	int example_main(int, char* argv[]) {
		unsigned a = std::atoi(argv[1]);
		unsigned b = std::atoi(argv[2]);

		ResultValue<unsigned int> resultValue = gcd(a, b);
		if(resultValue.err != ErrorCode::Ok) {
			std::cout << "Input data error! " << what(resultValue.err) << std::endl;
			return -1;
		}

		std::cout << resultValue.value << std::endl;

		return 0;
	}

} // namespace errors

namespace exceptions {

	struct DivisionByZeroException : public std::exception {
		const char* what() const noexcept override {
			return "Division by zero!";
		}
	};

	unsigned int gcd(unsigned int a, unsigned int b) {
		if(b == 0) {
			throw DivisionByZeroException{};
		}
		do {
			unsigned r = a % b;
			a = b;
			b = r;
		} while(b);
		return a;
	}

	int example_main(int, char* argv[]) {
		unsigned a = std::atoi(argv[1]);
		unsigned b = std::atoi(argv[2]);

		try {
			std::cout << gcd(a, b) << std::endl;
		} catch(const DivisionByZeroException& ex) {
			std::cout << "Input data error! " << ex.what() << std::endl;
			return -1;
		} catch(const std::exception& ex) {
			std::cout << "Some exception! " << ex.what() << std::endl;
			return -1;
		} catch(...) {
			std::cout << "Unknown exception!" << std::endl;
			return -1;
		}

		return 0;
	}

} // namespace exceptions

int main(int argc, char* argv[]) {

	naive::example_main(argc, argv);
	errors::example_main(argc, argv);
	exceptions::example_main(argc, argv);

	return 0;
}