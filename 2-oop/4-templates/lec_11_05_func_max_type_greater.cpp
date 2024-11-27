#include <iostream>
// user type as templ. param

class IntType {
public:
    explicit IntType(int value) :value_(value) {}

    // Say: friend
    friend std::ostream& operator<<(std::ostream& os, const IntType& it);

    friend bool operator>(const IntType&, const IntType&);

private:
    int value_;
};

template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    IntType a(123);
    IntType b(45);

    std::cout << "IntType max : " << max(a, b) << std::endl;
    //std::cout << "IntType max : " << max<IntType>(a, 214) << std::endl;  // explicit
}

std::ostream& operator<<(std::ostream& os, const IntType& it) {
    return os << it.value_;
}

bool operator>(const IntType& x, const IntType& y) {
    return x.value_ > y.value_;
}