#include <cstddef>
#include <iostream>

// Compile-time factorial
// non-type template arguments
// specialization
template <std::size_t n>
std::size_t factorial() {
    return n * factorial<n - 1>();
}

template <>
std::size_t factorial<0>() {
    return 1;
}

// compile-time: https://godbolt.org/z/xx37rY8oj

int main() {
    // 5 * 4 * 3 * 2 * 1
    std::cout << "factorial " << factorial<5>() << std::endl;
}
