#include "pretty.h"
#include "utils.h"

#include <functional>
#include <memory>

template <typename T, typename Deleter = std::default_delete<T>>
class unique_ptr {
    T *ptr{};
    Deleter d;
  public:
    unique_ptr(T *ptr_) : ptr{ptr_} {}
    ~unique_ptr() { d(ptr);}

    unique_ptr(const unique_ptr<T> &) = delete;
    unique_ptr<T> &operator=(const unique_ptr<T> &) = delete;

    unique_ptr(unique_ptr<T> &&other) : ptr{other.ptr} { other.ptr = nullptr; }
    unique_ptr<T> &operator=(unique_ptr<T> &&other) {
        delete ptr;
        ptr = other.ptr;
        other.ptr = nullptr;
        return *this;
    };

    T *get() { return ptr; }

    T *operator->() { return ptr; }
    T& operator*() { return *ptr; }
};

struct SomeStruct
{
    int val;
};

void unique_ptr_example() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    unique_ptr<int> ptr1(new int{41});
    //unique_ptr<int> ptr2(ptr1);
    unique_ptr<int> ptr2(std::move(ptr1));
    std::cout << *ptr2 << std::endl;

    unique_ptr<SomeStruct> s(new SomeStruct {57});
    std::cout << s->val << std::endl;
    std::cout << s.get() << std::endl;
}

class A {
  public:
    A() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    ~A() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

struct deleter {
    void operator()(A *ptr) { delete ptr; }
};

void delete_A(A *ptr) { delete ptr; }

void size_of() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    A *raw_ptr = nullptr;
    std::unique_ptr<A> ptr1(new A);
    std::unique_ptr<A, deleter> ptr2(new A);

    std::unique_ptr<A, std::function<void(A *)>> ptr3(new A, delete_A);
    std::unique_ptr<A, void(*)(A*)> ptr31(new A, delete_A);

    auto lam = [](A *ptr) { delete ptr; };
    std::unique_ptr<A, decltype(lam)> ptr4(new A, lam);

    int some_value = 42;
    auto lam2      = [&some_value](A *ptr) { delete ptr; };
    std::unique_ptr<A, decltype(lam2)> ptr5(new A, lam2);

    PRETTY_COUT(sizeof(raw_ptr), sizeof(ptr1), sizeof(ptr2), sizeof(ptr3), sizeof(ptr31),
                sizeof(ptr4), sizeof(ptr5));
}

class B {};
class C {};

void foo(std::unique_ptr<B>, std::unique_ptr<C>) {}

void make_unique_example() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    auto ptr = std::make_unique<A>();

    foo(std::unique_ptr<B>(new B), std::unique_ptr<C>(new C));
    foo(std::make_unique<B>(), std::make_unique<C>());
}

int main(int argc, char *argv[]) {

    unique_ptr_example();
    size_of();
    // make_unique_example();

    std::unique_ptr<int> u1(new int{56});
    u1.reset();
    std::cout << std::boolalpha << (u1.get() == nullptr) << std::endl;

    std::unique_ptr<int> u2(new int{56});
    int* resource = u2.release();
    delete resource;
    std::cout << std::boolalpha << (u2.get() == nullptr) << std::endl;

    std::unique_ptr<int[]>(new int [42]);

    return 0;
}
