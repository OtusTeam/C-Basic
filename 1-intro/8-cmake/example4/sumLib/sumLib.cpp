#include "sumLib.h"

#include <iostream>

#include "config.h"

namespace sumLib {

int sum(int a, int b)
{
  std::cout << "Hello from sumLib!" << std::endl;
  return a + b;
}

int getVersion() { return (PROJECT_VERSION); }

}  // namespace sumLib