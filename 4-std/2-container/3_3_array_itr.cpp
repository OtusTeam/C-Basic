#include "line_separator.h"
#include <cstddef>
#include <iostream>

// Making unique interface for Array<T> type (the same as List<T> interface)

template <typename T, std::size_t n>
class Array {
public:
	T &operator[](std::size_t i) {
		return data_[i];
	}

	class Iterator {
	public:
		Iterator() noexcept : itr_ptr_(nullptr) {}

		Iterator(T *itr_ptr) noexcept : itr_ptr_(itr_ptr) {}

		Iterator &operator++() {
			// if (index_ < n)
			++itr_ptr_;
			return *this;
		}

		bool operator!=(const Iterator &iterator) {
			return itr_ptr_ != iterator.itr_ptr_;
		}

		T &operator*() {
			return *itr_ptr_;
		}

	private:
		T *itr_ptr_;
	};

	Iterator begin() {
		return Iterator(data_);
	}

	Iterator end() {
		return Iterator(data_ + n);
	}

private:
	T data_[n];
};

// ---------------------------------------------------------------------------

// Common interface works with iterators

template <typename T>
void iterate_container_elements(T &data_container, const std::string &msg) {
	std::ignore = msg;
	// std::cout << msg << std::endl;

	LineSeparator::out(" Begin-end for:");
	auto itr = data_container.begin();
	for (; itr != data_container.end(); ++itr) {
		std::cout << (*itr) << " ";
	}
	std::cout << std::endl;

	LineSeparator::out(" for_each loop:");
	for (const auto &item : data_container) {
		std::cout << " " << item;
	}
	std::cout << std::endl;
}

int main(int, char *[]) {
	LineSeparator::out(" Validate that standard access works:");
	constexpr std::size_t n = 15;
	Array<int, n> array_7;
	array_7[5] = 99;
	std::cout << array_7[5] << std::endl;

	LineSeparator::out(" Fill elements in increasing order:");
	for (std::size_t i = 0; i < n; ++i) {
		array_7[i] = static_cast<int>(i);
	}

	LineSeparator::out(" Iterate array elements with iterator:");
	iterate_container_elements(array_7, "Array:");

	return 0;
}
