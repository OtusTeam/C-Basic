#include <iostream>

int main()
{

    std::cout << "Hello from the CMake example!\n";

    auto f = []() {
        std::cout << "I am lambda!\n";
    };

    f();

    return 0;
}
