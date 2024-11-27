// OTUS C++ basic course example
// Hanoi towers problem
// Solution with recursive function

#include <iostream>

void hanoi(int n, char from, char to, char tmp) {
	if (n == 0) {
		return;
	}
	hanoi(n - 1, from, tmp, to);
	std::cout << from << " -> " << to << "\n";
	hanoi(n - 1, tmp, to, from);
}

int main(int argc, char *argv[]) {
	int n = 5;
	if (argc == 2) { // optionaly pass number of disks as command line argument
		n = std::atoi(argv[1]);
	}
	hanoi(n, 'A', 'B', 'C');
}