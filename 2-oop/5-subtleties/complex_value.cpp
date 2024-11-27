#include <iostream>

////////////////////////////////////////////////////////////////////////////////

namespace motivation_manual {
class Complex {
public:
  Complex() : m_real{0}, m_im{0} {}
  Complex(const float real, const float im) : m_real{real}, m_im{im} {}

  float real() const { return m_real; }
  float im() const { return m_im; }

private:
  const float m_real;
  const float m_im;
};

void example() {
  const Complex c1{1, 2};
  const Complex c2{3, 4};

  // We can sum it manually, just field by field. Possible, but too complex,
  // especially if we have to sum many numbers.

  const Complex c_sum{c1.real() + c2.real(), c1.im() + c2.im()};
  std::cout << "c_sum = " << c_sum.real() << " + " << c_sum.im() << "i"
            << std::endl;
}
} // namespace motivation_manual

////////////////////////////////////////////////////////////////////////////////

namespace motivation_methods {
class Complex {
public:
  Complex() : m_real{0}, m_im{0} {}
  Complex(const float real, const float im) : m_real{real}, m_im{im} {}

  float real() const { return m_real; }
  float im() const { return m_im; }

  Complex sum(const Complex &rhs) const {
    return Complex{real() + rhs.real(), im() + rhs.im()};
  }

  Complex sub(const Complex &rhs) const {
    return Complex{real() - rhs.real(), im() - rhs.im()};
  }

private:
  const float m_real;
  const float m_im;
};

void example() {
  const Complex c1{1, 2};
  const Complex c2{3, 4};
  const Complex c3{5, 6};

  // We already added methods sub and sum and now can use it.
  // Now it became more understandable, but it still is a very complex syntax...

  const Complex c_sub = c3.sub(c1.sum(c2)); // :(
  std::cout << "c_sub = " << c_sub.real() << " + " << c_sub.im() << "i"
            << std::endl;
}
} // namespace motivation_methods

////////////////////////////////////////////////////////////////////////////////

namespace operators {
class Complex {
public:
  Complex() : m_real{0}, m_im{0} {}
  // Complex(float real) : m_real{real}, m_im{0} {}
  Complex(float real, float im) : m_real{real}, m_im{im} {}

  float real() const { return m_real; }
  float im() const { return m_im; }

  Complex &operator+=(Complex rhs) {
    m_real += rhs.real();
    m_im += rhs.im();
    return *this;
  }

private:
  float m_real;
  float m_im;
};

/*
        Where the operator has to be placed:

                1. changes lhs - method is better (ex.: +=, just because it have
   to have access to privates)

                2. =, [], () - always method (by Standard)

                3. all other - functions
*/

Complex operator+(Complex c1, Complex c2) {
  return Complex{c1.real() + c2.real(), c1.im() + c2.im()};
}

// Complex operator+(Complex c, float f) {
// 	return Complex{c.real() + f, c.im()};
// }

Complex operator-(Complex c1, Complex c2) {
  return Complex{c1.real() - c2.real(), c1.im() - c2.im()};
}

std::ostream &operator<<(std::ostream &os, Complex complex) {
  os << complex.real() << " + " << complex.im() << "i";
  return os;
}

void example() {
  const Complex c1{1, 2};
  const Complex c2{3, 4};
  const Complex c3{5, 6};

  Complex c_sub = c3 - (c1 + c2);  // Nice!
  std::cout << c_sub << std::endl; // Nice also!
  c_sub += c1;                     // Nice again!
}

} // namespace operators

/**

Operators to overload:
                + - * / % ^ & | ~ ! = < > += -= *= /= %= ^= &= |=
                << >> >>= <<= == != <= >=
                <=> (since C++20)
                && || ++ -- , ->* -> ( ) [ ]

Restrictions:

                Operators cannot be overloaded:
                    :: (scope resolution),
                     . (member access),
                    .* (member access through pointer to member),
                    ?: (ternary conditional)

                New operators such as **, <>, or &| cannot be created.

                It is not possible to change the precedence, grouping, or number
of operands of operators.

Please, try to follow semantics when overloading the operator.
Try to overload the operator only if it's understandable and required.
*/

int main() {

  motivation_manual::example();
  motivation_methods::example();
  operators::example();

  return 0;
}