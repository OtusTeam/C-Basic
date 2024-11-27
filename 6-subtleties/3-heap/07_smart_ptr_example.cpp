// Dynamic memory usage example
#include <array>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

#include "01_strategy.hpp"
#include "07_smart_ptr.hpp"

const size_t max_units = 1'000'000;

smart_ptr<Unit> make_unit_and_select(Selection &selection) {
    smart_ptr<Unit> solder{new Unit{0, 0}};
    selection.set(solder.get());
    return solder;
}

int main() {
    Selection selection;
    std::vector<smart_ptr<Unit>> units;
    units.reserve(max_units);
    for (size_t i = 0; i < max_units; ++i) {
        units.push_back(make_unit_and_select(selection));
        selection.click(100, 100);
        selection.unset();
    }
}
