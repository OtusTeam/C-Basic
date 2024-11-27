#include "line_separator.h"

#include <array>
#include <iostream>
#include <string_view>
#include <vector>

void index_example() {
	////////////////////////////////////////////////////////////////////////////

	// Introduction. NOT the same as C - arrays
	LineSeparator::out("Indexing");

	std::vector<int> vector_1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	for (std::size_t i = 0; i < vector_1.size(); ++i) {
		const auto tmp = vector_1[i] + i;
		std::cout << tmp << " ";
	}
	std::cout << std::endl;

	for (const auto &i : vector_1) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	for (auto it = vector_1.cbegin(); it != vector_1.cend(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout
		<< "First: " << vector_1.front()
		<< ", last: " << vector_1.back()
		<< std::endl;

	// Changing item values.
	auto it = vector_1.begin();

	vector_1[2] = 100;

	it += 5;
	*it = 200;

	// Oppps, UB - no element at 20
	// std::cout << vector_1[222] << std::endl;

	try {
		std::cout << vector_1.at(222) << std::endl;
	} catch (const std::out_of_range &ex) {
		std::cerr << "No element at 222! The error is \"" << ex.what() << "\"." << std::endl;
	}

	const int *data_ptr = vector_1.data();
	data_ptr += 5;
	std::cout << "Data ptr is: " << *data_ptr << std::endl;

	// Const objects are not allowed (elements must be assignable)
	// std::vector<const int> vector_2{10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	// std::cout << vector_2[1] << std::endl;
	// vector_2[4] = 1;     // Compile error: can not assign to const item;

	////////////////////////////////////////////////////////////////////////////

	LineSeparator::out("Vector assignment");

	std::vector<int> vector_3 = {11, 21, 31, 41, 51, 61, 71, 81, 91, 101};
	vector_1 = vector_3;
	for (const auto &i : vector_1) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	////////////////////////////////////////////////////////////////////////////

	// Const vector
	LineSeparator::out("Const vector access");

	const std::vector<int> vector_4 = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	std::cout << "vector_4[5] = " << vector_4[5] << std::endl;
	// const_reference operator[]( size_type pos ) const;
	// vector_4[5] = 234;  // Compile error: requires   reference operator[]( size_type pos );   not a const member

	// Memory reservation
	int N = 1000;
	std::vector<double> vec_6(N, 0.); // allocates at creation

	////////////////////////////////////////////////////////////////////////////

	// Reallocations in for-loop
	LineSeparator::out("Push back reallocation");

	std::vector<double> vec_7(1, -1.);
	vec_7.reserve(6);
	for (std::size_t k = 0; k < 50; ++k) {
		vec_7.push_back(10. * (k + 1));
		std::cout << " size = " << vec_7.size() << " capacity = " << vec_7.capacity();
		std::cout << " " << vec_7.data() << std::endl;
	}

	////////////////////////////////////////////////////////////////////////////

	// Copy constructor, copy assignment operator.
	struct SomeType {
		explicit SomeType(const int x = 123) : x_(x) {
			std::cout << "SomeType ctor " << x_ << " " << this << std::endl;
		}

		~SomeType() {
			std::cout << "SomeType dtor " << x_ << " " << this << std::endl;
		}

		// SomeType(const SomeType& st) = delete;
		SomeType(const SomeType &st) : x_(st.x_) {
			std::cout << "SomeType copy ctor " << x_ << " " << this << std::endl;
		}

		// SomeType & operator= (const SomeType& ) = delete;
		SomeType &operator=(const SomeType &st) {
			std::cout << "SomeType copy assignment " << x_ << " " << this;

			if (&st == this)
				return *this;

			x_ = st.x_;
			std::cout << " x changed " << x_ << std::endl;

			return *this;
		}

		SomeType(const int x, const int y) : SomeType(x) {}

		int Get() const { return x_; }

	private:
		int x_ = -1;
	};

	LineSeparator::out("Constructor by initialization list:");
	std::vector<SomeType> v_some = {SomeType{1},
									SomeType{2},
									SomeType{3},
									SomeType{4},
									SomeType{5}};

	LineSeparator::out("Copy Construction:");
	std::vector<SomeType> v_another(v_some);

	LineSeparator::out("Default Construction:");
	std::vector<SomeType> v_some_0(10);

	LineSeparator::out("SomeType Assignment:");
	v_some_0 = v_some;

	////////////////////////////////////////////////////////////////////////////

	// The same push back for SomeType
	v_some.push_back(SomeType{6});

	// ...or emplace
	v_some.emplace_back(7);
	v_some.emplace_back(8, 80000);

	std::cout << "Is some: ";
	for (const auto &i : v_some) {
		std::cout << i.Get() << " ";
	}
	std::cout << std::endl;

	////////////////////////////////////////////////////////////////////////////

	LineSeparator::out("Insert in the middle:");

	// Inserting in the middle or in front - could be not efficient.

	std::vector<double> slow_slow{1, 2, 3, 4};

	slow_slow.insert(slow_slow.begin(), 10);
	slow_slow.insert(slow_slow.begin() + 3, 10);
}

// ---------------------------------------------------------------------------

// Common interface problem

template <typename Container>
void traversing_container_elements(const Container &data_container, const std::string_view &msg) {
	std::cout << msg << std::endl;

	std::cout << " by index:\t";
	for (std::size_t i = 0; i < data_container.size(); ++i) {
		std::cout << data_container[i] << " ";
	}
	std::cout << std::endl;

	std::cout << " for-each:\t";
	for (const auto &i : data_container) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	std::cout << " by iterator:\t";
	for (auto it = data_container.cbegin(); it != data_container.cend(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << std::endl;
}

void generalization_1_example() {
	LineSeparator::out(" Interface unification:");

	std::array<int, 10> array_1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	traversing_container_elements(array_1, "Array:");

	std::vector<double> vector_2 = {11., 12., 13., 14., 15., 16., 17., 18., 19., 20.};
	traversing_container_elements(vector_2, "Vector:");
}

int main() {
	index_example();
	generalization_1_example();

	return 0;
}
