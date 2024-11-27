#include <cstring>
#include <iostream>
#include <string>

template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

template <>
const char* max<const char*>(const char* a, const char* b) {
    // First need to find length of the both strings
    const size_t a_length = std::strlen(a);
    const size_t b_length = std::strlen(b);

    // Now we should iterate all sybmols from the first and the second string
    const size_t min_length = (a_length < b_length) ? a_length : b_length;

    for (size_t i = 0; i < min_length; ++i) {
        if (a[i] > b[i]) {
            return a;
        } else if (a[i] < b[i]) {
            return b;
        }
    }

    // In case all symbols are equal it returns a string of bigger length
    return (a_length < b_length) ? b : a;

    /*const bool a_less = std::lexicographical_compare(a, a + a_length, b, b + b_length);
    return a_less ? b : a;*/
}

int main() {
    std::cout << "max(42, 123) = " << max(42, 123) << std::endl;

    std::cout << "string max(988, 99)";
    std::cout << ::max(std::to_string(988), std::to_string(99)) << std::endl;

    std::cout << R"(max("123", "234") = )" << max("123", "234") << std::endl;
    std::cout << R"(max("123", "23")  = )" << max("123", "23") << std::endl;
    std::cout << R"(max("123", "12")  = )" << max("123", "12") << std::endl;
}

