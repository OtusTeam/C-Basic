#include "tracer.hpp"

#include <iostream>
#include <string>
#include <vector>

namespace motivation {

	struct Employee {
		std::string first;
		std::string middle;
		std::string last;
		int age;
	};

	void want_to_move_example() {

		std::vector<Employee> empls;
		// Can't do initialization - data required
		// empls.push_back( {...} )

		std::cout << "Enter the next employee, please: " << std::endl;
		for(int i = 0; i < 10; ++i) {
			Employee empl;
			std::cin >> empl.first;  // Ivan
			std::cin >> empl.middle; // Sergeevich
			std::cin >> empl.last;   // Petrov
			std::cin >> empl.age;    // 42

			empls.push_back(empl); // copy here :(
			// .......

			// empl variable is still valid
			std::cout << "You've entered: " << empl.age << ' ' << empl.first << ' ' << empl.middle << ' '
								<< empl.last << std::endl;
			// You've entered: 42 Ivan Sergeevich Petrov
		}
	}

	void want_to_move_example_2() {

		std::vector<Employee> global_list;
		// Somehow fill the global_list

		std::vector<Employee> local_list;
		local_list.push_back(global_list.back()); // copy here
		global_list.pop_back();
	}

	struct StringWithMoving {
		StringWithMoving()
			: m_data{nullptr}
			, m_size{0} {
		}

		StringWithMoving(const char* str)
			: StringWithMoving{} {
			if(!str)
				return;

			m_size = std::strlen(str);
			m_data = new char[m_size + 1];
			std::copy(str, str + m_size, m_data);
			m_data[m_size + 1] = '\0';
		}

		StringWithMoving(const StringWithMoving& rhs)
			: StringWithMoving{rhs.get()} {
		}

		~StringWithMoving() {
			delete[] m_data;
		}

		void move_from(StringWithMoving& rhs) {
			// delete [] m_data; ??
			char* tmp = m_data;
			size_t tmp_size = m_size;

			m_data = rhs.m_data;
			m_size = rhs.m_size;

			rhs.m_data = tmp;
			rhs.m_size = m_size;
		}

		const char* get() const {
			if(m_size)
				return m_data;
			else
				return "";
		}

	private:
		char* m_data;
		size_t m_size;
	};

	struct Employee_with_moving {
		void move_from(Employee_with_moving& rhs) {
			age = rhs.age;

			first.move_from(rhs.first);
			middle.move_from(rhs.middle);
			last.move_from(rhs.last);
		}

		int age;

		StringWithMoving first;
		StringWithMoving middle;
		StringWithMoving last;
	};

	void now_can_move_example() {

		std::vector<Employee_with_moving> empls;

		std::cout << "Enter the next employee, please: " << std::endl;
		for(int i = 0; i < 10; ++i) {
			empls.push_back(Employee_with_moving{});

			Employee_with_moving empl;
			empl.age;    // 42
			empl.first;  // Ivan
			empl.middle; // Sergeevich
			empl.last;   // Petrov

			empls.back().move_from(empl);

			// std::cout << "You've entered: " << empl.age << ' ' << empl.first << ' ' << empl.middle << ' ' <<
			// empl.last << std::endl; You've entered: 0
		}
	}

} // namespace motivation

namespace usage {

	void example1() {

		std::vector<std::string> strings1{"first", "second", "third"};

		// some code here

		std::vector<std::string> strings2;

		// now we need to take the first string from the string1 vector
		// and put it into the strings2 vector

		// without moving
		{
			std::string temp = strings1.back(); // first copy here
			strings1.pop_back();

			strings2.push_back(temp); // second copy here

			// we still can use temp here with correct behaviour
			std::cout << temp;
		}

		// with moving
		{
			int v1 = 42;
			int v2 = v1;

			std::string temp = std::move(strings1.back()); // no copy, but moving
			strings1.pop_back();

			strings2.emplace_back(std::move(temp)); // no copy, but moving

			// we can't use a value of the temp here (undefined)
			temp = "value";
		}
	}

	void example2() {

		struct Employee {
			std::string first;
			std::string middle;
			std::string last;
		};

		std::vector<Employee> empls;
		for(int i = 0; i < 3; ++i) {
			Employee empl;
			std::cin >> empl.first;
			std::cin >> empl.middle;
			std::cin >> empl.last;

			empls.emplace_back(std::move(empl));
		}
	}

} // namespace usage

namespace custom {

	struct string {
		string()
			: m_data{nullptr}
			, m_size{0} {
		}

		explicit string(const char* value) {
			m_size = std::strlen(value) + 1; // one more byte for term null
			if(m_size) {
				m_data = new char[m_size];
				std::copy(value, value + m_size, m_data);
				m_data[m_size - 1] = '\0';
			}
		}

		// copy ctor
		string(const string& rhs) {
			m_size = rhs.m_size;
			m_data = new char[m_size];
			std::copy(rhs.m_data, rhs.m_data + m_size, m_data);
		}

		// l-value reference - T&, string&
		// r-value reference - T&&, string&&

		// move ctor
		string(string&& rhs)
			: m_data{nullptr}
			, m_size{0} {
			swap(*this, rhs);
		}

		~string() {
			delete[] m_data;
		}

		// void test(int) {}
		// void test(float) {}
		// void test(std::string) {}

		void test() {

			std::string str{"Some"};

			// 1. copy ctor
			std::string copy{str}; // std::string&
			// move ctor
			std::string move{std::move(str)}; // std::string& -> std::string&&

			// 2. copy assignment operator
			copy = str;

			// move assignment operator
			copy = std::move(str);
		}

		string& operator=(const string& rhs) {
		}

		string& operator=(string&& rhs) {
		}

		const char* get() const {
			if(m_size)
				return m_data;
			else
				return "\0";
		}

	private:
		friend void swap(string& lhs, string& rhs) {
			std::swap(lhs.m_data, rhs.m_data);
			std::swap(lhs.m_size, rhs.m_size);
		}

		char* m_data;
		size_t m_size;
	};

	void example() {
		std::cout << std::endl << std::endl;
		std::cout << "*****     custom::example()     *****" << std::endl;

		custom::string str{"trololo"};
		std::cout << str.get() << std::endl;

		std::cout << "***   after copy:" << std::endl;
		custom::string str2{str}; // copy or move? -> copy

		std::cout << "str2 = " << str2.get() << std::endl;
		std::cout << "str = " << str.get() << std::endl;

		std::cout << "***   after move:" << std::endl;
		custom::string str3{std::move(str)};

		std::cout << "str3 = " << str2.get() << std::endl;
		std::cout << "str = " << str.get() << std::endl;

		std::cout << std::endl << std::endl;
	} // destructor for str

} // namespace custom

// Move medium
void moveMedium() {
	std::cout << "Move medium:" << std::endl;

	std::string value{"Aha-a-a-a-a-a!"};

	std::string value2 = std::move(value);

	std::cout << "  value is: \"" << value << "\" at #" << &value << std::endl; // NOLINT

	// the comment disables linter ^^^^^^
	// warning about variable usage
	// after moving

	std::cout << "  value2 is: \"" << value2 << "\" at #" << &value2 << std::endl;
}

#if 0
// Possible implementation of std::move
template <typename T>
typename std::remove_reference<T>::type && move(T &&arg) {
    // Move doesn't move!

    return static_cast<typename std::remove_reference<T>::type &&>(arg);
}
#endif

//-----------------------------------------------------------------------------

int main(const int argc, char*[]) {

	return 0;
}