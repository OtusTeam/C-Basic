#include <cstring>
#include <exception>
#include <new>

class Person {
public:
    Person(const char* firstname, const char* lastname) {
        try {
            size_t firstnameLength = std::strlen(firstname);
            firstname_ = new char[firstnameLength + 1];
            std::strncpy(firstname_, firstname, firstnameLength);

            size_t lastnameLength = std::strlen(lastname);
            lastname_ = new char[lastnameLength + 1];
            std::strncpy(lastname_, lastname, lastnameLength);
        } catch (const std::bad_alloc &) {
            delete firstname_;
            throw;
        }
    }

    ~Person() {
        delete firstname_;
        delete lastname_;
    }
private:
    char *firstname_;
    char *lastname_;
};


int main() {
    try {
        Person john{"John", "Smith"};
    } catch (...) {

    }
}