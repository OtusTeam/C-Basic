#include <iostream>

int max(int a, int b) {
    return (a > b) ? a : b;
}

float max(float a, float b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << "max(42, 123) = " << max(42, 123)
              << "max(1.5f, 1.9f) = " << max(1.5f, 1.9f) << std::endl;
}