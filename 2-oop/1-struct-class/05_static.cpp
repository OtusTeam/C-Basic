#include "05_static.h"
#include <iostream>

// Определяем статический член вне тела структуры.
// Определение статического члена не попадает под действие спецификаторов доступа.
int Counter::count = 0;

Counter::Counter()
{
  ++count;
}

Counter::~Counter()
{
  --count;
}

int Counter::getCount()
{
    // Не имеют *this
    // Не могут обращаться к нестатическим членам.
    return count;
}

void example()
{
  {
    // Статические члены структуры существуют, даже если объекты структуры не созданы.
    // Они создаютс при запуске программы и уничтожаются, когда программа
    //  завершает свое выполнение.

    // А вот обратиться к приватному статическому полю уже нельзя.
    // std::cout << Counter::count << '\n';
    std::cout << Counter::getCount() << '\n';

    Counter a;
    std::cout << Counter::getCount() << '\n';

    Counter b;
    std::cout << Counter::getCount() << '\n';
  }

  std::cout << Counter::getCount() << '\n';
}

#include "example_runner.hpp"

int main()
{
  auto list = {
      std::make_pair("example", example)
  };
  run(list);
}
