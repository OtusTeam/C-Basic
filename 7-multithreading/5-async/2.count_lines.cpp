// OTUS C++ basic course
// Example of exception from future.get()

#include <exception>
#include <fstream>
#include <future>
#include <iostream>
#include <numeric>
#include <stdexcept>
#include <string>
#include <system_error>
#include <vector>

size_t count_lines(const std::string &filepath) {
    std::ifstream is{filepath};
    if (!is.is_open()) {
        throw std::runtime_error{"Failed to open '" + filepath + "'"};
    }
    char ch;
    size_t nlines = 0;
    while (is.get(ch)) {
        if (ch == '\n') {
            ++nlines;
        }
    }
    return nlines;
}

int main(int argc, char *argv[]) {
    std::vector<std::future<size_t>> tasks;

    for (int i = 1; i < argc; ++i) {
        tasks.push_back(std::async(count_lines, argv[i]));
    }

    size_t total = 0;
    bool success = true;
    for (size_t i = 0; i < tasks.size(); ++i) {
        try {
            total += tasks[i].get();
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
            success = false;
        }
    }
    if (success) {
        std::cout << total << "\n";
    }
}