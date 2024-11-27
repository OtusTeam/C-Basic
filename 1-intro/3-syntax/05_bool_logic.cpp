#include <bitset>
#include <iostream>
#include <vector>

int main(int, char *[]) {
	bool t = true; // or false
	std::cout << "Size of type bool is: " << sizeof(bool) << std::endl;

	bool t2 = t && false;
	bool t3 = t || false;
	bool t4 = !false;
	std::cout << "t2 = " << t2 << " t3 = " << t3 << " t4 = " << t4 << std::endl;

	int a = 2;		// 0010
	int b = 3;		// 0011
	int r1 = a & b; // 0010
	int r2 = a | b; // 0011
	int r3 = a ^ b; // 0001
	std::cout << "r1 = " << r1 << std::endl;
	std::cout << "r2 = " << r2 << std::endl;
	std::cout << "r3 = " << r3 << std::endl;

	return 0;
}