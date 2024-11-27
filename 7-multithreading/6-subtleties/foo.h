// OTUS C++ Basic course
// thread_local example

#pragma once

#include <iostream>
#include <mutex>
#include <thread>

class Foo {
  public:
    Foo() {
        std::lock_guard lock{mtx_};
        std::clog << "Foo ctor called from " << std::this_thread::get_id()
                  << " counter is " << counter << std::endl;
    }

    ~Foo() {
        std::lock_guard lock{mtx_};
        std::clog << "Foo dtor called from " << std::this_thread::get_id()
                  << " counter is " << counter << std::endl;
    }

    unsigned int counter = 0;
  private:
    inline static std::mutex mtx_;
};
