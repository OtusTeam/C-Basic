#include <iostream>

int main(int, char *[]) {
	int a1 = 1042284544;
	float x1 = *(reinterpret_cast<float *>(&a1));
	std::cout << "From " << a1 << " to " << x1 << std::endl;

	float x2 = 0.15625;
	int a2 = *(reinterpret_cast<int *>(&x2));
	std::cout << "From " << x2 << " to " << a2 << std::endl;

	return 0;
}