#include <iostream>

//static storage duration = duration of program of program
int global_val;

int foo() {
    static int k = 2; //static storage duration
    return ++k;
}

int main() {
    int local_val = 42; //automatic storage duration
    std::cout << local_val << std::endl;

    std::cout << foo() << std::endl;
    std::cout << foo() << std::endl;

    int* heap_val = new int{10}; //dynamic storage duration

    // ...

    delete heap_val;

    return 0;
}
