#include <iostream>
#include <string>

// https://en.cppreference.com/w/cpp/language/friend
namespace friends
{

class Person;

class Laptop {
  public:
    Laptop(const std::string& model) :
        model_{model}
    {}

  // Добавим дружественный класс
  private:
    friend /*class*/ Person;

  private:
      std::string model_;
};

class Person {
  public:
    Person(const std::string& name, const std::string& surname, int age):
        name_{name}, surname_{surname}, age_{age}
    {}

    void getLaptop(const Laptop& laptop) const
    {
        std::cout << name_ << " took laptop model " << laptop.model_ << '\n';
    }

    // Добавим дружественную функцию
   private:
      friend std::ostream &operator<<(std::ostream &os, const Person &person);

  private:
    std::string name_;
    std::string surname_;
    int age_{};
};

// Перегрузка оператора вывода
std::ostream &operator<<(std::ostream &os, const Person &person)
{
    os << person.name_ << " " << person.surname_ << " " << person.age_;
    return os;
}

void motivation()
{
    Person person = {"Ivan", "Ivanov", 23};
    std::cout << person << '\n'; // Проблема вывода пользовательского типа
}

void get_laptop()
{
    Person iIvanov("Ivan", "Ivanov", 23);

    Laptop dell("Dell");
    iIvanov.getLaptop(dell);
}
}

int main()
{
    friends::motivation();

    friends::get_laptop();
}