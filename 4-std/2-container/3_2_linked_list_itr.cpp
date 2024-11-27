#include "line_separator.h"
#include <iostream>

// Proof of concept List<T>::Iterator type

template <typename T>
struct DataBlock final {
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
class List final {
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

	void push_back(const T &item) {
		DataBlock<T> *new_data_block = new DataBlock<T>(item);
		new_data_block->data_item_ = item;
		current_node_->data_block_ = new_data_block;
		current_node_ = new_data_block;
	}

	class Iterator {
	public:
		Iterator() noexcept : itr_node_(nullptr) {}

		Iterator(DataBlock<T> *node) noexcept : itr_node_(node) {}

		Iterator &operator++() {
			if (itr_node_)
				itr_node_ = itr_node_->data_block_;
			return *this;
		}

		// Postfix ++ overload
		Iterator operator++(int) {
			Iterator iterator = *this;
			++(*this);
			return iterator;
		}

		bool operator!=(const Iterator &iterator) {
			return itr_node_ != iterator.itr_node_;
		}

		T &operator*() {
			return itr_node_->data_item_;
		}

	private:
		DataBlock<T> *itr_node_;
	};

	Iterator begin() {
		return Iterator(head_node_->data_block_);
	}

	Iterator end() {
		return Iterator(nullptr);
	}

private:
	DataBlock<T> *head_node_;
	DataBlock<T> *current_node_;
};

// ---------------------------------------------------------------------------

// Common interface works with iterators

template <typename T>
void iterate_container_elements(T &data_container, const std::string &msg) {
	std::cout << msg << std::endl;

	LineSeparator::out(" Standard for output:");
	auto itr = data_container.begin();
	for (; itr != data_container.end(); ++itr) {
		std::cout << *itr << " ";
	}
	std::cout << std::endl;

	LineSeparator::out(" for_each output:");
	for (const auto &item : data_container) {
		std::cout << " ! " << item;
	}
	std::cout << std::endl;
}

void generalization_2_example() {
	LineSeparator::out(" Pushing back elements:");
	List<int> list;
	for (int i = 500; i <= 800; i += 30) {
		list.push_back(i);
	}

	LineSeparator::out(" Iterate the elements:");
	iterate_container_elements(list, " List:");
}

// Iterator& operator=(const Iterator& itr1)
// {
//     std::cout << "!!!!!!!!!!!!!!\n";
//     // this->itr_node_ = node;
//     return *this;
// }

// Iterator& operator=(DataBlock<T>* node)
// {
//     std::cout << "++++++\n";
//     this->itr_node_ = node;
//     return *this;
// }

int main(int, char *[]) {
	LineSeparator::out(" Pushing back elements:");
	List<int> list;
	for (int i = 100; i <= 200; i += 10) {
		list.push_back(i);
	}

	LineSeparator::out(" Output the elements:");
	List<int>::Iterator itr = list.begin();
	for (; itr != list.end(); ++itr) {
		std::cout << (*itr) << std::endl;
	}

	List<int>::Iterator itr_2 = list.begin();
	itr_2++;
	++itr_2;
	(*itr_2) = 4567;

	LineSeparator::out(" Change some elements:");
	for (itr = list.begin(); itr != list.end(); ++itr) {
		std::cout << (*itr) << std::endl;
	}

	LineSeparator::out(" Unique interface examples:");
	generalization_2_example();

	return 0;
}