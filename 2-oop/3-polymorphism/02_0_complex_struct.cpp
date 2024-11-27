#include <iostream>

struct Complex
{
	float real;
	float im;
};

Complex complex_sum(
		Complex first, // The first complex number
		Complex second // The second complex number
	)
{
	Complex result;
	result.real = first.real + second.real;
	result.im = first.im + second.im;
	return result;
}

int main()
{
	Complex first;
	std::cout << "Enter the first complex number in the format: [real part] [image part]\n";
	std::cin >> first.real >> first.im;

	Complex second;
	std::cout << "Enter the second complex number in the format: [real part] [image part]\n";
	std::cin >> second.real >> second.im;

	Complex result = complex_sum(first, second);

	std::cout << "The result: " << result.real << " + " << result.im << "i\n";
}
