// OTUS C++ basic course
// Promise example

#include <chrono>
#include <future>
#include <iostream>
#include <ostream>
#include <thread>


int main() {
    std::promise<int> p;
    std::future<int> f = p.get_future();

    std::cout << "Answer to the Ultimate question of Life, Universe, and "
                 "Everything: ";
    std::cout.flush();
    std::thread ultimate_question_of_life{[&p]() {
        std::this_thread::sleep_for(std::chrono::seconds(15));
        p.set_value(42);
    }};
    while (f.wait_for(std::chrono::seconds(1)) != std::future_status::ready) {
        std::cout << '.';
        std::cout.flush();
    }
    std::cout << f.get() << "\n";
    ultimate_question_of_life.join();
}