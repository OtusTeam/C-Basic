// Dynamic memory usage example
#include <chrono>
#include <thread>
#include <vector>
#include <memory>

#include "01_strategy.hpp"

const size_t max_units = 1'000'000;

std::unique_ptr<Unit> make_unit_and_select(Selection &selection) {
    std::unique_ptr<Unit> solder = std::make_unique<Unit>(0, 0);
    selection.set(solder.get());
    return solder;
}

int main() {
    Selection selection;
    std::vector<std::unique_ptr<Unit>> units;
    units.reserve(max_units);
    for (size_t i = 0; i < max_units; ++i) {
        units.push_back(make_unit_and_select(selection));
        selection.click(100, 100);
        selection.unset();
    }
}
