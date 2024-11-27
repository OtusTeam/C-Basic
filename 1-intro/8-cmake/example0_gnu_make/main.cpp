#include "answer.h"

#include <iostream>

int main() {
  std::cout << "Hello from the GNU Make example!\n"
            << R"(The answer is ")" << getAnswer() << R"("!)" << '\n';

  return 0;
}
