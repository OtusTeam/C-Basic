#include <string>

class Person {
public:
    Person(const char* firstname, const char* lastname)
        : firstname_{firstname}
        , lastname_{lastname} {
    }

    Person(const Person &other)
        : firstname_{other.firstname_}
        , lastname_{other.lastname_}
    {}

    Person &operator=(const Person &other) {
        firstname_ = other.firstname_;
        lastname_ = other.lastname_;
        return *this;
    }

private:
    std::string firstname_;
    std::string lastname_;
};

int main() {
    Person john{"John", "Smith"};
    Person mary{"Mary", "Jane"};

    try {
        john = mary;
    } catch (...) {
        
    }
}
