// https://godbolt.org/z/x3zhMx

#include <fmt/color.h>
#include <fmt/core.h>
#include <fmt/os.h>
#include <fmt/ranges.h>
#include <vector>

void printVector() {
    std::vector<int> v = {1, 2, 3};
    fmt::print("{}\n", v);
}

void printString() {
    std::string out = fmt::format("My custom text, {0}, {0}, {0}", 23, 32);
    //ADD ERROR
    //    std::string out = fmt::format("My custom text, {}, {:2f}, {}", 23, "tert", "Ha-ha");
    //    std::string out = fmt::format("My custom text, {}, {:2f}, {}", 23, 23.43);
    fmt::print(out);
}

void examples() {
    fmt::format("{:<30}", "left aligned");
    // Result: "left aligned                  "
    fmt::format("{:>30}", "right aligned");
    // Result: "                 right aligned"
    fmt::format("{:^30}", "centered");
    // Result: "           centered           "
    fmt::format("{:*^30}", "centered"); // use '*' as a fill char
    // Result: "***********centered***********"

    fmt::print(fmt::emphasis::bold,
               "\n\n\n\n|{0:-^{2}}|\n"
               "|{1: ^{2}}|\n"
               "|{0:-^{2}}|\n",
               "", "I Love C++!", 50);
}

int main() {
    fmt::print("Hello, world!\n");

    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold,
               "Hello, {}!\n", "world");
    fmt::print(fg(fmt::color::floral_white) | bg(fmt::color::slate_gray) |
               fmt::emphasis::underline,
               "Hello, {}!\n", "мир");
    fmt::print(fg(fmt::color::steel_blue) | fmt::emphasis::italic,
                  "Hello, {}!\n", "世界");

    printVector();
    printString();

    examples();
}
