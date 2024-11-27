#pragma once

#include <fstream>
#include <iostream>
#include <list>
#include <mutex>
#include <string>
#include <vector>

#include <cstddef>

namespace my {

	struct my_class {
	public:
		explicit my_class(const char * path);

		size_t do_work();
		void do_other_work(int param);
	private:
		std::fstream m_file; // file to work with
		std::vector<uint8_t> m_buffer; // temporary buffer to read data
		std::mutex m_mutex; // because of multi thread implementation
		std::list<std::string> m_tokens; // unique tokens list
	};

} // namespace my