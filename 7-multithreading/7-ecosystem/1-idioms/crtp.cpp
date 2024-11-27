#include <iostream>

namespace motivation {

	struct Struct1 {
		explicit Struct1(int value)
			: m_value{value} {}

		bool operator<(const Struct1 &rhs) const {
			return m_value < rhs.m_value;
		}

		bool operator>(const Struct1 &rhs) const {
			return rhs.m_value < m_value;
		}

		bool operator==(const Struct1 &rhs) const {
			return !(*this < rhs) && !(rhs < *this);
		}

		bool operator!=(const Struct1 &rhs) const {
			return !(*this == rhs);
		}

	private:
		int m_value;
	};

	struct Struct2 {
		// ...
	};

	struct Struct3 {
		// ...
	};

	struct Struct4 {
		// ...
	};

	// ....

	void example() {
		std::cout << "motivation::example()" << std::endl;
		Struct1 s1{42};
		Struct1 s2{56};

		std::cout << "s1 < s2: " << (s1 < s2) << std::endl;
		std::cout << "s1 == s2: " << (s1 == s2) << std::endl;
		std::cout << "s1 != s2: " << (s1 != s2) << std::endl;
		std::cout << "s1 > s2: " << (s1 > s2) << std::endl;

		std::cout << std::endl
				  << std::endl;
	}

} // motivation

namespace crtp {

	template <class T>
	struct comparable {};

	struct Struct1 : public comparable<Struct1> {
		explicit Struct1(int value)
			: m_value{value} {}

		bool operator<(const Struct1 &rhs) const {
			return m_value < rhs.m_value;
		}
	private:
		int m_value;
	};

	template <class T>
	bool operator<(const comparable<T> &lhs, const comparable<T> &rhs) {
		return (static_cast<const T &>(lhs) < static_cast<const T &>(rhs));
	}
	template <class T>
	bool operator>(const comparable<T> &lhs, const comparable<T> &rhs) {
		return (static_cast<const T &>(rhs) < static_cast<const T &>(lhs));
	}
	template <class T>
	bool operator==(const comparable<T> &lhs, const comparable<T> &rhs) {
		return !(static_cast<const T &>(lhs) < static_cast<const T &>(rhs))
			&& !(static_cast<const T &>(rhs) < static_cast<const T &>(lhs));
	}
	template <class T>
	bool operator!=(const comparable<T> &lhs, const comparable<T> &rhs) {
		return !(lhs == rhs);
	}

	void example() {
		std::cout << "crtp::example()" << std::endl;
		Struct1 s1{42};
		Struct1 s2{56};

		std::cout << "s1 < s2: " << (s1 < s2) << std::endl;
		std::cout << "s1 == s2: " << (s1 == s2) << std::endl;
		std::cout << "s1 != s2: " << (s1 != s2) << std::endl;
		std::cout << "s1 > s2: " << (s1 > s2) << std::endl;

		std::cout << std::endl
				  << std::endl;
	}

	struct Struct2 : public comparable<Struct2> {};
	struct Struct3 : public comparable<Struct3> {};
	struct Struct3 : public comparable<Struct3> {};
}

int main() {

	motivation::example();
	crtp::example();

	return 0;
}