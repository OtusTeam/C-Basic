// OTUC C++ Basic course thread_local example

#include <algorithm>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

#include "foo.h"

thread_local Foo foo;

void task() {
    ++foo.counter;  // no need for mutex because foo is thread_local
    std::this_thread::sleep_for(std::chrono::seconds(3));

    std::cout << std::this_thread::get_id() << " foo.counter = " << foo.counter << std::endl;
}

int main() {
    size_t nthreads = std::thread::hardware_concurrency();

    std::vector<std::thread> workers;
    std::generate_n(std::back_inserter(workers), nthreads,
                    []() { return std::thread{task}; });

    std::for_each(workers.begin(), workers.end(),
                  [](std::thread &th) { th.join(); });
}
