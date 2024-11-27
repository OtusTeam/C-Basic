#include <thread>
#include <iostream>

class thread_guard {
public:
    thread_guard(std::thread &thread)
        : thread_{thread}
    {}

    thread_guard(const thread_guard&) = delete;

    thread_guard& operator=(const thread_guard&) = delete;
    
    ~thread_guard() {
        if (thread_.joinable()) {
            thread_.join();
        }
    }
private:
    std::thread &thread_;
};

void foo() {} 

int main() {
    std::thread th{foo};
    thread_guard guard{th};
}
