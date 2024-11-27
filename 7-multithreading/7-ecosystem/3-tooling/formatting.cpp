// clang-format example. Before autoformatting.
// https://clang.llvm.org/docs/ClangFormatStyleOptions.html
// In VSCode use Shit+Alt+F.
// Rules from the .clang-format will be used.

#include <iostream>

namespace some {

    struct MyStruct 
	{
        MyStruct(int value)
			: m_value{value} {
        }

		~MyStruct() {
		}

		void doSomething() const 
		{ std::cout << "m_value = " << m_value << std::endl;
		}
			private:
				int m_value;};

	void function() { MyStruct str{54}; int value = 42; std::cout << "value = " << value << std::endl; str.doSomething(); }

}

int
main(
int argc, 
char**argv
) {

some::function();

    return 0;
}