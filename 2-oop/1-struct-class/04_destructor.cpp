#include <iostream>
#include <string>
#include <cstring>

namespace motivation
{
    // Структра с деструктором по умолчанию.
    class String {
      public:
        String() = default;
        String(const char* cString)
        {
            if (cString != nullptr) {
                const size_t lengthWithNullTerminator = std::strlen(cString) + 1;
                data = new char[lengthWithNullTerminator]; // проблема?
                std::copy(cString, cString + lengthWithNullTerminator, data);
            }
        }
        std::string toStdString() const
        {
            return data ? data : "";
        }
        // ~String() {}
        ~String() = default;

        char* data = nullptr;
    };

    void example()
    {
        String hello("Hello");

        String world("world");
        std::cout << hello.toStdString() << " " << world.toStdString() << '\n';
        // Проблема! Выделили память с помощью new, но не освободили её
    }
} // namespace motivation

// Улучшение 1. Добавим деструктор
namespace first_attempt
{
    class String {
      public:
        String() = default;

        String(const char* cString)
        {
            if (cString) {
                const size_t lengthWithNullTerminator = std::strlen(cString) + 1; // + 1 для '\0'
                data = new char[lengthWithNullTerminator];
                std::copy(cString, cString + lengthWithNullTerminator, data);
            }
        }

        ~String()
        {
            // Выделяли память под массив, поэтому используем []
            delete[] data;
        }

        std::string toStdString() const
        {
            return data ? data : "";
        }

        char* data = nullptr;
    };

    void example()
    {
        String a = "Hello";
        std::cout << a.toStdString() << '\n';
        // String b = a; // новая проблема?
        // std::cout << a.toStdString() << " " << b.toStdString() << '\n';
    }
} // namespace first_attempt

// Улучшение 2. Добавим конструктор копирования
namespace second_attempt
{
    class String {
      public:
        String() = default;

        String(const char* cString)
        {
            initFrom(cString);
        }

        ~String()
        {
            delete[] data;
        }

        String(const String& other)
        {
            initFrom(other.data);
        }

        std::string toStdString() const
        {
            return data ? data : "";
        }

        void initFrom(const char* cString);

        char* data = nullptr;
    };

    // Вынесли повторяющиеся операции в отдельную функцию
    void String::initFrom(const char* cString)
    {
        if (cString) {
            const size_t lengthWithNullTerminator = std::strlen(cString) + 1;
            data = new char[lengthWithNullTerminator];
            std::copy(cString, cString + lengthWithNullTerminator, data);
        }
    }

    void example()
    {
        String a = "Hello";
        String b = a;
        std::cout << a.toStdString() << " " << b.toStdString() << '\n';

        String world = "world";
        // b = world; // опять проблема?
        std::cout << a.toStdString() << " " << b.toStdString() << '\n';
        // Опять проблема: повторное освобождение памяти
    }
} // namespace second_attempt

// Окончательное решение
// Использован принцип инкапсуляции и новые ключевые слова public и private (см. слайд)
// Почти идеальное, потому как на текущем этапе мы не знакомы с семантикой перемещения
namespace solution
{
    class String {
      public:
        String() = default;

        String(const char* cString)
        {
            initFrom(cString);
        }

        ~String()
        {
            delete[] data;
        }

        String(const String& other)
        {
            initFrom(other.data);
        }

        String& operator=(const String& other)
        {
            if (this == &other) {
              return *this; // исключаем проблему с самоприсваиванием
            }
            delete[] data;
            initFrom(other.data);
            return *this;
        }

        std::string toStdString() const
        {
            return data ? data : "";
        }

      private: // Новое ключевое слово
        void initFrom(const char* cString);
        char* data = nullptr;
    };

    void String::initFrom(const char* cString)
    {
        if (cString) {
            const size_t lengthWithNullTerminator = std::strlen(cString) + 1;
            data = new char[lengthWithNullTerminator];
            std::copy(cString, cString + lengthWithNullTerminator, data);
        }
    }

    void example()
    {
        String a = "Hello";
        // Проверим проблему самоприсваивания: уберем проверку на самоприсваивание
        a = a;
        String b;
        b = a;
        std::cout << a.toStdString() << " " << b.toStdString() << '\n';
    }
} // namespace solution

#include "example_runner.hpp"

int main()
{
    auto list = {
        std::make_pair("motivation", motivation::example),
        std::make_pair("first_attempt", first_attempt::example),
        std::make_pair("second_attempt", second_attempt::example),
        std::make_pair("solution", solution::example)
    };
    run(list);
}
