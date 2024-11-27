#include <iostream>
#include <string>

int main() {
	using namespace std;

	int value1, value2;
	string name;

	cout << "Input your name: " << endl;
	cin >> name;

	cout << "Input your name (without endl): ";
	cin >> name;

	cout << "Input value1 and value2: " << endl;
	cin >> value1 >> value2;

	cout << "Hi (without endl), " << name << endl;
	cout << "Hi, " << name << endl;
	cout << "sum of two values is: " << value1 + value2 << endl;

	return 0;
}
