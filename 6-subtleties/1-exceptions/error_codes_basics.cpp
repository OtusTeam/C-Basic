#include "console_header.hpp"

#include <iostream>

// The motivation example - simple function which calculates
// the division of two numbers (a / b).
// One problem here - there is no any check for the b value - is
// should not be zero.

namespace motivation {

	float division(float a, float b) {
		return a / b;
	}

	void example() {
		Header header{"motivation::example()"};

		std::cout << "Hello from super division calculator!" << std::endl;
		std::cout << "Enter the first number, please:" << std::endl;

		float a;
		std::cin >> a;

		std::cout << "Enter the seconf number, pease:" << std::endl;
		float b;
		std::cin >> b;

		float result = division(a, b);

		std::cout << "The result is: " << std::endl;
		std::cout << result << std::endl;
	}
} // namespace motivation

// The naive solution example - let's check b number right before the function
// call.
// It is not a good solution, because we get a violation of encapsulation here -
// the calling code should "know" all precondition which should be checked.

namespace naive {

	float division(float a, float b) {
		return a / b;
	}

	void example() {
		Header header{"naive::example()"};

		std::cout << "Hello from super division calculator!" << std::endl;
		std::cout << "Enter the first number, please:" << std::endl;

		float a;
		std::cin >> a;

		std::cout << "Enter the seconf number, pease:" << std::endl;
		float b;
		std::cin >> b;

		// violation of encapsulation here
		if (b == 0) {
			std::cout << "Error! The second number could not be zero!" << std::endl;
		} else {
			float result = division(a, b);

			std::cout << "The result is: " << std::endl;
			std::cout << result << std::endl;
		}
	}
} // namespace naive

// The example with error codes. No the best solution also, but it
// works.
// The main problem here - we should change the function signature
// and make additional check in the calling code.

namespace error_code {

	/*
		@brief Calculates a division of two arguments
		@param a [in] - the first argument for division
		@param b [in] - the second argument for division
		@param result [out] - the result of division (a / b)
		@return false in case of b argument is zero, and the operation 
		could not be calculated properly
		true otherwise.
	*/
	bool division(float a, float b, float& result) {
		if (b == 0) {
			return false;
		}
		result = a / b;
		return true;
	}

	/*
		@brief Calculates a sum of two arguments
		@param a [in] - the first argument for sum
		@param b [in] - the second argument for sum
		@param result [out] - the result of sum (a + b)
		@return true in any cases
	*/
	bool sum(float a, float b, float& result) {
		result = a + b;
		return true;
	}

	void example() {
		Header header{"error_code::example()"};

		std::cout << "Hello from super division calculator!" << std::endl;
		std::cout << "Enter the first number, please:" << std::endl;

		float a;
		std::cin >> a;

		std::cout << "Enter the seconf number, pease:" << std::endl;
		float b;
		std::cin >> b;

		float result;
		bool error = division(a, b, result);
		
		// Note here! We could not check - what exactly was wrong!
		if (!error) {
			std::cout << "Error!" << std::endl;
		} else {
			std::cout << "The result is: " << std::endl;
			std::cout << result << std::endl;
		}
	}
} // error_code


// The sequential calls is the worst case scenario for error codes - 
// any step could fail. And we should add error checks into the each call.
// Sometimes the error check code takes up more space than the main functional 
// code.
//  if(2)	 if(3)		if(4)
// func1 -> func2 -> func3 -> func4

namespace sequential_calls {

	bool func(float a, float b, float& result) {
		// The invariant here - b should not be zero
		if (b == 0) return false;
		result = a / b;
		return true;
	}

	bool other_func(float a, float b, float& result) {
		// The invariant here - b should not be greater than 10.
		if (b > 10) return false;

		float c;
		bool code = func(a, b, c);
		if (!code) return false;
		result = a + b + c;
		return true;
	}

	bool and_one_more_func(float a, float b, float& result) {
		// The invariant here - a should not be 100
		if (a == 100) return false;

		float c;
		bool code = other_func(a, b, c);
		if (!code) return false;

		result = a * b + c;
		return true;
	}

	void example() {
		Header header{"sequential_calls::example()"};

		float a = 32;
		float b = 0;
		
		float result;
		bool code = and_one_more_func(a, b, result);

		if (code) {
			std::cout << "Something goes wrong... And I really don't know - what and where!" << std::endl;
		}
		else {
			std::cout << "The result is:" << std::endl;
			std::cout << result << std::endl;
		}
	}

}


int main(int, char **) {

	motivation::example();

	naive::example();

	error_code::example();

	sequential_calls::example();

	// Erorr code :)
	return 0;
}