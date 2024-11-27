#pragma once
#include <iostream>

template <class List>
void run(List list)
{
    for (auto [title, fn]: list) {
        std::cout << "*** " << title << "::example ***" << '\n';
        fn();
        std::cout << "*** " << title << "::end ***" << '\n';
    }
}