#include <iostream>
#include <string>

namespace streams
{

// Структура из предыдущего вебинара.
// Давайте вспомним: чем отличается структура от класса?
struct Person {
    std::string name;
    std::string surname;
    int age{};
};

void motivation()
{
    // Создаем базовый тип и выводим его в консоль.
    int i = 100;
    std::cout << i << '\n';

    // Создаем пользовательский тип и выводим его в консоль.
    Person person = {"Ivan", "Ivanov", 23};
    // std::cout << person << '\n'; // Проблема вывода пользовательского типа
    std::cout << person.name << " " << person.surname << " " << person.age << '\n';
}

// Решение проблемы вывода пользовательского типа
// Перегрузка оператора вывода
std::ostream &operator<<(std::ostream &os, const Person &person)
{
    os << person.name << " " << person.surname << " " << person.age;
    return os;
}

// Перегрузка оператора ввода
std::istream &operator>>(std::istream &is, Person &person)
{
    is >> person.name >> person.surname >> person.age;
    return is;
}

void use_streams()
{
    Person person;
    std::cin >> person;
    person.age += 10;
    std::cout << person << '\n';
}

}  // namespace streams

// Перегрузка арифметических операций
namespace math
{

// Вектор, выходящий из начала координат
struct Vec {
    int x{};
    int y{};
};

Vec operator+(const Vec &lhs, const Vec &rhs)
{
    return Vec{lhs.x + rhs.x, lhs.y + rhs.y};
}

std::ostream &operator<<(std::ostream &os, const Vec &v)
{
    os << "[" << v.x << ", " << v.y << "]";
    return os;
}

void sum()
{
    Vec a{3, 5};
    Vec b{2, 1};
    std::cout << "sum: " << a + b << '\n';
}

}  // namespace math

int main()
{
    streams::motivation();
    streams::use_streams();
    math::sum();
}
