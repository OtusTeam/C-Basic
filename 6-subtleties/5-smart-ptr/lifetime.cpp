#include <iostream>

//static storage duration = duration of program of program
int global_val;

//thread storage duration
thread_local int thread_local_val;

int foo() {
    static int k = 0; //static storage duration
    return ++k;
}

int main() {
    int local_val = 42; //automatic storage duration

    std::cout << foo() << std::endl;

    auto heap_val = new int{10}; //dynamic storage duration
    
    // ...
    
    delete heap_val;

    return 0;
}
