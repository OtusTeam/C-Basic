#include <iostream>

class Base
{
  public:
	Base()
	{
		// pure virtual function call
		doInitialize();
	}
	~Base() {}

	virtual void doSomething() = 0;
  private:
	void doInitialize()
	{
		doSomething();
	}
};

class Derived : public Base
{
  public:
	Derived() {}
	~Derived() {}

	void doSomething() override
	{
		std::cout << "Hello from Derived!" << std::endl;
	}
};

int main()
{
	Derived d;
}
