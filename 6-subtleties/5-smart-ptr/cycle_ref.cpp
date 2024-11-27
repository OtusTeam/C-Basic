#include <iostream>
#include <memory>

struct SomeStruct {
    SomeStruct() {
        std::cout << "Constructor!" << std::endl;
    }

    ~SomeStruct() {
        std::cout << "Desctructor!" << std::endl;
    }

    std::shared_ptr<SomeStruct> partner;
};

void function_with_leakage() {
    auto partnerA = std::make_shared<SomeStruct>();
    auto partnerB = std::make_shared<SomeStruct>();
    partnerA->partner = partnerB;
    partnerB->partner = partnerA;
}

int main() {
    function_with_leakage();
}
