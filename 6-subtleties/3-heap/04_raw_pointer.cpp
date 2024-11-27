

int main() {

    {
        auto ptr = new int{10};

        // ...

        delete ptr;
    }

    {
        auto value = 10;
        auto ptr = new int{10};

        // ...

        ptr = &value;
    }

    {
        int* ptr = new int[10];

        // ...

        delete[] ptr;
    }

    {
        auto ptr = new int[10];

        // if (...) {

        // } else if (...) {
        //     ...
        // } else if (...) {
        //
        //     return ... !!!!!!!
        // } ...

        delete[] ptr;
    }

    return 0;
}
