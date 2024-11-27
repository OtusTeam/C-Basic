#include <cstddef>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <vector>

struct Entity {
  uint8_t id{255};
};

using Color = uint32_t;

struct Shape : public Entity {
  Color color{};
};

struct Square : public Shape {
  double length{};
};

void printSize()
{
    std::cout << "sizeof(Entity) " << sizeof(Entity) << '\n'
              << "sizeof(Shape) " << sizeof(Shape) << '\n'
              << "sizeof(Square) " << sizeof(Square) << '\n';
}

void printAddress(const char* name, const void* ptr)
{
    std::cout << "Address of " << name << " is " << ptr << '\n';
}

void printAddresses(const Square& square)
{
    printAddress("Square", &square);
    printAddress("Shape (static_cast)", static_cast<const Shape*>(&square));
    printAddress("Entity (static_cast)", static_cast<const Entity*>(&square));
}

void base()
{
    printSize();

    Square square;
    printAddresses(square);
}

void hack(std::vector<std::byte>& mem)
{
#warning "Unsafe code. For demo purposes only"
    {
        static_assert(sizeof(Entity) == sizeof(uint8_t),
                      "sizeof(Entity) must be 1");
        const uint8_t id = 42;
        std::memcpy(mem.data(), &id, 1);
    }
    {
        static_assert(sizeof(Square) - sizeof(Shape) == sizeof(double),
                      "sizeof(Square) must be 1");
        double length = -1.;
        std::memcpy(mem.data() + sizeof(Shape), &length, sizeof(double));
    }
}

void underTheHood()
{
    Square square;
    std::vector<std::byte> mem(sizeof(Square));

    std::byte* sAsBytes = reinterpret_cast<std::byte*>(&square);
    std::memcpy(mem.data(), sAsBytes, mem.size());

    hack(mem);

    std::memcpy(sAsBytes, mem.data(), mem.size());

    std::cout << "I'm in. Hehehe" << '\n';
    std::cout << "New id: " << unsigned(square.id) << '\n';
    std::cout << "New length: " << square.length << '\n';
}

int main()
{
    base();
    underTheHood();
}
