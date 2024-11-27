#include <algorithm>
#include <iostream>
#include <list>
#include <random>
#include <vector>

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &values) {
	for (auto &v : values)
		std::cout << v << ' ';
	return os;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::list<T> &values) {
	for (auto &v : values)
		std::cout << v << ' ';
	return os;
}

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

void test_sort() {
	std::cout << "\ntest_sort\n";

	std::vector<CompareTracer> source = {{9}, {8}, {7}, {6}, {5}, {4}, {3}, {2}, {1}, {0}};

	// bool is_sorted( ForwardIt first, ForwardIt last, Compare comp );

	std::cout << "is_sorted = " << std::is_sorted(source.cbegin(), source.cend(), std::greater<>()) << std::endl
			  << std::endl;

	std::random_shuffle(source.begin(), source.end());
	std::vector<CompareTracer> target1 = source;

	std::cout << "Values before sorting:\n";
	std::cout << target1 << std::endl
			  << std::endl;

	// void sort( RandomIt first, RandomIt last, Compare comp );

	std::sort(target1.begin(), target1.end());

	std::cout << "Compares count = " << CompareTracer::getCounter() << std::endl;
	CompareTracer::reset();

	std::cout << "target1 after sort:\n";
	std::cout << target1 << std::endl
			  << std::endl;

	std::vector<CompareTracer> target2 = source;

	// void partial_sort( RandomIt first, RandomIt middle, RandomIt last, Compare comp );

	std::partial_sort(target2.begin(), std::next(target2.begin(), 3), target2.end());

	std::cout << "Compares count = " << CompareTracer::getCounter() << std::endl;
	CompareTracer::reset();

	std::cout << "target2 after partial_sort:\n";
	std::cout << target2 << std::endl
			  << std::endl;

	std::vector<CompareTracer> target3 = source;
	std::nth_element(target3.begin(), std::next(target3.begin(), target3.size() / 2), target3.end());

	std::cout << "target3 after nth_element:\n";
	std::cout << target3 << std::endl;
	std::cout << "Compares count = " << CompareTracer::getCounter() << std::endl;
	CompareTracer::reset();
	std::cout << std::endl;

	using TPair = std::pair<CompareTracer, int>;
	std::vector<TPair> target4 = {
		std::make_pair(CompareTracer{9}, 0),
		std::make_pair(CompareTracer{9}, 1),
		std::make_pair(CompareTracer{9}, 2),
		std::make_pair(CompareTracer{9}, 3),
		std::make_pair(CompareTracer{9}, 4),
		std::make_pair(CompareTracer{8}, 0),
		std::make_pair(CompareTracer{8}, 1),
		std::make_pair(CompareTracer{8}, 2),
		std::make_pair(CompareTracer{7}, 0),
		std::make_pair(CompareTracer{6}, 0),
		std::make_pair(CompareTracer{5}, 0)};

	std::cout << "target4 before stable sort:\n";
	for (auto &p : target4) {
		std::cout << '[' << p.first << ", " << p.second << "] ";
	}
	std::cout << std::endl;

	std::stable_sort(target4.begin(), target4.end(), [](const TPair &l, const TPair &r) {
		return l.first < r.first;
	});

	std::cout << "target4 after stable sort:\n";
	for (auto &p : target4) {
		std::cout << '[' << p.first << ", " << p.second << "] ";
	}
	std::cout << std::endl;
}

void test_list() {
	std::cout << "\ntest_list\n";

	std::list<int> values = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

	std::cout << "Values before sorting:\n";
	std::cout << values << std::endl
			  << std::endl;

	// std::sort(values.begin(), values.end());

	values.sort();

	std::cout << "Values after sorting:\n";
	std::cout << values << std::endl
			  << std::endl;

	// No such methods
	// values.stable_sort();
	// values.partial_sort();
}

int main() {
	test_sort();
	test_list();

	return 0;
}