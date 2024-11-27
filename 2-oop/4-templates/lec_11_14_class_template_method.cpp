#include <iostream>
#include <string>

class MyClass 
{
public:
	MyClass() {}
	MyClass(int v) : value_{v} {}

	template <typename T>
	T as() const {return static_cast<T>(value_);}

private:
	int value_;
};

template <>
std::string MyClass::as<std::string>() const 
{
	return std::to_string(value_);
}

int main() 
{
	MyClass i_class{42};
    // Say metaprogramming
	std::cout << i_class.as<char>() << std::endl;
	std::cout << i_class.as<int>() << std::endl;
	std::cout << i_class.as<float>() << std::endl;
	std::cout << i_class.as<std::string>() << std::endl;
}