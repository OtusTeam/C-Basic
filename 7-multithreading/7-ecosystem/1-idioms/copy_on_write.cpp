#include <iostream>
#include <memory>

namespace motivation {

	void example() {

		std::cout << "motivation::example()" << std::endl;

		std::string some_huge_string = "I'm too huge to be copied...";

		std::string copy1 = some_huge_string; // :(
		std::cout << copy1 << std::endl;

		std::string copy2 = some_huge_string; // Good
		copy2 += " Changed!";
		std::cout << copy2 << std::endl;

		std::cout << std::endl
				  << std::endl;
	}

}

namespace copy_on_write {

	struct COW_string {
		explicit COW_string(const char *ptr)
			: m_ref{std::make_shared<std::string>(ptr)} {
		}
		explicit COW_string(const std::string &str)
			: COW_string(str.data()) {
		}

		COW_string(const COW_string &other) {
			m_ref = other.m_ref;
		}

		// Constant version - just return a reference
		const std::string &operator*() const {
			return *m_ref;
		}

		// Non-const version - copy now
		std::string &operator*() {
			do_detach();
			return *m_ref;
		}

		// Constant version - just return a reference
		const std::string *operator->() const {
			return m_ref.get();
		}

		// Non-const version - copy now
		std::string *operator->() {
			do_detach();
			return m_ref.get();
		}

	private:
		void do_detach() {
			std::string *tmp = m_ref.get();
			// Copy only if current pointer is not nullptr and current ref is shared
			if (!(tmp == 0 || m_ref.use_count())) {
				m_ref = std::make_shared<std::string>(*tmp);
			}
		}

		std::shared_ptr<std::string> m_ref;
	};

	void example() {

		std::cout << "copy_on_write::example()" << std::endl;

		COW_string str{"I'm too huge to be copied..."};
		// check the data() pointer
		std::cout << std::hex << "str pointer: " << (int *)str->data() << std::endl;

		// Do copy without copying
		const COW_string copy1{str};
		std::cout << "copy1 value: " << *copy1 << std::endl;
		std::cout << std::hex << "copy1 pointer: " << (int *)copy1->data() << std::endl;

		const COW_string copy2{str};
		std::cout << "copy2 value: " << *copy2 << std::endl;
		std::cout << std::hex << "copy2 pointer: " << (int *)copy2->data() << std::endl;

		// Do change
		COW_string copy3{copy2};
		*copy3 += " Changed!";
		std::cout << "copy3 value after change: " << *copy3 << std::endl;
		std::cout << std::hex << "copy3 pointer after change: " << (int *)copy3->data() << std::endl;
		std::cout << "copy1 value: " << *copy1 << std::endl;
		std::cout << "copy2 value: " << *copy2 << std::endl;

		std::cout << std::endl
				  << std::endl;

		// Problem
		{
			COW_string str1{"String1"};
			char &c = str1->operator[](0); // take a reference to one symbol
			const COW_string str2{str1};
			c = '0';

			std::cout << "str1 value: " << *str1 << std::endl;
			std::cout << "str2 value: " << *str2 << std::endl;
		}
	}

}

int main() {
	motivation::example();

	copy_on_write::example();

	return 0;
}