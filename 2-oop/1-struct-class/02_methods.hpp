#pragma once
#include <string>

namespace motivation
{
    // Предварительное объявление сообщает компилятору о существовании класса
    //  до его фактического определения.
    // Повод: ослабить зависимости между файлами, сократить время компиляции
    class Point;

    // Предварительного объявления класса достаточно для объявления функции
    std::string toString(const Point& point);

    // Объявление класса
    class Point {
      public:
        int x;
        int y;
    };
} // namespace motivation

namespace methods
{
    class Point {
      public:
        int x;
        int y;

        // Объявление метода
        // std::string toString();
        // Метод можно сделать константным,
        //  в этом случае метод не сможет менять поля класса
        std::string toString() const;
    } point1;
} // namespace methods
