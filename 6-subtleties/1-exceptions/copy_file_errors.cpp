#include <filesystem>
#include <iostream>

// copy_file source dest

// Copy the source file to the dest file
int main(int argc, char** argv) {

	// Check arguments count
	if(argc < 3) {
		std::cout << "Usage:"
			"\ncopy_file source dest"
			"\n\tsource - the source file path"
			"\n\tdest - the destination file path"
			"\nNote: the source file path should exist and the source file should be a regular file."
			"\nNote: the destination file path should be correct and the destination file should not exist.";
		return -1;
	}

	// Check the first path
	std::filesystem::path source = argv[1];
	// 1. for existing
	if(!std::filesystem::exists(source)) {
		std::cout << "The source file does not exist. Path: " << source << std::endl;
		return -1;
	}
	// 2. for regular file
	if(!std::filesystem::is_regular_file(source)) {
		std::cout << "The source file path is not a path to the regular file. Path: " << source << std::endl;
		return 0;
	}

	// Check the second path
	std::filesystem::path dest = argv[2];
	// 1. for existing
	if(std::filesystem::exists(dest)) {
		std::cout << "The destination file should not exist. Path: " << dest << std::endl;
		return -1;
	}

	std::error_code error;
	std::filesystem::copy(source, dest, error);
	if(error) {
		std::cout << "Failed to copy the source path [" << source << "] to the dest path [" << dest << "]. Error: " << error.message() << std::endl;
		return -1;
	}

	return 0;
}