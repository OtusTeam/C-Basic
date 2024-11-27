// Dynamic memory usage example
#include <array>
#include <iostream>
#include <thread>
#include <chrono>

#include "01_strategy.hpp"

int main() {
    int* arr = new int[10];
    arr[3] = 5;

    delete[] arr;
    /*...*/

    arr[5] = 10;
}
