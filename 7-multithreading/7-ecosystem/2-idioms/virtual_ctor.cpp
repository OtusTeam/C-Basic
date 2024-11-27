#include <iostream>
#include <memory>

namespace motivation {

	struct Base {
		virtual ~Base() = default;
		virtual void do_something() const = 0;
	};

	struct Derived1 : Base {
		void do_something() const override {
			std::cout << "Derived1" << std::endl;
		}
	};

	struct Derived2 : Base {
		void do_something() const override {
			std::cout << "Derived2" << std::endl;
		}
	};

	struct Derived3 : Base {
		void do_something() const override {
			std::cout << "Derived3" << std::endl;
		}
	};

	void user_function(Base* ptr) {
		// we can't create a copy, because we don't know a type
		// ??

		// but we can delete object because of virtual destructor
		// delete ptr

		ptr->do_something();

		delete ptr;
	}

	void example() {
		std::cout << "motivation::example()" << std::endl;

		std::unique_ptr<Base> ptr1 = std::make_unique<Derived1>();
		std::unique_ptr<Base> ptr2 = std::make_unique<Derived2>();
		std::unique_ptr<Base> ptr3 = std::make_unique<Derived3>();

		user_function(ptr1.get());
		user_function(ptr2.get());
		user_function(ptr3.get());

		std::cout << std::endl << std::endl;
	}

} // namespace motivation

namespace solution {

	struct Base {
		virtual ~Base() = default;

		virtual std::unique_ptr<Base> clone() = 0;
		virtual std::unique_ptr<Base> create() = 0;

		virtual void do_something() const = 0;
	};

	struct Derived1 : Base {
	public:
		std::unique_ptr<Base> clone() override {
			return std::make_unique<Derived1>(*this);
		}
		std::unique_ptr<Base> create() override {
			return std::make_unique<Derived1>();
		}

		void do_something() const override {
			std::cout << "Derived1" << std::endl;
		}
	};

	struct Derived2 : Base {
	public:
		std::unique_ptr<Base> clone() override {
			return std::make_unique<Derived2>(*this);
		}
		std::unique_ptr<Base> create() override {
			return std::make_unique<Derived2>();
		}

		void do_something() const override {
			std::cout << "Derived2" << std::endl;
		}
	};

	struct IFileSystemObject {
		size_t size();
		void rename(const char *newName);
	};

	struct File : IFileSystemObject {

	};

	struct Folder : IFileSystemObject {

	};

	void user_function(Base* ptr) {
		// can create new object now
		auto new_instance = ptr->create();
		// cat create copy
		auto copy = ptr->clone();

		ptr->do_something();
	}

	void example() {
		std::cout << "solution::example()" << std::endl;

		std::unique_ptr<Base> ptr1 = std::make_unique<Derived1>();
		std::unique_ptr<Base> ptr2 = std::make_unique<Derived2>();

		user_function(ptr1.get());
		user_function(ptr2.get());

		std::cout << std::endl << std::endl;
	}

} // namespace solution

int main() {

	motivation::example();
	solution::example();

	return 0;
}