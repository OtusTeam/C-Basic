#include <iostream>

template <typename T>
class MyClass {
public:
    MyClass() {}

    MyClass(T v) :value_{v} {}

    T getValue() const { return value_; }

private:
    T value_;
};

template <>
int MyClass<int>::getValue() const {
    std::cout << "Hello from specialized method!" << std::endl;
    return value_;
}

int main() {
    MyClass i_class{42};
    MyClass f_class{3.14f};

    std::cout << i_class.getValue() << std::endl;
    std::cout << f_class.getValue() << std::endl;
}
