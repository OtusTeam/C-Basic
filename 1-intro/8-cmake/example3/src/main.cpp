#include "config.h"
#include <lib.h>
#include <dynamic_lib.h>

#include <iostream>

int main()
{
    std::cout << "Hello from main!\n";
    lib::makeSomeSuperJob();
    std::cout << "Lib verion:" << lib::getVersion() << '\n';
    dynamic_lib::makeSomeSuperJob();

    std::cout << "Main version: " << (PROJECT_VERSION) << '\n';

    return 0;
}
