#include <iostream>
#include <string>

namespace motivation
{
    // Обратите внимание, что значения передаются по ссылке
    void get_user_info(std::string& name, std::string& surname, int& age)
    {
        std::cout << "Hello!" << std::endl;

        // Что использовать std::endl или '\n'?
        // https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#slio50-avoid-endl
        std::cout << "Enter your name:\n";
        std::cin >> name;

        std::cout << "Enter your surname:" << '\n';
        std::cin >> surname;

        std::cout << "Enter your age:" << '\n';
        std::cin >> age;
    }

    void example()
    {
        std::string name;
        std::string surname;
        int age{};

        get_user_info(name, surname, age);

        if (age < 16) {
            std::cout << "Access denied!" << '\n';
        } else if (age < 30) {
            std::cout << "Hello, " << name << '\n';
        } else {
            std::cout << "Hello, " << name << " " << surname << '\n';
        }
    }

} // namespace motivation


namespace classes
{

    // Класс объединяет данные, относящиеся к одной сущности, реализуя принцип абстракции
    // Класс - это пользовательский тип
    class Person {
      public:
        std::string name;
        std::string surname = "Ivanov";
        int age;
    };

    // Метод возвращает объект класса
    Person get_user_info()
    {
        // Объект типа Person
        // Объект - это конкретный экземпляр класса
        Person person;

        std::cout << "Hello!" << '\n';

        std::cout << "Enter your name:" << '\n';
        // Обращаемся к полю класса через оператор .
        std::cin >> person.name;

        std::cout << "Enter your surname:" << '\n';
        std::cin >> person.surname;

        std::cout << "Enter your age:" << '\n';
        std::cin >> person.age;

        return person;
    }

    void example()
    {
        const Person person = get_user_info();

        // person - константный объект: можем читать, не можем изменять
        if (person.age < 16) {
            std::cout << "Access denied!" << '\n';
        } else if (person.age < 30) {
            std::cout << "Hello, " << person.name << '\n';
        } else {
            std::cout << "Hello, " << person.name << " " << person.surname << '\n';
        }
    }
} // namespace classes

namespace object_as_field
{
    class Biometrics {
      public:
        int one;
        int another;
        //... другие параметры
    };

    class Person {
      public:
        std::string name;
        std::string surname = "Ivanov";
        int age;
        Biometrics biometrics;
    };

    void example() {
        Person p;
        p.biometrics.another;
    }
} // namespace object_as_field

#include "example_runner.hpp"

int main()
{
    auto list = {
        std::make_pair("motivation", motivation::example),
        std::make_pair("structures", classes::example),
        std::make_pair("object_as_field", object_as_field::example)
    };
    run(list);
}
