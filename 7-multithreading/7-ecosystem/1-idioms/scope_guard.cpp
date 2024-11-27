#include <iostream>
#include <thread>

namespace motivation {

	void example1() {
		std::cout << "Start of the motivation::example1" << std::endl;

		// do something

		std::cout << "End of the motivation::example1" << std::endl;
	}

	void example2(bool condition) {
		std::cout << "Start of the motivation::example2" << std::endl;

		if (condition) {
			// Duplicate code here :(
			std::cout << "End of the motivation::example2" << std::endl;
			return;
		}

		std::cout << "End of the motivation::example2" << std::endl;
	}

	namespace some_c_library {

		void initialize() {
			std::cout << "Hello from initialize function!" << std::endl;
		}

		void deinitialize() {
			std::cout << "Hello from deinitialize function!" << std::endl;
		}

	}

	void example3(bool condition) {
		// call initialization function
		some_c_library::initialize();

		// do some work
		if (condition) {
			// Duplicate code here :(
			some_c_library::deinitialize();
			return;
		}

		// do more work
		some_c_library::deinitialize();
	}

} // namespace motivation

namespace scope_guard {

	template <typename Exit>
	struct scope_guard {
		template <typename TExit>
		explicit scope_guard(TExit&& exit)
				: m_exit{std::forward<TExit>(exit)}
				, m_isSet{true} {
		}

		scope_guard(const scope_guard&) = delete;
		scope_guard(scope_guard&& other)
				: m_exit{std::move(other.m_exit)}
				, m_isSet{other.m_isSet} {
			other.release();
		}

		~scope_guard() {
			destroy();
		}

		scope_guard& operator=(const scope_guard& ) = delete;
		scope_guard& operator=(scope_guard&& other) {
			destroy();
			m_exit = std::move(other.m_exit);
			m_isSet = other.m_isSet;
			other.release();
			return *this;
		}

		void release() noexcept {
			m_isSet = false;
		}
	private:
		void destroy() noexcept(noexcept(std::declval<Exit>()())) {
			if (m_isSet) m_exit();
		}
		Exit m_exit;
		bool m_isSet;
	};

	template<typename Exit>
	scope_guard<typename std::remove_reference<Exit>::type> 
	makeScopeExit(Exit&& exit) {
		return scope_guard<typename std::remove_reference<Exit>::type>{
			std::forward<Exit>(exit)
		};
	}

	void example1() {
		std::cout << "Start of the scope_guard::example1" << std::endl;
		auto scopeExit = makeScopeExit(
			[](){
				std::cout << "End of the scope_guard::example1" << std::endl;
			}
		);

		// do some work
	}

	void example2(bool condition) {
		std::cout << "Start of the scope_guard::example2" << std::endl;
		auto scopeExit = makeScopeExit(
			[](){
				std::cout << "End of the scope_guard::example2" << std::endl;
			}
		);

		if (condition) {
			// no duplicate code here
			return;
		}
	}

	namespace some_c_library {

		void initialize() {
			std::cout << "Hello from initialize function!" << std::endl;
		}

		void deinitialize() {
			std::cout << "Hello from deinitialize function!" << std::endl;
		}

	}

	void example3(bool condition) {
		// call initialization function
		some_c_library::initialize();
		auto scopeExit = makeScopeExit(
			&some_c_library::deinitialize
		);

		// do some work
		if (condition) {
			// No duplicate code here
			return;
		}

		// do more work
	}

	void thread_function() {
		for (size_t i = 0; i < 10; ++i) {
			std::cout << "Hello from thread!" << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
		}
	}

	void example4(bool condition) {
		std::thread thr{thread_function};
		auto scopeExit = makeScopeExit(
			[&thr](){
				thr.join();
				std::cout << "ScopeExit - thread was joined!" << std::endl;
			}
		);

		// do some work

		if (condition) {
			return;
		}

		// do some other work
	}

} // namespace scope_guard


int main() {

	motivation::example1();
	motivation::example2(true);
	motivation::example3(true);

	scope_guard::example1();
	scope_guard::example2(true);
	scope_guard::example3(true);
	scope_guard::example4(true);

	return 0;
}