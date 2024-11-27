#include <iostream>
#include <iomanip>


// Преимущества функций:
// 1. Переиспользование кода
// 2. Структурирование кода
// 3. Возможно делегирования работы
// 4. Удобство тестирования
// 5. 

int main() {

	double base = 0;
	double exp = 0;

	std::cout << "Enter base: ";
	std::cin >> base;
	std::cout << std::endl;

	std::cout << "Enter exp: ";
	std::cin >> exp;
	std::cout << std::endl;

	double result = 1;
	for (unsigned int i = 0; i < exp; ++i) {
		result *= base;
	}

	std::cout << std::setprecision(10) << "pow(" << base << ", " << exp << ") = " << result << std::endl;
	// pow(3.1415926, 8) = 9488.529721

	return 0;
}