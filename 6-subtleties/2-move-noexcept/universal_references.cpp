#include <iostream>
#include <string>
#include <vector>


#define UNUSED(variable) (void)variable

// void testFunc(int counter, std::string s) {
// 	std::cout << "std::string" << s << std::endl;
// }

void testFunc(int counter, std::string& s) {
	std::cout << '[' << counter << ']' << "- std::string& " << s << std::endl;
}

void testFunc(int counter, std::string&& s) {
	std::cout << '[' << counter << ']' << "- std::string&&" << s << std::endl;
}

template<typename T>
void testUnirefFuncBad(int counter, T&& param) {
	// param
	testFunc(counter, param);
}

template<typename T>
void testUnirefFunc(int counter, T&& param) {
	// param
	testFunc(counter, std::forward<T>(param));
}

// T&& - universal (T&, T&&)
// std::forward<T>()

int main() {

	std::string str{"Hello!"};

	testFunc(0, str); // str&
	testFunc(1, std::move(str)); // str&&

	testUnirefFuncBad(2, str); // str&
	testUnirefFuncBad(3, std::move(str)); // str&

	testUnirefFunc(4, str);            // str&
	testUnirefFunc(5, std::move(str)); // str&&

	return 0;
}