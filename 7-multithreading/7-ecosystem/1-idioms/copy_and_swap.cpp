#include <iostream>

namespace motivation {

	struct some_class {
	public:
		explicit some_class(int data_size)
			: m_size{data_size}
			, m_data{new int[data_size]} { // exception

		}
		~some_class() {
			delete [] m_data;
		}

		some_class(const some_class& other) {
			m_size = other.m_size;
			m_data = new int[m_size]; // exception
			// copy data here
		}

		some_class& operator=(const some_class& other) {
			// clear current data
			delete [] m_data;
			m_size = other.m_size;
			// allocate new region
			m_data = new int[m_size]; // Ooops. What if exception here?

			// 1. Exception safety - bad :(
			// 2. Duplicating code - bad :(
			return *this;
		}
	private:
		int *m_data;
		int m_size;
	};

	void example() {
		some_class some1{42};
		some_class some2{56};

		try {
			some1 = some2;
		}
		catch(...) {
			// ....
		}

		// I'he caught all exceptions... But object some1 is invalid!
		some1;
	}

} // motivation

namespace copy_and_swap {

struct some_class {

	public:
		some_class(int data_size)
			: m_size{data_size}
			, m_data{new int[data_size]} {

		}
		~some_class() {
			delete [] m_data;
		}

		some_class(const some_class& other) {
			m_size = other.m_size;
			m_data = new int[m_size];
			// copy data here
		}

		some_class& operator=(const some_class& other) {
			// create new object from other
			some_class tmp{other};
			// if exception here, current object is still valid
			// swap - this operation could not throw 
			swap(*this, tmp);
			return *this;
		}
	private:
		void swap(some_class& lhs, some_class& rhs) {
			std::swap(lhs.m_data, rhs.m_data);
			std::swap(lhs.m_size, rhs.m_size);
		}

		int *m_data;
		int m_size;
	};

	void example() {

		some_class some1{42};
		some_class some2{56};

		try {
			some1 = some2;
		}
		catch(...) {

		}

		// Object some1 is valid here
		some1;

	}

} // namespace copy_and_swap

int main() {
	motivation::example();

	return 0;
}