#include <iostream>

using std::cout;
using std::endl;

int main() {
    // character array is a C-style string
    char paul[] = "Paul";

    cout << paul << endl;

    for (int i = 0; i < 4; ++i) {
        cout << paul[i] << ' ';
    }
    cout << endl;

    // '\0' - null terminator
    // | P | a | u | l | \0 |
    for (int i = 0; paul[i] != '\0'; ++i) {
        cout << paul[i] << ' ';
    }
    cout << endl;

    // noncharacter arrays
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 27};
    const int nprimes = sizeof(primes) / sizeof(primes[0]);
    for (int i = 0; i < nprimes; ++i) {
        cout << primes[i] << ' ';
    }
    cout << endl;


    // pointers
    for (char* p = paul; *p != '\0'; ++p) {
        cout << *p << ' ';
    }
    cout << endl;

    // string length (strlen)
    int paul_len = 0;
    for (char *p = paul; *p != '\0'; ++p) {
        ++paul_len;
    }
    cout << "paul name length: " << paul_len << endl;

    // string copy (strcpy)
    char name[80];
    char *src = paul;
    char *dst = name;
    do {
        *dst++ = *src++;
    } while (*src != '\0');
    *dst = '\0';
    cout << name << endl;
}