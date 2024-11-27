#include "line_separator.h"

#include <deque>

void api_demo() {
	int stack_var = 0;
	std::deque<int> dq{1, 2, 3, 4, 5};
	print(dq);

	dq.push_front(0);
	dq.push_back(6);
	print(dq);

	dq.pop_front();
	dq.pop_back();
	print(dq);

	for (auto val : dq) // range based for
		std::cout << val << " ";
	std::cout << std::endl;
}

int main(int argc, char *argv[]) {
	api_demo();
}