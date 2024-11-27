#include <iostream>
#include <string>

// Заглянем в инклюд
#include "02_methods.hpp"

namespace motivation
{

    std::string toString(const Point& point) {
        return "{" + std::to_string(point.x) + ", " + std::to_string(point.y) + "}";
    }

    void example() {
        Point point;
        point.x = 3;
        point.y = 5;

        std::cout << toString(point) << '\n'; // {3, 5}
    }
} // namespace motivation

namespace methods
{
    // Оператор :: (двойное двоеточие)
    // Определение метода структуры: имя_структуры::имя_метода
    std::string Point::toString() const {
        return "{" + std::to_string(x) + ", " + std::to_string(y) + "}";
    }

    void example() {
        std::cout << "*** methods::example ***" << '\n';

        Point point;
        point.x = 3;
        point.y = 5;

        std::cout << point.toString() << '\n';
    }
} // namespace methods

#include "example_runner.hpp"

int main()
{
    auto list = {
        std::make_pair("motivation", motivation::example),
        std::make_pair("methods", methods::example)
    };
    run(list);
}
