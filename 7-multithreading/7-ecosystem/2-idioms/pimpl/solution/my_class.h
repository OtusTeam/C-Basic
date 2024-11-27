#pragma once

#include <cstddef>

// pointer to implementation (pimpl)
namespace my {

	struct my_class {
	public:
		explicit my_class(const char * path);
		~my_class();

		size_t do_work();
		void do_other_work(int param);
	private:
		struct impl;
		impl* m_impl; // pimpl
	};

} // namespace my