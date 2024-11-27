#include <iostream>

namespace motivation {

	struct Struct1 {
	public:
		Struct1() = default;

		void do_something() {
			std::cout << "Hello from Struct1" << std::endl;
		}
	};

	struct Struct2 {
	public:
		Struct2() = default;

		void do_something() {
			std::cout << "Hello from Struct2" << std::endl;
		}
	};

	struct Other {
	public:
		Other() = default;

		void do_something() {
			m_struct1.do_something();
			m_struct2.do_something();
		}
	private:
		int m_value;
		Struct1 m_struct1;
		Struct2 m_struct2;
	};

	struct Other2 {
	public:
		Other2() = default;

		void do_something() {
		}
	private:
		int m_value;
	};

	void example() {
		std::cout << "motivation::example" << std::endl;

		Struct1 struct1;
		Struct2 struct2;
		Other other;
		Other2 other2;

		std::cout << "sizeof(struct1) = " << sizeof(struct1) << std::endl;
		std::cout << "sizeof(struct2) = " << sizeof(struct2) << std::endl;
		std::cout << "sizeof(other) = " << sizeof(other) << std::endl;
		std::cout << "sizeof(int) = " << sizeof(int) << std::endl;
		std::cout << "sizeof(other2) = " << sizeof(other2) << std::endl;

		std::cout << std::endl << std::endl;
	}

} // motivation

namespace empty_base {

struct Struct1 {
	public:
		Struct1() = default;

		void do_something() {
			std::cout << "Hello from Struct1" << std::endl;
		}
	};

	struct Struct2 {
	public:
		Struct2() = default;

		void do_something() {
			std::cout << "Hello from Struct2" << std::endl;
		}
	};

	struct Other : private Struct1, Struct2 {
	public:
		Other() = default;

		void do_something() {
			Struct1::do_something();
			Struct2::do_something();
		}
	private:
		int m_value;
	};

	struct Other2 {
	public:
		Other2() = default;

		void do_something() {
		}
	private:
		int m_value;
	};

	void example() {
		std::cout << "empty_base::example" << std::endl;

		Struct1 struct1;
		Struct2 struct2;
		Other other;
		Other2 other2;

		std::cout << "sizeof(struct1) = " << sizeof(struct1) << std::endl;
		std::cout << "sizeof(struct2) = " << sizeof(struct2) << std::endl;
		std::cout << "sizeof(other) = " << sizeof(other) << std::endl;
		std::cout << "sizeof(int) = " << sizeof(int) << std::endl;
		std::cout << "sizeof(other2) = " << sizeof(other2) << std::endl;

		std::cout << std::endl << std::endl;
	}

}

int main() {

	motivation::example();
	empty_base::example();

	return 0;
}