#include <iostream>

// self assignment check

namespace motivation {

	struct some_struct {

		some_struct(size_t size)
			: m_data{new int[size]}, m_size{size} {}
		~some_struct() {
			delete[] m_data;
		}

		some_struct(const some_struct &rhs) {
			m_data = new int[rhs.m_size];
			m_size = rhs.m_size;
		}

		some_struct &operator=(const some_struct &rhs) {
			delete[] m_data;
			// What if *this == rhs?
			// We are in trouble
			m_data = new int[rhs.m_size];
			m_size = rhs.m_size;
			return *this;
		}

	private:
		size_t m_size;
		int *m_data;
	};

	void example() {
		std::cout << "motivation::example" << std::endl;

		some_struct some{42};
		some = some; // Ooops

		std::cout << std::endl
				  << std::endl;
	}

} // namespace motivation

namespace copy_and_swap {

	struct some_class {

		some_class(int data_size)
			: m_size{data_size}, m_data{new int[data_size]} {
		}
		~some_class() {
			delete[] m_data;
		}

		some_class(const some_class &other) {
			m_size = other.m_size;
			m_data = new int[m_size];
			// copy data here
		}

		some_class &operator=(const some_class &other) {
			// create new object from other
			some_class tmp{other}; // allocation
			// if exception here, current object is still valid
			// swap - this operation could not throw
			swap(*this, tmp);
			return *this;
		}

	private:
		void swap(some_class &lhs, some_class &rhs) {
			std::swap(lhs.m_data, rhs.m_data);
			std::swap(lhs.m_size, rhs.m_size);
		}

		int m_size;
		int *m_data;
	};

	void example() {
		std::cout << "copy_and_swap::example" << std::endl;

		some_class some{42};
		// Good now
		some = some;
		// But need additional allocation

		std::cout << std::endl
				  << std::endl;
	}

} // copy_and_swap

namespace self_check {

	struct some_class {

		some_class(int data_size)
			: m_size{data_size}, m_data{new int[data_size]} {
		}
		~some_class() {
			delete[] m_data;
		}

		some_class(const some_class &other) {
			m_size = other.m_size;
			m_data = new int[m_size];
			// copy data here
		}

		some_class &operator=(const some_class &other) {
			if (this != &other) {
				// create new object from other
				some_class tmp{other};
				// if exception here, current object is still valid
				// swap - this operation could not throw
				swap(*this, tmp);
			}
			return *this;
		}

	private:
		void swap(some_class &lhs, some_class &rhs) {
			std::swap(lhs.m_data, rhs.m_data);
			std::swap(lhs.m_size, rhs.m_size);
		}

		int m_size;
		int *m_data;
	};

	void example() {
		std::cout << "self_check::example" << std::endl;

		some_class some{42};
		// Very good now
		some = some;

		std::cout << std::endl
				  << std::endl;
	}

} // self_check

int main() {

	motivation::example();
	copy_and_swap::example();
	self_check::example();

	return 0;
}