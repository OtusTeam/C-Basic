#include <iostream>

template <typename T>
class smart_ptr {
    T *ptr;

  public:
    smart_ptr(T *ptr_) : ptr{ptr_} {}
    ~smart_ptr() { delete ptr; }

    T* get() { return ptr; }

    T* operator->() { return ptr; }
    T& operator*() { return *ptr; }
};

class A {
  public:
    A() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    ~A() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

void example() {
    smart_ptr<int> ptr(new int{10});
}

void double_free() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    smart_ptr<A> ptr(new A);
    smart_ptr<A> ptr2 = ptr;
}

template <typename T>
void foo(smart_ptr<T> ptr) {
    // do smth with ptr
    std::cout << ptr.get() << std::endl;
}

void double_free2() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    smart_ptr<A> ptr(new A);
    foo(ptr);
}

int main() {
    example();
    double_free();
    double_free2();

    return 0;
}
