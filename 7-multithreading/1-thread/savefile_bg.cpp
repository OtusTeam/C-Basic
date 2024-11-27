// Find a problem in this code

#include <cstddef>
#include <fstream>
#include <iostream>
#include <iterator>
#include <ostream>
#include <thread>
#include <vector>

#if defined(__linux__) || defined(__APPLE__)
const char *null = "/dev/null";
#elif defined(_WIN32)
const char *null = "NUL";
#else
#error platform not supportedd
#endif

std::thread savefile_bg(const std::string &filename) {
    return std::thread(
        [](const std::string filename) {
            std::vector<char> buffer(10 * 4096 * 4096, 'A');
            std::ofstream out(filename);
            out.write(buffer.data(), buffer.size());
            out.close();
            std::clog << "File written\n";
        },
        filename);
    
}

int main() {
    std::thread bg_task = savefile_bg(null);
    bg_task.detach();
    std::getchar();
}