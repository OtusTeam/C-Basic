#include <iostream>

// different types
template <typename T, typename U>
void foo(T t, U u) {
    std::cout << "t = " << t << std::endl;
    std::cout << "u = " << u << std::endl;
}

// only full spec
template <>
void foo<int, float>(int t, float u) {
    std::cout << "Hello from specialized function!" << std::endl;
    std::cout << "t = " << t << std::endl;
    std::cout << "u = " << u << std::endl;
}

// default
template <typename T = int, std::size_t n = 4>
void bar(T t) {
    std::cout << "Non-type template arguments:" << std::endl;
    std::cout << "t = " << t << std::endl;
    std::cout << "n = " << n << std::endl;
}


int main() {
    // 1
    foo(123, "Hello!");
    foo(13, 42.1f);

    // 2
    bar(234);
    bar<float, 12>(3.5f);
}
