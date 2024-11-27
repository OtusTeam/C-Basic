#include <future>
#include <iostream>
#include <memory>
#include <thread>

namespace enable_shared_from_this {

	// CRTP
	struct SuperClass : std::enable_shared_from_this<SuperClass> {
		SuperClass() = default;
		~SuperClass() {
			m_future.get();
			std::cout << "destructor" << std::endl;
		}

		void run() {
			std::cout << "run" << std::endl;
			m_future = std::async(
				std::launch::async,
				&SuperClass::do_step_one,
				this,
				shared_from_this() // shared_ptr
			);
		} // return
	private:
		void do_step_one(std::shared_ptr<SuperClass> ptr) {
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			std::cout << "Step one" << std::endl;
			m_future = std::async(
				std::launch::async,
				&SuperClass::do_step_two,
				this,
				shared_from_this()
			);
		}

		void do_step_two(std::shared_ptr<SuperClass> ptr) {
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			std::cout << "Step two" << std::endl;
			m_future = std::async(
				std::launch::async,
				&SuperClass::do_step_three,
				this,
				shared_from_this()
			);
		}

		void do_step_three(std::shared_ptr<SuperClass> ptr) {
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			std::cout << "Step three" << std::endl;
		} // ~SuperClass

		std::future<void> m_future;
	};

	void example() {

		std::cout << "start of the example" << std::endl;

		// Work here
		{
			std::shared_ptr<SuperClass> ptr = std::make_shared<SuperClass>();
			ptr->run();
		}

		std::cout << "end of the example" << std::endl;

	}

} // enable_shared_from_this

struct Struct {
	std::shared_ptr<Struct> get_shared() {
		return std::shared_ptr<Struct>{ this };
	}
};

template<typename T>
struct shared_ptr {

	shared_ptr(const shared_ptr&rhs) {
		m_impl = rhs.m_impl;
		m_impl->counter++;
	}

	~shared_ptr() {
		m_impl->counter--;
		if (m_impl->counter == 0) {
			delete m_impl->m_data;
			delete m_impl;
		}
	}
private:
	struct impl {
		T * m_data;
		std::atomic<int> counter;
	};
	impl *m_impl;
};

int main() {

	enable_shared_from_this::example();
	
	std::this_thread::sleep_for(std::chrono::seconds(10));
	
	return 0;
}