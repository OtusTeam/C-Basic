#include <fstream>
#include <iostream>

#include "buffer.hpp"

const size_t buff_size = 4096;

void copy_file(std::ifstream &src, std::ofstream &dst) {
    buffer buf{buff_size};

    do {
        src.read(buf.data(), buf.size());
        dst.write(buf.data(), src.gcount());
    } while (src);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cout << "Usage: copy <source> <destination>\n";
        return 1;
    }

    std::ifstream src{argv[1]};
    if (!src.is_open()) {
        std::cerr << "Failed to open source file: " << argv[1] << '\n';
        return 1;
    }
    std::ofstream dst{argv[2]};
    if (!dst.is_open()) {
        std::cerr << "Failed to open destination file: " << argv[2] << '\n';
        return 1;
    }
    copy_file(src, dst);
}