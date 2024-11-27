// Dynamic memory usage example
#include <memory>

#include "01_strategy.hpp"

int main() {
    Selection selection;
    std::unique_ptr<Unit> solder = std::make_unique<Unit>(0, 0);
    selection.set(solder.get());
    solder.reset();
    selection.click(100, 100);
}
