#include <iostream>
#include <list>
#include <mutex>
#include <vector>


// Mixin class
namespace motivation {

	struct Vector {
		// implementation here
	};

	struct ThreadSafeVectorWithMutex {
		// implementation here
	};

	struct TheadSafeVectorWithSpinlock {
		// implementation here
	};

	struct VectorWhichPrintsElementsWithComma {
		//
	};

	// 1. ThreadSafe
	// 2. Printing style
	// 3. Storage 

	// too many implementations...

} // namespace motivation

namespace solution {

	template <typename MutexType>
	struct MutexLock {
		void lock() {
			m_mutex.lock();
		}

		void unlock() {
			m_mutex.unlock();
		}
	private:
		MutexType m_mutex;
	};

	struct NoLock {
		void lock() {
			// do nothing
		}
		void unlock() {
			// do nothing
		}
	};

	template <typename T, const char Sep>
	struct SepPrinter {
		void print(const T &value, size_t index) {
			if (index)
				std::cout << Sep;
			std::cout << value;
		}
	};

	// Strategy
	template <typename T, typename Mutex = NoLock, typename Printer = SepPrinter<T, ' '>>
	struct List : Mutex, Printer {
		List(std::initializer_list<T> args)
			: m_vector{args} {}

		void push_back(const T &value) {
			std::lock_guard<Type> lck{*this}; // call Mutex::lock here
			m_vector.push_back(value);
		}

		T operator[](size_t i) {
			std::lock_guard<Type> lck{*this}; // call Mutex::lock here
			return m_vector[i];
		}

		void print_all() {
			std::lock_guard<Type> lck{*this}; // call Mutex::lock here
			for (size_t i = 0; i < m_vector.size(); ++i) {
				Printer::print(m_vector[i], i);
			}
			std::cout << std::endl;
		}

	private:
		using Type = List<T, Mutex, Printer>;
		std::vector<T> m_vector;
	};

	void example() {
		std::cout << "solution::example()" << std::endl;

		List<int> list{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		list.print_all();

		List<int, solution::NoLock, SepPrinter<int, '.'>> list_with_dots{
			0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		list_with_dots.print_all();

		List<int, solution::MutexLock<std::mutex>, SepPrinter<int, '-'>> list_with_mutex {
			0, 1, 2, 3, 4, 5, 6, 7, 8, 9
		};
		list_with_mutex.print_all();

		std::cout << std::endl
				  << std::endl;
	}

} // namespace solution

namespace crtp {

	template <class T>
	class NonCopyable {
	public:
		NonCopyable(const NonCopyable &) = delete;
		T &operator=(const T &) = delete;

	protected:
		NonCopyable() = default;
		~NonCopyable() = default; /// Protected non-virtual destructor
	};

	// CRTP
	struct SomeStruct : private NonCopyable<SomeStruct> {

	};

	struct SomeStruct2 : private NonCopyable<SomeStruct> {
	};

}

int main() {

	solution::example();

	return 0;
}