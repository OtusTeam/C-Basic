#include <array>
#include <iostream>

#include "01_strategy.hpp"

void make_unit_and_select(Selection &selection) {
    Unit solder{0, 0};
    selection.set(&solder);
}

void move_home(Selection &selection) {
    std::array<int, 10> numbres = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    selection.click(100, 100);
    for (int num : numbres) {
        std::cout << num << ' ';
    }
    std::cout << '\n';
}

int main() {
    Selection selection;
    make_unit_and_select(selection);
    move_home(selection);
    selection.unset();
}
