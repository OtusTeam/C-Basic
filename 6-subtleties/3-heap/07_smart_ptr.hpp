// Smart pointer implementation example

#pragma once

#include <utility>

template <class T>
class smart_ptr {
  public:
    smart_ptr() noexcept {
    }
    smart_ptr(T *ptr) noexcept : ptr_{ptr} {
    }

    ~smart_ptr() {
        delete ptr_;
    }

    // Non copyable
    smart_ptr(const smart_ptr<T> &) = delete;
    smart_ptr &operator=(const smart_ptr<T> &) = delete;

    // Movable
    smart_ptr(smart_ptr<T> &&other) noexcept {
        std::swap(ptr_, other.ptr_);
    }

    smart_ptr &operator=(smart_ptr<T> &&other) noexcept {
        if (this == &other) {
            return *this;
        }
        reset();
        std::swap(ptr_, other.ptr_);
        return *this;
    }

    bool empty() const noexcept {
        return ptr_ == nullptr;
    }

    // conversion to bool operator overloading to support code like
    // if (!p) {}
    operator bool() const noexcept {
        return empty();
    }

    void reset(T *ptr = nullptr) noexcept {
        delete ptr_; // it is save to delete nullptr;
        ptr_ = ptr;
    }

    const T *get() const noexcept {
        return ptr_;
    }

    T *get() noexcept {
        return ptr_;
    }

    // operator * overloading to support code like this
    // smart_ptr<Object> p{new Object};
    // *p = Object{};
    const T &operator*() const noexcept {
        return get();
    }

    T &operator*() noexcept {
        return get();
    }

    // -> operator overloading to support code like this
    // smart_ptr<Object> p{new Object};
    // p->object_method();
    const T *operator->() const noexcept {
        return get();
    }

    T *operator->() noexcept {
        return get();
    }

  private:
    T *ptr_ = nullptr;
};
