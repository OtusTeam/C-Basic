#include <bitset>
#include <iostream>
#include <vector>

int main(int, char *[]) {
	// 1. One-line statement
	if (false) {
		std::cout << "\nThis condition is executed" << std::endl;
		std::cout << "\nAnd this condition is executed in any case of if condition\n"
				  << std::endl;
	}

	// 2. Multiline if
	bool condition_value = true;
	if (condition_value) {
		std::cout << "\nIt contains a sequence of commads" << std::endl;
		int a = 364;
		std::cout << "a = " << a << std::endl;
	}

	// 3. if else
	bool condition_value_2 = true; // 3.444;
	if (!condition_value_2) {
		std::cout << "Condition is true --- " << std::endl;
		std::cout << "\t\t\t --- print out one more line" << std::endl;
	} else {
		std::cout << "Condition is false" << std::endl;
		int x = 100;
		int y = 200;
		std::cout << "Prefix increment:  " << ++x << std::endl;
		std::cout << "Postfix increment: " << y++ << std::endl;
	}

	// 4. if, if-else, else
	int x = 51;
	if (x < 6 || (0 == x % 2)) {
		std::cout << "first condition is selected \n";
	} else if (x > 1000) {
		std::cout << " second condition " << std::endl;
	} else if (x > 50 && (x % 17 == 0)) {
		std::cout << " third condition " << std::endl;
	} else
		std::cout << "Finally, none of conditions was selected.." << std::endl;
		std::cout << "Finally, none of conditions was selected.." << std::endl;

	// 5. Ternary operator
	// boolean-condition ? value-1 (true) : value-2 (false)
	int z = 10;
	int y = 100;

	int a = (z < y) ? 23 : 1000;

	std::cout << "Ternary operator result: " << a << std::endl;

	// 6. Nested if
	int w1 = 234;
	if (w1 > 0) {
		if (w1 < 100) {
			std::cout << "w1 is less then 100" << std::endl;
		} else if (w1 > 200) {
			std::cout << "w1 is greater then 200" << std::endl;
		}
	}

	return 0;
}