#include "line_separator.h"
#include <iostream>

// Proof of concept List DS
template <typename T>
struct DataBlock {
	DataBlock(const T &initialValue) : data_item_(initialValue),
									   data_block_(nullptr) {
		std::cout << "ctor: " << data_item_ << " " << this << std::endl;
	}

	~DataBlock() {
		std::cout << "dtor: " << data_item_ << " " << this << std::endl;
		delete data_block_;
	}

	T data_item_;
	DataBlock *data_block_;
};

template <typename T>
class List {
private:
	DataBlock<T> *head_node_;
	DataBlock<T> *current_node_;

public:
	List() : head_node_(new DataBlock<T>(T())),
			 current_node_(head_node_) {
		std::cout << "List ctor " << current_node_ << std::endl;
	}

	~List() {
		std::cout << "List dtor " << std::endl;

		delete head_node_;
		head_node_ = nullptr;
		current_node_ = nullptr;
	};

	void append(const T &item) {
		DataBlock<T> *new_data_block = new DataBlock<T>(item);
		new_data_block->data_item_ = item;
		current_node_->data_block_ = new_data_block;
		current_node_ = new_data_block;
	}

	bool next() {
		if (current_node_->data_block_) {
			current_node_ = current_node_->data_block_;
			return true;
		}
		return false;
	}

	T &get_item() {
		return current_node_->data_item_;
	}

	void to_begin() {
		current_node_ = head_node_;
	}
};

int main(int, char *[]) {
	LineSeparator::out("Example 1: Append elements");
	List<int> list;
	for (int i = 30; i < 40; ++i) {
		list.append(i + 1);
	}

	LineSeparator::out("Example 2: Out all the elements");
	list.to_begin();
	while (list.next()) {
		std::cout << list.get_item() << " ";
	}
	std::cout << std::endl;

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

	return 0;
}
