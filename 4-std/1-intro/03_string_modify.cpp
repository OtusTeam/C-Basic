#include <iostream>
#include <string>

void modify()
{
	{
		std::cout << " Copy and Substr\n";
		std::string chemicals{"Argentum Mercury Ferrum"};

		auto mercury = chemicals.substr(chemicals.find('M'), 7);
		std::cout << "C++ string: " << mercury << "\n";

		char ferrum[7]{};
		// Copies characters
		chemicals.copy(ferrum, 6, chemicals.find('F'));
		std::cout << "C string: " << ferrum << '\n';
	}

	{
		std::cout << '\n'
				  << " Replace " << '\n';
		std::string chemicals{"Argentum Mercury Ferrum"};

		auto mPos = chemicals.find('M');
		// Replaces specified portion of a string
		chemicals.replace(chemicals.begin(), chemicals.begin() + mPos, "Elements:");
		std::cout << "New string: " << chemicals << " pos = " << mPos << '\n';

		auto fPos = chemicals.find('F');
		chemicals.replace(chemicals.begin() + fPos - 1, chemicals.end(), ", Freddie");
		std::cout << "New string: " << chemicals << "\n";
	}
}

void convertions()
{
	std::cout << " Convertions\n";
	std::string one{"1"};
	std::string fifteen{"F"};
	std::string fourteen{"1110"};
	double real = 12.567890;

	std::cout << "One to integer: " << std::stoi(one) << "\n";
	std::cout << "Fifteen to integer: " << std::stol(fifteen, nullptr, 16) << "\n";
	std::cout << "Fourteen to integer: " << std::stoull(fourteen, nullptr, 2) << "\n";
	std::cout << "Real to string: " << std::to_string(real) << "\n";
}

int main()
{
	modify();
	convertions();
}
