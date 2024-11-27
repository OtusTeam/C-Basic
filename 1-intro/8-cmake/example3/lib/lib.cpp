#include "lib.h"
#include <private_lib.h>
#include <iostream>

#include <config.h>

namespace lib
{

int makeSomeSuperJob() {
  std::cout << "Hello from lib!\n";
  std::cout << MY_VAR;
  return 42;
}

int getVersion() { return getProjectVersionPatch(); }

}  // namespace lib
