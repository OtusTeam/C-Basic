#pragma once

#include <memory>

#include <cstddef>

namespace my {

	struct my_class {
	public:
		explicit my_class(const char * path);
		// Comment me (and the definition in the .cpp) to see an error
		~my_class();

		my_class(const my_class& rhs) = delete;
		my_class(my_class&& rhs) noexcept;

		my_class& operator=(const my_class& rhs) = delete;
		my_class& operator=(my_class&& rhs) noexcept;

		size_t do_work();
		void do_other_work(int param);
	private:
		struct impl;
		std::unique_ptr<impl> m_impl; // pimpl
	};

} // namespace my