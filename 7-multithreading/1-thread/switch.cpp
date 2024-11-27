#include <thread>
#include <iostream>

const int num_iters = 10'000;

void print_n(char ch, int count) {
    while (--count) {
        std::cout.put(ch);
    }
}

int main() {
    std::thread underscore{print_n, '_', num_iters};
    std::thread bar{print_n, '|', num_iters};
    underscore.join();
    bar.join();
}
