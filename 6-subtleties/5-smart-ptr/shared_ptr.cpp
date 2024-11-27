#include "pretty.h"
#include "utils.h"

#include <memory>
#include <functional>

template<typename T>
struct shared_ptr {
    shared_ptr(T* ptr)
        : m_counter{new std::size_t{1}},
          m_ptr{ptr} {
    }

    shared_ptr(const shared_ptr& other)
        : m_counter{ other.m_counter },
          m_ptr{ other.m_ptr } {
        ++(*m_counter);
    }

    ~shared_ptr() {
        if (--(*m_counter) == 0) {
            delete(m_ptr);
            delete(m_counter);
        }
    }

private:
    T* m_ptr;
    std::size_t* m_counter;
};

class A {
  public:
    A() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    ~A() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

void shared_ptr_example() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    shared_ptr<A> ptr1(new A);
    auto ptr2 = ptr1;
}

void delete_A(A *ptr) { delete ptr; }

void size_of() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    A *raw_ptr = nullptr;
    std::shared_ptr<A> ptr1(new A);
    A* raw = ptr1.get();
    ptr1.reset();

    std::shared_ptr<A> ptr2(new A, delete_A);

    auto lam = [](A *ptr) { delete ptr; };
    std::shared_ptr<A> ptr3(new A, lam);

    int some_value = 42;
    auto lam2      = [&some_value](A *ptr) { delete ptr; };
    std::shared_ptr<A> ptr4(new A, lam2);

    PRETTY_COUT(sizeof(raw_ptr), sizeof(ptr1), sizeof(ptr2), sizeof(ptr3),
                sizeof(ptr4));
}

int main(int argc, char *argv[]) {
    // shared_ptr_example();
    size_of();
    return 0;
}
