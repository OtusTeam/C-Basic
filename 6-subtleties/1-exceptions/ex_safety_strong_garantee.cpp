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
        std::string firstname_tmp = other.firstname_;
        std::string lastname_tmp = other.lastname_;
        // no except  below
        firstname_ = std::move(firstname_tmp);
        lastname_ = std::move(lastname_tmp);
        return *this;
    }

private:
    std::string firstname_;
    std::string lastname_;
};

int main() {
    
}
