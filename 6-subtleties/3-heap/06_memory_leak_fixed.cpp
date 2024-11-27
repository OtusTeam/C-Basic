// Dynamic memory usage example
#include <vector>

#include "01_strategy.hpp"

const std::size_t max_units = 1'000'000;

Unit *make_unit_and_select(Selection &selection) {
    Unit *solder = new Unit{0, 0};
    selection.set(solder);
    return solder;
}

void clean_units(std::vector<Unit *> &units) {
    for (Unit *unit : units) {
        delete unit;
    }
    units.clear();
}

int main() {
    Selection selection;
    std::vector<Unit *> units;
    units.reserve(max_units);
    for (std::size_t i = 0; i < max_units; ++i) {
        units.push_back(make_unit_and_select(selection));
        selection.click(100, 100);
        selection.unset();
    }
    clean_units(units);
}
