// OTUS C++ basic course std::async example

#include <future>
#include <iostream>
#include <thread>

void print_thread_id(const std::string_view &msg) {
    std::clog << msg << " from thread id: " << std::this_thread::get_id()
              << std::endl;
}

int main() {
    print_thread_id("main");

    // std::launch::async запуск задачи в новом потоке
    std::future<void> async_policy =
        std::async(std::launch::async, print_thread_id, "std::launch::async");

    async_policy.wait();

    // std::launch::deferred отложенное (ленивое) выполнение задачи
    std::future<void> deferred_policy = std::async(
        std::launch::deferred, print_thread_id, "std::launch::deferred");
    deferred_policy.wait();

    auto t = std::thread(print_thread_id, "thread");

    // std::launch::async | std::launch::deferred - любая из стратегий по
    // усмотрению реализации
    std::future<void> any_policy =
        std::async(std::launch::async | std::launch::deferred, print_thread_id,
                   "std::launch::async | std::launch::deferred");
    any_policy.wait();

    // По умолчанию ведет себя как std::launch::async | std::launch::deferred
    std::future<void> default_policy = std::async(print_thread_id, "default");
    deferred_policy.wait();
}
