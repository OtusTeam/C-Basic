#include "line_separator.h"

#include <array>
#include <iostream>

void index_example() {
	////////////////////////////////////////////////////////////////////////////

	// 1. Introduction. The same as C - arrays
	LineSeparator::out("Elements access:");

	// Fixed type. Fixed size.
	std::array<int, 10> array_1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	array_1[1] = 100;

	for (std::size_t i = 0; i < array_1.size(); ++i) {
		const auto &tmp = array_1[i] + i;
		std::cout << tmp << " ";
	}
	std::cout << std::endl;

	for (const auto &i : array_1) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	for (auto it = array_1.cbegin(); it != array_1.cend(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// Const correctness
	std::array<const int, 10> array_2 = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	// array_2[4] = 1;     // Compile error: can not assign to const item

	std::array<const int, 10> array_3 = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	// array_3 = array_1; // Compile error: no operator = (const std::array<const T> & )

	const std::array<int, 10> array_4 = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	// array_4[5] = 55;   // Compile error: assign to const variable
	// std::cout << array_4[5] << std::endl;
	// reference operator[]( size_type pos );   not a const member

	////////////////////////////////////////////////////////////////////////////

	LineSeparator::out("Elements access:");

	auto tmp_4 = array_4[5];
	std::cout << tmp_4 << std::endl;
	// const_reference operator[]( size_type pos ) const;

	const int *data_ptr = array_4.data();
	data_ptr += 3;
	std::cout << "Data ptr is: " << *data_ptr << std::endl;

	////////////////////////////////////////////////////////////////////////////

	LineSeparator::out("Custom type can be const");

	struct NameOut {
		NameOut() { std::cout << "NameOut ctor" << std::endl; }
		~NameOut() { std::cout << "NameOut dtor" << std::endl; }

		std::string_view GetOut() const { return "This is my out!"; }
	};
	std::array<const NameOut, 3> xname = {NameOut(), NameOut(), NameOut()};

	std::cout << xname[2].GetOut() << std::endl;

	std::cout << xname.at(2).GetOut() << std::endl;

	// Oppps, UB - no element at 20
	// std::cout << xname[20].GetOut() << std::endl;

	try {
		std::cout << xname.at(20).GetOut() << std::endl;
	} catch (const std::out_of_range &ex) {
		std::cerr << "No element at 20! The error is \"" << ex.what() << "\"." << std::endl;
	}

	////////////////////////////////////////////////////////////////////////////

	LineSeparator::out("Cpp17");

	const std::array cpp17_1 = {NameOut(), NameOut(), NameOut()};
	const auto cpp17_2 = std::array{NameOut(), NameOut(), NameOut()};
}

int main() {
	index_example();

	return 0;
}
