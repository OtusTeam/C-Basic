#include <iostream>
#include <string>
#include <vector>

namespace motivation {

	// Abstraction for all cat-like animals: cats, tigers, lions, ets.
	class Felidae {
	public:
		Felidae(const std::string &name)
			: m_name{name} {
			std::cout << "Felidae constructor" << std::endl;
		}

		~Felidae() {
			std::cout << "Felidae destructor" << std::endl;
		}

		void speak() const {
			// Hm...
			// It is not a some concrete animal - it is an abstraction.
			// How does the abstraction speak? :)
			std::cout << "Felidae::speak()" << std::endl;
		}

		void call() const {
			// Ok - We can call ANY cat-like by name.
			std::cout << m_name << ", come here!" << std::endl;
		}

		void feed() {
			// Hm...
			// How many food is required?
			std::cout << "Felidae::feed()" << std::endl;
		}

		std::string get_name() const { return m_name; }

	private:
		std::string m_name;
	};

	// The concrete animal - cat
	class Cat : public Felidae {
	public:
		Cat(const std::string &name, const std::string &breed)
			: Felidae{name}, m_breed{breed} {

			Felidae::speak();
			std::cout << "Cat constructor" << std::endl;
		}

		~Cat() {
			std::cout << "Cat destructor" << std::endl;
		}

		void speak() const {
			// Easy! Cats say "meow".
			std::cout << "Meow, meow, meow!" << std::endl;
		}

		void call() const {
			// Ok - We can call cat by it's name.
			std::cout << get_name() << ", kitty, kitty, kitty, come here!" << std::endl;
		}

		void feed() {
			// Ok - we know how much food Cat need.
			std::cout << "I'm a little kitty, and I'll eat everything you have!" << std::endl;
		}

	private:
		std::string m_breed;
	};

	// The concrete animal - lion
	class Lion : public Felidae {
	public:
		Lion(const std::string &name, int age)
			: Felidae{name}, m_age{age} {
			std::cout << "Lion constructor" << std::endl;
		}

		~Lion() {
			std::cout << "Lion destructor" << std::endl;
		}

		void speak() const {
			// Not so easy, but also known.
			std::cout << "Grrrrrrr!" << std::endl;
		}

		void call() const {
			// It is not a very good idea to call a lion...
			std::cout << get_name() << ", don't eat me, please!" << std::endl;
		}

		void feed() {
			// Ok - we know how much food Lion need.
			std::cout << "I'm a lion!" << std::endl;
		}
	private:
		int m_age;
	};

	void work_with(const Felidae &felidae) {
		std::cout << "Next animal: " << std::endl;
		std::cout << "-- work_with felidae::call()" << std::endl;
		felidae.call();
		std::cout << std::endl;

		std::cout << "-- work_with felidae::speak()" << std::endl;
		felidae.speak();
		std::cout << std::endl;
	}

	void example() {
		std::cout << "*** motivation::example() ***" << std::endl;

		Lion lion1{"Simba", 1};
		Lion lion2{"Mufasa", 20};
		Cat cat1{"Tom", "Russian blue"};
		Cat cat2{"Boris", "Just a cat"};

		// Hm... How can we create a collection?
		std::vector<Felidae*> collection{
			&lion1,
			&lion2,
			&cat1,
			&cat2
		};

		// Ok. Not very good, but ok.
		for (auto felidae : collection) {
			work_with(*felidae);
		}
	}

} // namespace motivation

namespace bad_solution {

	// Abstraction for all cat-like animals: cats, tigers, lions, ets.
	class Felidae {
	public:
		enum class Type {
			Cat,
			Lion
			// many-many others
		};

		Felidae(Type type)
			: m_type{type} {
			std::cout << "Felidae constructor" << std::endl;
		}

		~Felidae() {
			std::cout << "Felidae destructor" << std::endl;
		}

		Type type() const {
			return m_type;
		}

		void speak() const {
			// Hm...
			// It is not a some concrete animal - it is an abstraction.
			// How does the abstraction speak? :)
			std::cout << "Felidae::speak()" << std::endl;
		}

	private:
		Type m_type;
	};


	class Cat : public Felidae {
	public:
		Cat()
			: Felidae{Felidae::Type::Cat} {
			std::cout << "Cat constructor" << std::endl;
		}

		~Cat() {
			std::cout << "Cat destructor" << std::endl;
		}

		void speak() const {
			std::cout << "Cat::speak()" << std::endl;
		}
	};

	class Lion : public Felidae {
	public:
		Lion()
			: Felidae{Felidae::Type::Lion} {
			std::cout << "Lion constructor" << std::endl;
		}

		~Lion() {
			std::cout << "Lion destructor" << std::endl;
		}

		void speak() const {
			std::cout << "Lion::speak()" << std::endl;
		}
	};


	void work_with(const Felidae &felidae) {
		std::cout << "Next animal: " << std::endl;

		// 1. Take a type
		Felidae::Type type = felidae.type();
		// 2. Make a dynamic_cast to target type
		switch(type) {
			case Felidae::Type::Cat: {
				const Cat& cat = static_cast<const Cat&>(felidae);
				std::cout << "-- work_with Cat::call()" << std::endl;
				cat.speak();
				break;
			}
			case Felidae::Type::Lion: {
				const Lion& lion = static_cast<const Lion&>(felidae);
				std::cout << "-- work_with Lion::call()" << std::endl;
				lion.speak();
				break;
			}
			default:
				std::cout << "Error! Unknown Felidae!" << std::endl;
		}
	}

	void example() {
		std::cout << "*** bad_solution::example() ***" << std::endl;

		Lion lion1{};
		Lion lion2{};
		Cat cat1{};
		Cat cat2{};

		// Hm... How can we create a collection?
		std::vector<Felidae*> collection{
			&lion1,
			&lion2,
			&cat1,
			&cat2
		};

		// Ok. Not very good, but ok.
		for (auto felidae : collection) {
			work_with(*felidae);
		}
	}
} // namespace bad_solution

namespace with_virtual {

	// Abstraction for all cat-like animals: cats, tigers, lions, ets.
	class Felidae {
	public:
		Felidae(const std::string &name)
			: m_name{name} {
			std::cout << "Felidae constructor" << std::endl;
		}

		virtual ~Felidae() {
			std::cout << "Felidae destructor" << std::endl;
		}

		// Pure-virtual method - because we can't implement in for the
		// abstract cat-like animal
		virtual void speak() const = 0;

		// virtual method - we can make a some default implementation
		// for all cat-like animals
		virtual void call() const {
			// Ok - I can call ANY cat-like by name.
			std::cout << m_name << ", come here!" << std::endl;
		}

		// Non-virual method. We don't want to change a behavior in the
		// derived classes.
		std::string get_name() const { return m_name; }

	private:
		std::string m_name;
	};

	void example_pure_virtual() {
		// Compile time error here:
		// Felidae felidae{"Unknown"};

		// animal.cpp: In function 'void example_pure_virtual()':
		// animal.cpp: error: cannot declare variable 'felidae' to be of abstract type 'Felidae'
		//       |  Felidae felidae{"Unknown"};
		//       |          ^~~~~~~
		// animal.cpp: note:   because the following virtual functions are pure within 'Felidae':
		//       | class Felidae {
		//       |       ^~~~~~~
		// animal.cpp: note:     'virtual void Felidae::speak() const'
		//       |  virtual void speak() const = 0;
		//       |               ^~~~~

		// We can't create an object of the class if it has any pure-virtual methods!
		// It means than we don't need an "abstract" objects - we need only objects of the
		// derived classes.
	}

	// The concrete animal - cat
	class Cat : public Felidae {
	public:
		Cat(const std::string &name, const std::string &breed)
			: Felidae{name}, m_breed{breed} {
			std::cout << "Cat constructor" << std::endl;
		}

		virtual ~Cat() {
			std::cout << "Cat destructor" << std::endl;
		}

		virtual void speak() const override {
			// Easy! Cats say "meow".
			std::cout << "Meow, meow, meow!" << std::endl;
		}

		virtual void call() const override {
			// Ok - We can call cat by it's name.
			std::cout << get_name() << ", kitty, kitty, kitty, come here!" << std::endl;
		}

	private:
		std::string m_breed;
	};

	// The concrete animal - lion
	class Lion : public Felidae {
	public:
		Lion(const std::string &name, int age)
			: Felidae{name}, m_age{age} {
			std::cout << "Lion constructor" << std::endl;
		}

		virtual ~Lion() {
			std::cout << "Lion destructor" << std::endl;
		}

		virtual void speak() const override {
			// Not so easy, but also known.
			std::cout << "Grrrrrrr!" << std::endl;
		}

		virtual void call() const override {
			// It is not a very good idea to call a lion...
			std::cout << get_name() << ", don't eat me, please!" << std::endl;
		}

	private:
		int m_age;
	};

	void work_with(const Felidae &felidae) {
		std::cout << "-- work_with felidae::speak()" << std::endl;
		felidae.speak();

		std::cout << "-- work_with felidae::call()" << std::endl;
		felidae.call();
	}

	void example() {
		std::cout << "*** with_virtual::example() ***" << std::endl;

		// Now we can create a collection
		std::vector<Felidae*> collection{
			new Lion{"Simba", 1},
			new Lion{"Mufasa", 20},
			new Cat{"Tom", "Russian blue"},
			new Cat {"Boris", "Just a cat"}
		};

		// Ok. Not very good, but ok.
		for (auto felidae : collection) {
			work_with(*felidae);
		}

		for (auto felidae : collection) {
			delete felidae;
		}
	}

} // namespace with_virtual

int main()
{
	motivation::example();
	std::cout << std::endl;

	bad_solution::example();
	std::cout << std::endl;

	with_virtual::example();
	std::cout << std::endl;
}
