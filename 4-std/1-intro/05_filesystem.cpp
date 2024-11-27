// https://en.cppreference.com/w/cpp/filesystem
#include <filesystem>

#include <fstream>
#include <iostream>

int main()
{
	// 1.
	// Returns or sets the current working directory
	const std::filesystem::path currentDir = std::filesystem::current_path();
	std::cout << currentDir << '\n';

	// 2.
	const auto someFile = currentDir / ".." / "readme.txt";
	std::cout << someFile << '\n';

	const auto otherFile = currentDir / "otherFolder/otherFile.txt";
	std::cout << otherFile << '\n';

	// 3.
	// An iterator to the contents of the directory
	for (auto const &entry : std::filesystem::directory_iterator(currentDir)) {
		auto filename = entry.path().filename();
		// std::cout << filename << '\n';
	}

	// 4.
	// Returns the path of the parent path
	std::cout << otherFile.parent_path() << '\n';
	// Returns filename with extenstion
	std::cout << otherFile.filename() << '\n';
	// Returns filename only
	std::cout << otherFile.stem() << '\n';
	// Returns extension
	std::cout << otherFile.extension() << '\n';

	// 5.
	const auto folder = currentDir / "folder";
	std::cout << "First exists: " << std::filesystem::exists(folder) << '\n';
	try {
		std::filesystem::create_directories(folder);
	} catch (const std::filesystem::filesystem_error &e) {
		std::cout << "Exception! " << e.what() << '\n';
	}
	std::cout << "Second exists: " << std::filesystem::exists(folder) << '\n';

	// 6.
	const std::filesystem::path wrongFolder = "/super_root";
	std::error_code errCode;
	bool result = std::filesystem::create_directories(wrongFolder, errCode);
	if (errCode) {
		std::cout << "Creation failed! " << errCode.value() << '\n';
	}
	std::cout << "errCode = " << errCode.value() << '\n';
	std::cout << "result  = " << result << '\n';

	// 7.
	const auto file = folder / "file.txt";
	{
		// Returns the native version of the path
		std::ofstream stream(file.native());
		if (!stream.is_open()) {
			std::cout << "Failed to create file: " << file << '\n';
		} else {
			stream << "Hello, World!" << '\n';
		}
	}
	auto last_write_time = std::filesystem::last_write_time(file);

	// 8
	// Removes a file or empty directory
	std::filesystem::remove(file);
	std::cout << "File exists after remove: " << std::filesystem::exists(file) << '\n';
	// Removes a file or directory and all its contents, recursively
	std::filesystem::remove_all(folder);
	std::cout << "Folder exists after remove: " << std::filesystem::exists(folder) << '\n';
}
