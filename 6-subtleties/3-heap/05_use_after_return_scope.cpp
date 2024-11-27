// Dynamic memory usage example
#include <array>
#include <iostream>
#include <thread>
#include <chrono>

#include "01_strategy.hpp"

int *p = 0;
void UseAfterScope()
{
    {
        int x = 0;
        p = &x;
    }
    *p = 5;
}

int *ptr;
void FunctionThatEscapesLocalObject() {
  int local[100];
  ptr = &local[0];
}

//ASAN_OPTIONS=detect_stack_use_after_return=1 ./05_use_after_return_scope 

int main(int argc, char** argv) {
    UseAfterScope();
    //FunctionThatEscapesLocalObject();
    //return ptr[argc];
    return 0;
}
