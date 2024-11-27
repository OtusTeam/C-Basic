#include <algorithm>
#include <iostream>
#include <vector>

#include <cstdlib>

struct CompareTracer {

	CompareTracer(int value)
		: m_value{value} {
	}

	static void reset() {
		m_counter = 0;
	}

	bool operator<(const CompareTracer &other) const {
		std::cout << "Compare: " << m_value << " < " << other.m_value << std::endl;
		++m_counter;
		return m_value < other.m_value;
	}

	bool operator==(const CompareTracer &other) const {
		std::cout << "Compare: " << m_value << " == " << other.m_value << std::endl;
		++m_counter;
		return m_value == other.m_value;
	}

	bool operator>(const CompareTracer &other) const {
		std::cout << "Compare: " << m_value << " > " << other.m_value << std::endl;
		++m_counter;
		return m_value > other.m_value;
	}

	static std::size_t getCounter() {
		return m_counter;
	}

	friend std::ostream &operator<<(std::ostream &os, const CompareTracer &v) {
		os << v.m_value;
		return os;
	}

private:
	static std::size_t m_counter;
	int m_value;
};

std::size_t CompareTracer::m_counter = 0;

void test_find() {
	std::cout << "\ntest_find\n";

	const int count = 100;
	const int valueToFind = 76;

	std::vector<CompareTracer> values;
	for (int i = 0; i < count; ++i)
		values.emplace_back(i);

	auto iter = std::find(values.cbegin(), values.cend(), CompareTracer{valueToFind});

	if (iter == values.cend())
		std::cout << "not found!" << std::endl;
	else
		std::cout << "found at " << std::distance(values.cbegin(), iter) << "!" << std::endl;

	std::cout << "Compares count = " << CompareTracer::getCounter() << std::endl;
	CompareTracer::reset();
}

void test_bsearch() {
	std::cout << "\ntest_bsearch\n";

	const int count = 100;
	const int valueToFind = 76;

	std::vector<CompareTracer> values;
	for (int i = 0; i < count; ++i)
		values.emplace_back(i);

	const CompareTracer key{valueToFind};
	auto iter = std::bsearch(
		&key,
		values.data(),
		values.size(),
		sizeof(CompareTracer),
		[](const void *l, const void *r) -> int {
			const CompareTracer *left = static_cast<const CompareTracer *>(l);
			const CompareTracer *right = static_cast<const CompareTracer *>(r);
			if (*left < *right)
				return -1;
			if (*left == *right)
				return 0;
			// if (*left > *right)
			return 1;
		});

	if (!iter)
		std::cout << "not found!" << std::endl;
	else
		std::cout << "found at " << (static_cast<CompareTracer *>(iter) - values.data()) << "!" << std::endl;

	std::cout << "Compares count = " << CompareTracer::getCounter() << std::endl;
	CompareTracer::reset();
}

void test_binary_search() {
	std::cout << "\ntest_binary_search\n";

	const int count = 100;
	const int valueToFind = 75;

	std::vector<CompareTracer> values;
	for (int i = 0; i < count; ++i)
		values.emplace_back(i);

	const CompareTracer key{valueToFind};
	bool found = std::binary_search(
		values.cbegin(),
		values.cend(),
		key);

	if (!found)
		std::cout << "not found!" << std::endl;
	else
		std::cout << "found!" << std::endl;

	std::cout << "Compares count = " << CompareTracer::getCounter() << std::endl;
	CompareTracer::reset();
}

void test_lower_bound() {
	std::cout << "\ntest_lower_bound\n";

	const int count = 100;
	const int valueToFind = 75;

	std::vector<CompareTracer> values;
	for (int i = 0; i < count; ++i)
		values.emplace_back(i);

	const CompareTracer key{valueToFind};
	auto iter_lower = std::lower_bound(
		values.cbegin(),
		values.cend(),
		key);

	if (iter_lower == values.cend())
		std::cout << "lower not found!" << std::endl;
	else
		std::cout << "lower bound at " << std::distance(values.cbegin(), iter_lower) << "!" << std::endl;

	std::cout << "Compares count = " << CompareTracer::getCounter() << std::endl;
	std::cout << std::endl;
	CompareTracer::reset();

	auto iter_upper = std::upper_bound(
		values.cbegin(),
		values.cend(),
		key);

	if (iter_upper == values.cend())
		std::cout << "upper not found!" << std::endl;
	else
		std::cout << "upper bound at " << std::distance(values.cbegin(), iter_upper) << "!" << std::endl;

	std::cout << "Compares count = " << CompareTracer::getCounter() << std::endl;
	CompareTracer::reset();
}

void test_ranges() {
	std::cout << "\ntest_ranges\n";

	std::vector<int> values = {0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5};
	const int valueToFind = 4;

	for (int i = 0; i < values.size(); ++i) {
		std::cout << '[' << i << "] = " << values.at(i) << std::endl;
	}

	auto iter_lower = std::lower_bound(
		values.cbegin(),
		values.cend(),
		valueToFind);

	auto iter_upper = std::upper_bound(
		values.cbegin(),
		values.cend(),
		valueToFind);

	auto pair = std::equal_range(
		values.cbegin(),
		values.cend(),
		valueToFind);

	if (iter_lower != values.cend())
		std::cout << "lower bound at " << std::distance(values.cbegin(), iter_lower) << std::endl;
	if (iter_upper != values.cend())
		std::cout << "upper bound at " << std::distance(values.cbegin(), iter_upper) << std::endl;
	if (pair.first != values.cend())
		std::cout << "begin of the equal range at " << std::distance(values.cbegin(), pair.first) << std::endl;
	if (pair.second != values.cend())
		std::cout << "end of the equal range at " << std::distance(values.cbegin(), pair.second) << std::endl;
}

int main() {
	test_find();
	test_bsearch();
	test_binary_search();
	test_lower_bound();
	test_ranges();

	return 0;
}