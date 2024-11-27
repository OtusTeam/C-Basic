#include <iostream>

template <typename T, size_t N>
class FixedSizeContainer 
{
public:
	FixedSizeContainer() : last_{0} {}

	bool push_back(const T &v) 
	{
		if (last_ >= N) 
		{
			// No free space to add one more element
			return false;
		}
		data_[last_] = v;
		last_++;
		return true;
	}

	bool get(const size_t pos, T &out) const 
	{
		if (pos >= last_) 
		{
			// invalid position
			return false;
		}
		out = data_[pos];
		return true;
	}

	bool erase(const size_t pos) 
	{
		if (pos >= last_) 
		{
			// invalid position
			return false;
		}
		// need to move all element after 'pos' to one position to the left
		for (size_t i = pos; i < last_; ++i) 
		{
			data_[i] = data_[i + 1];
		}
		last_--;
		return true;
	}

	size_t count() const { return last_; }

private:
	T data_[N];
	size_t last_;
};

template <typename T, size_t N>
void print_container(const FixedSizeContainer<T, N> &container) 
{
	for (size_t i = 0; i < container.count(); ++i) 
	{
		if (i != 0) std::cout << ' ';
		
		T value;
		container.get(i, value);
		std::cout << value;
	}
}

void test_container_int() 
{
	FixedSizeContainer<int, 5> int_container;

	int_container.push_back(0);
	int_container.push_back(1);
	int_container.push_back(2);
	int_container.push_back(3);
	int_container.push_back(4);

	print_container(int_container);
	std::cout << std::endl;

	int_container.erase(2);

	print_container(int_container);
	std::cout << std::endl;
}

int main() 
{
	test_container_int();
}