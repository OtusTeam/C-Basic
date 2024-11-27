#include "tracer.hpp"

#include <string>
#include <vector>

namespace rule_of_five {

	struct RuleOfFiveStruct {

		RuleOfFiveStruct() {
		} // default ctor

		RuleOfFiveStruct(const RuleOfFiveStruct&) {
		} // copy ctor

		RuleOfFiveStruct(RuleOfFiveStruct&&) noexcept {
		} // move ctor

		RuleOfFiveStruct& operator=(const RuleOfFiveStruct&) { // copy assignment operator
			return *this;
		}

		RuleOfFiveStruct& operator=(RuleOfFiveStruct&&) noexcept { // move assignment operator
			return *this;
		}
	};

} // namespace rule_of_five

namespace no_except {

	void function() noexcept {
		// this function should not throw an exception
	}

	// overload by noexcept specificator is not allowed
	// void function() {
	// }

	void test() {
		std::cout << "function is noexcept: " << noexcept(function) << std::endl;
	}

	struct SomeStruct {
		void method() noexcept {
			// this method should not throw an exception
		}

		void one_more_method() noexcept(true) {
			// this method should not throw an exception
		}

		void and_one_more_method() noexcept(false) {
			// this method may throw an exception
		}

		void strange_method() noexcept(sizeof(int) == 4) {
			// this method should not throw an exception if int has a 4 bytes
		}

		void other_method() noexcept(noexcept(function)) {
			// this method should not throw an exception is the function marked as noexcept only
			function();
		}
	};

	struct Base {
		virtual void method() = 0;
		virtual void other_method() noexcept = 0;
	};

	struct Derived : public Base {
		void method() override {} // Ok
		// void method() noexcept override {} // Ok

		void other_method() noexcept override {} // Ok
		// void other_method() override {} // Error
	};


} // namespace no_except

int main() {

	std::vector<Tracer> tracers;
	for(int i = 0; i < 10; ++i) {
		std::cout << "*** append [" << i << "] element:" << std::endl;
		tracers.emplace_back(Tracer{std::to_string(i)});
	}

	return 0;
}
