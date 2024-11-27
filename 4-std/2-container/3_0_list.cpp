#include <iostream>
#include <list>
#include <vector>

int main(int, char *[]) {
	std::vector<int> myvec{100, 200, 300};
	std::list<int> mylist;

	std::list<int>::iterator it = mylist.insert(mylist.begin(), 10);

	it = mylist.insert(it, 2, 20);
	it = mylist.insert(it, myvec.cbegin(), myvec.cend());
	it = mylist.begin();
	mylist.insert(it, {1, 2, 3});
	mylist.push_back(45);

	std::cout << "List content:";
	for (const int &x : mylist) {
		std::cout << " " << x;
	}
	std::cout << std::endl;

	return 0;
}

// Loss of unique interface
// template <typename T>
// void traversing_container_elements(T & data_container, const std::string& msg)
// {
//     std::cout << msg << std::endl;
//     for (std::size_t i = 0; i < data_container.size(); ++i)
//     {
//         std::cout << data_container[i] << " ";
//     }
//     std::cout << std::endl;
// }

template <typename T>
class DataBlock {
private:
	T data_;
	DataBlock *next_;
	DataBlock *prev_;
};

template <typename T>
class List {
private:
	DataBlock<T> *head_;
	DataBlock<T> *tail_;
};

//     head                                                   tail
//
//       |                                                     |
//       |                                                     |
//       V                                                     V
//    _ _ _ _ _         _ _ _ _ _         _ _ _ _ _         _ _ _ _ _
//   |         | ----> | data    | ----> |         | ----> |         |
//   |         |       | next    |       |         |       |         |
//   |         | <---- | prev    | <---- |         | <---- |         |
//    - - - - -         - - - - -         - - - - -         - - - - -
