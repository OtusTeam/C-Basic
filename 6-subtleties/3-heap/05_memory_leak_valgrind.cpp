// Dynamic memory usage example
#include <array>
#include <iostream>
#include <thread>
#include <chrono>

#include "01_strategy.hpp"

const std::size_t max_units = 1'000'000;

void make_unit_and_select(Selection &selection) {
    Unit *solder = new Unit{0, 0};
    selection.set(solder);
}

//valgrind --leak-check=full ./05_memory_leak_valgrind
//valgrind --tool=massif --time-unit=ms ./05_memory_leak_valgrind
//ms_print massif.out.2022
int main() {
    Selection selection;
    for (std::size_t i = 0; i < max_units; ++i) {
        make_unit_and_select(selection);
        selection.click(100, 100);
        selection.unset();
    }
}
