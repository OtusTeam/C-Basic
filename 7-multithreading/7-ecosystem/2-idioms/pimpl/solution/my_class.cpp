#include "my_class.h"

#include <fstream>
#include <iostream>
#include <list>
#include <mutex>
#include <string>
#include <vector>

namespace my {

	// struct A {
	// 	struct B {
	// 		struct C {
	// 			C();
	// 		};
	// 	};
	// };

	// A::B::C::C() {

	// }

	struct my_class::impl {
	public:
		explicit impl(const char *path) {
			std::cout << "my_class::impl::impl - path: " << path << std::endl;
		}

		std::size_t do_work() {
			return 42;
		}

		void do_other_work(int) {
		}
	private:
		std::fstream m_file; // file to work with
		std::vector<uint8_t> m_buffer; // temporary buffer to read data
		std::mutex m_mutex; // because of multi thread implementation
		std::list<std::string> m_tokens; // unique tokens list
	};

	my_class::my_class(const char *path) {
		std::cout << "my_class::my_class - path: " << path << std::endl;
		m_impl = new my_class::impl{path};
	}

	my_class::~my_class() {
		delete m_impl;
	}

	std::size_t my_class::do_work() {
		return m_impl->do_work();
	}

	void my_class::do_other_work(int param) {
		m_impl->do_other_work(param);
	}

} // namespace my