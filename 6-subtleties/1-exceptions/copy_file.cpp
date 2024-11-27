#include <filesystem>

// copy_file source dest

// Copy the source file to the dest file
int main(int argc, char** argv) {

	std::filesystem::copy(argv[1], argv[2]);

	return 0;
}