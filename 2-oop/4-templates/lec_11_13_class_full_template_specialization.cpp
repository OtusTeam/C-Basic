#include <iostream>

template <typename T>
class MyClass 
{
public:
	MyClass() {}
	MyClass(T v) : value_{v} {}
	T getValue() const { return value_; }
private:
	T value_;
};

// 2
template <>
class MyClass<double> {
public:
	MyClass(double v) : value2_{v} {}
	double takeValue() const {return value2_;}
private:
	double value2_;
};

int main() 
{
	MyClass i_class{42};
	MyClass f_class{3.14f};

	std::cout << i_class.getValue() << std::endl;
	std::cout << f_class.getValue() << std::endl;

	MyClass d_class{1.6};
	std::cout << d_class.takeValue() << std::endl;
}
