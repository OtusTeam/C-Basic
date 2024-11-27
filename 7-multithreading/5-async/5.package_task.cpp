// OTUS C++ basic course
// std::package_task example

#include <future>
#include <iostream>
#include <stdexcept>
#include <thread>
#include <functional>

bool is_prime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i < n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void task_lambda() {
    std::packaged_task<bool(int)> task([](int n) { return is_prime(n); });
    std::future<bool> result = task.get_future();
    task(4159);
    std::cout << "is_prime(4159): " << result.get() << "\n";
}

void task_bind() {
    std::packaged_task<bool()> task(std::bind(is_prime, 5021));
    std::future<bool> result = task.get_future();
    task();
    std::cout << "is_prime(5021): " << result.get() << "\n";
}

void task_thread() {
    std::packaged_task<bool(int)> task(is_prime);
    std::future<bool> result = task.get_future();
    std::thread task_td(std::move(task), 7919);
    task_td.join();
    std::cout << "is_prime(7919): " << result.get() << "\n";
}

int main() {
    task_lambda();
    task_bind();
    task_thread();
}