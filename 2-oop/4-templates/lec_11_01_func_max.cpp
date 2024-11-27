#include <iostream>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int value1 = 42;
    int value2 = 123;

    std::cout << "max(42, 123) = " << max(value1, value2) << std::endl;

    std::cout << "max(1.5f, 1.9f) = " << max(1.5f, 1.9f) << std::endl;
}