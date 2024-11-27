#include "my_class.h"

#include <fstream>
#include <iostream>
#include <list>
#include <mutex>
#include <string>
#include <vector>

namespace my {

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
		m_impl = std::make_unique<my_class::impl>(path); // 
	}

	// Comment me to see an error
	my_class::~my_class() {
	}

	my_class::my_class(my_class&& rhs) noexcept {
		m_impl = std::move(rhs.m_impl);
	}

	my_class& my_class::operator=(my_class&& rhs) noexcept {
		m_impl = std::move(rhs.m_impl);
		return *this;
	}

	std::size_t my_class::do_work() {
		return 0;
	}

	void my_class::do_other_work(int param) {
		m_impl->do_other_work(param);
	}

} // namespace my