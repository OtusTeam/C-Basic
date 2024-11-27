// Dynamic memory usage example
#include <array>
#include <iostream>
#include <string.h>

#include "01_strategy.hpp"

void heap_buffer_overflow()
{
    int* arr = new int[10];
    arr[3] = 5;

    arr[10] = 4;

    delete[] arr;
}

void stack_buffer_overflow()
{
    char str[] = "Hello, world!";
    char dst[13];
    strcpy(dst, str);
}

int main() {
    heap_buffer_overflow();
    //stack_buffer_overflow();
}
