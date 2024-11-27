#include <iostream>

struct Test
{
    Test(int value)
        : m_value(value)
    {}

    int m_value;
};

struct S
{
    S()
    {
        std::cout << "S::ctor" << std::endl;
    }
    ~S()
    {
        std::cout << "S::dtor" << std::endl;
    }

    int m_value;
};

int main() {

    int* a = new int(1);
    Test* t = new Test(2);
    delete t;
    delete a;

    std::cout << "SINGLE ITEM" << std::endl;
    S* s = new S;
    delete s;

    std::cout << "ARRAY" << std::endl;
    S* sArr = new S[5];
    delete[] sArr;

    std::cout << "OPERATOR NEW" << std::endl;
    void* sMem = ::operator new(sizeof(S));
    S* s2 = new(sMem) S;
    s2->~S();
    ::operator delete(sMem);

    return 0;
}
