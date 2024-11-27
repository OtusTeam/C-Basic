#include "compilation.h"

#include <iostream>

#define MY_SUPER_CONSTANT 42

#define MY_SUPER_MAX(a, b) ((a<b)?b:a)

// #define NAME_AND_VALUE(variable) (std::cout << "variable = " << variable << std::endl)

void some_function(int) {

}

void some_other_function(float) {

}

int main() {
	MY_SUPER_CONSTANT;

	some_function(42);

	some_other_function(34.f);

	int max = MY_SUPER_MAX(42, 45);
	// int max2 = MY_SUPER_MAX(1, "hello!"); // Ooops

	// NAME_AND_VALUE(max);

	return 0;
	// exit(0);
}