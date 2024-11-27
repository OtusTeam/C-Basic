#include "../include/utils.h"

#include <iostream>

namespace project
{

std::vector<int> read_sequence(std::istream& is) {
	std::vector<int> values;
	int v = 0;
	while (is >> v) {
		values.push_back(v);
	}
	return values;
}

void print_sequence(const std::vector<int> &seq, std::ostream& os) {
	for (size_t i = 0; i < seq.size(); ++i) {
		if (i != 0)
			os << ' ';
		os << seq[i];
	}
	os << '\n';
}

std::vector<int> filter_even(const std::vector<int> &seq) {
	std::vector<int> evens;
	for (size_t i = 0; i < seq.size(); ++i) {
		if (seq[i] % 2 == 0) {
			evens.push_back(seq[i]);
		}
	}
	return evens;
}

} // namespace project
