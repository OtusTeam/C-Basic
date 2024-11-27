// Dynamic memory usage example
#include <array>
#include <iostream>
#include <thread>
#include <chrono>

#include "01_strategy.hpp"

const std::size_t max_units = 1'000;

void make_unit_and_select(Selection &selection) {
    Unit *solder = new Unit{0, 0};
    selection.set(solder);
}

//ASAN_OPTIONS=help=1 ./05_memory_leak_san
int main() {
    Selection selection;
    for (std::size_t i = 0; i < max_units; ++i) {
        make_unit_and_select(selection);
        selection.click(100, 100);
        selection.unset();
    }
}
