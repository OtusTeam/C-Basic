#include <iostream>

template <typename T>
class MyClass {
public:
    MyClass() {}

    MyClass(T v) :value_{v} {}

    virtual ~MyClass() {};

    virtual T getValue() const { return value_; }

private:
    T value_;
};

// 1. 
class A: public MyClass<std::string> {
public:
    A() :MyClass() {}

    A(const std::string& s) :MyClass(s) {}

    ~A() override {};
};

// 2.
template <typename T>
class B: public MyClass<T> {
public:
    B() :MyClass<T>() {}

    B(T b) :MyClass<T>(b) {}

    ~B() override {}
};


int main() {
    MyClass<int> i_class{42};
    MyClass f_class{3.14f};

    std::cout << i_class.getValue() << std::endl;
    std::cout << f_class.getValue() << std::endl;

    A a1("Super String");
    std::cout << a1.getValue() << std::endl;

    B<double> b(999.88);
    std::cout << b.getValue() << std::endl;
}
