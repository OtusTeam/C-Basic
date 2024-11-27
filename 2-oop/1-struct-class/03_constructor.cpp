#include <iostream>
#include <string>

class Point {
  public:
    int x;
    int y;

    Point(int x, int y)
    {
        // this -  указатель на объект, для которого был вызван метод
        this->x = x;
        (*this).y = y;
        // Проблема нейминга: m_x, x_
    }

    std::string toString() const
    {
        return "{" + std::to_string(x) + ", " + std::to_string(y) + "}";
    }
};

namespace two_args_constructor
{
    void example()
    {
        // Различные варианты создания объекта https://habr.com/ru/articles/438492/
        // Cheat: если непонятно, как это работает, можно воспользоваться дебагом

        // Прямая инициализация: вызов конструктора Point(int x, int y)
        Point point(0, 0);
        std::cout << point.toString() << '\n';

        // Инициализация копированием: создание временного  объекта через вызов конструктора Point(int x, int y),
        //  присвоение результата объекту point1
        Point point1 = Point{1, 11};
        std::cout << point1.toString() << '\n';

        // Инициализация списком (начиная с С++11)
        Point point2 = {2, 22};
        std::cout << point2.toString() << '\n';

        // Почему не соберется? Ответ в namespace default_constructor
        // Point p;
    }
} // namespace two_args_constructor

namespace default_constructor
{
    class Point {
      public:
        int x = 0;
        int y = 0;
        // Конструктор по умолчанию автоматически генерится компилятором, если нет пользовательских конструкторов
        // Point() {}
        // Начиная с С++11
        Point() = default;
        // Суперспособность конструктора: member initializer lists
        Point(int x, int y): x(x), y(y) {}

        std::string toString() const
        {
            return "{" + std::to_string(x) + ", " + std::to_string(y) + "}";
        }
    };

    void example()
    {
        Point p; // вызовется конструктор по умолчанию
        std::cout
            << p.toString() << "\t"
            <<  Point(3, 5).toString() << '\n';
        // Почему не соберется? Ответ https://www.sandordargo.com/blog/2021/12/22/most-vexing-parse
        // Point p1();
        // p1.toString();
    }
} // namespace default_constructor

#include "example_runner.hpp"

int main()
{
    auto list = {
        std::make_pair("two_args_constructor", two_args_constructor::example),
        std::make_pair("default_constructor", default_constructor::example)
    };
    run(list);
}