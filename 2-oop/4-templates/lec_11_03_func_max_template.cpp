#include <iostream>

// typename == class
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

/*template <typename T>
T max(T a, T b)
{
    T result = a;
    if (result < b) {
        result = b;
    }
    return result;
}*/

// instantiation for each type...

int main() {
    max<int>(1, 2); // explicit
    std::cout << "max(42, 123) = " << max(42, 123) << std::endl;
    std::cout << "max(42ll, 123ll) = " << max(42ll, 123ll) << std::endl;

    std::cout << "max(1.5f, 1.9f) = " << max(1.5f, 1.9f) << std::endl;
    std::cout << "max(1.5L, 1.9L) = " << max(1.5L, 1.9L) << std::endl;

    // std::cout << "max(Ann, Bob) = " << max("Ann", "Bob") << std::endl;
}