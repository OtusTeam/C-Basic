#pragma once

#include <iostream>
#include <string_view>

struct LineSeparator {
	static void out(const std::string_view &msg) {
		std::cout << "\n---------------------------------";
		std::cout << msg << std::endl;
	}
};

template <class Container>
void print(const Container &container) {
	for (const auto &item : container) {
		std::cout << item << ' ';
	}
	std::cout << '\n';
}

template <class Container>
void print_assoc(const Container &container) {
	for (const auto &item : container) {
		std::cout << item.first << ": " << item.second << ", ";
	}
	std::cout << '\n';
}
