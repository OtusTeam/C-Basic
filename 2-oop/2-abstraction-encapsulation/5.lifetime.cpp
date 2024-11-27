#include <iostream>
#include <string>

class Demo {
  public:
    Demo(const std::string &name = "") : name{name}
    {
        log("Constructor");
    }

    ~Demo()
    {
        log("Destructor");
    }

    Demo(const Demo &other)
    {
      name = other.name + "-copy";
      log("Copy constructor");
    }

    Demo &operator=(const Demo &other)
    {
      name = other.name + "-copy";
      log("Copy assignment");
      return *this;
    }

  private:
    void log(const char *stage)
    {
      std::cout << name << " - " << stage << '\n';
    }

  private:
    std::string name;
};

void base()
{
   Demo demo;
}

void copyConstructor()
{
    Demo a("a");
    Demo other = a;
}

void copyAssignment()
{
    Demo a("a");
    Demo other("b");
    other = a;
}

Demo foo()
{
    Demo demo;
    return demo;
}

void returnFrom()
{
    foo();
}

void scope()
{
    {
        Demo a("a");
        Demo other("b");
        other = a;
    }
    std::cout << "Bye" << '\n';
}

void dynamic()
{
    Demo *pointer = new Demo();
    delete pointer;
}

int main()
{
  base();
  std::cout << '\n';

  copyConstructor();
  std::cout << '\n';

  copyAssignment();
  std::cout << '\n';

  scope();
  std::cout << '\n';

  dynamic();
  std::cout << '\n';

  returnFrom();  // play with -fno-elide-constructors in CMakeLists.txt
}