
#pragma once

#include <iostream>
#include <string>

// Helper class just to trace all actions with an object - ctor, copy and so on.
class Tracer {
public:
	Tracer() {
		std::cout << "  Default ctor #" << m_id << std::endl;
	}

	explicit Tracer(std::string name) : m_name(std::move(name)) {
		std::cout << "  Ctor \"" << m_name << "\" #" << m_id << std::endl;
	}

	Tracer(const Tracer &rhs) : m_name(rhs.m_name) {
		std::cout << "  Copy ctor from \"" << rhs.m_name << "\" #" << m_id << std::endl;
	}

	Tracer(Tracer &&rhs) /*noexcept*/  : m_name(std::move(rhs.m_name)) {
		std::cout << "  Move ctor from \"" << m_name << "\" #" << m_id << std::endl;
	}

	~Tracer() {
		std::cout << "  Dtor \"" << m_name << "\" #" << m_id << std::endl;
	}

	Tracer &operator=(const Tracer &rhs) {
		std::cout
			<< "  Copy assign from \"" << rhs.m_name
			<< "\" to \"" << m_name << "\" #" << m_id
			<< std::endl;

		m_name = rhs.m_name;

		return *this;
	}

	Tracer &operator=(Tracer &&rhs) /*noexcept*/ {
		std::cout
			<< "  Move assign from \"" << rhs.m_name
			<< "\" to \"" << m_name << "\" #" << m_id
			<< std::endl;

		m_name = std::move(rhs.m_name);

		return *this;
	}

	void DoSomeAction() const {
		std::cout << "    Some action #" << m_id << std::endl;
	}

private:
	std::uint64_t m_id = m_nextId++;
	std::string m_name = "empty";

	static std::uint_least64_t m_nextId;
};

inline std::uint_least64_t Tracer::m_nextId = 1;
