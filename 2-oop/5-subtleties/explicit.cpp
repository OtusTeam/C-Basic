#include <algorithm>
#include <iostream>

namespace motivation {

class Distance {
public:
  Distance(const int value) : m_value{value} {
    std::cout << "Distance(" << value << ")" << std::endl;
  }
  int value() const { return m_value; }

private:
  const int m_value;
};

class Weight {
public:
  Weight(const int value) : m_value{value} {
    std::cout << "Weight(" << value << ")" << std::endl;
  }
  int value() const { return m_value; }

private:
  const int m_value;
};

int calculate_delivery_price(const Distance &distance, const Weight &weight) {
  const int minDistance = 10;

  return std::max(distance.value(), minDistance) * weight.value();
}

void example() {
  const int distance = 10;
  const int weight = 2;
  std::cout << calculate_delivery_price(weight, distance) << std::endl;
}

} // namespace motivation

////////////////////////////////////////////////////////////////////////////////

namespace solution {

class Distance {
public:
  explicit Distance(const int value) : m_value{value} {
    std::cout << "Distance(" << value << ")" << std::endl;
  }
  int value() const { return m_value; }

private:
  const int m_value;
};

class Weight {
public:
  explicit Weight(const int value) : m_value{value} {
    std::cout << "Weight(" << value << ")" << std::endl;
  }
  int value() const { return m_value; }

private:
  const int m_value;
};

int calculate_delivery_price(const Distance &distance, const Weight &weight) {
  const int minDistance = 10;

  return std::max(distance.value(), minDistance) * weight.value();
}

void example() {
  const int distance = 10;
  const int weight = 2;

  // Now We can't make such a silly a mistake!
  // We should pass Distance and Weight object explicit
  std::cout << calculate_delivery_price(Distance{distance}, Weight{weight})
            << std::endl;
}

} // namespace solution


int main() {

  motivation::example();
  solution::example();

  return 0;
}

/*

Recommended to use keyword "explicit" each time when:
 - C-tor has only one argument;
 - C-tor has only one REQUIRED argument (it doesn't have a default value).

A class could have explicit and implicit constructors at the same time.

 */