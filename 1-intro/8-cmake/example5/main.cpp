#include "config.h"
#include "sumLib.h"

#include <iostream>

int main()
{
    std::cout << "Hello from main!\n";
    sumLib::sum(1, 3);
    // std::cout << "Lib verion:" << sumLib::getVersion() << '\n';

    std::cout << "Main version: " << (PROJECT_VERSION) << '\n';

    return 0;
}