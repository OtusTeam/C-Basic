// OTUS C++ Basic course

#include <algorithm>
#include <chrono>
#include <iterator>
#include <thread>
#include <vector>
#include <iomanip>

#include "logger.h"

void task() {
    Logger &logger = Logger::getLogger();
    logger.log("Task started");
    std::this_thread::sleep_for(std::chrono::seconds(3));
    logger.log("Task finished");
}

int main() {
    size_t nthreads = std::thread::hardware_concurrency();

    std::vector<std::thread> workers;
    std::generate_n(std::back_inserter(workers), nthreads,
                    []() { return std::thread{task}; });

    std::for_each(workers.begin(), workers.end(),
                  [](std::thread &th) { th.join(); });
}