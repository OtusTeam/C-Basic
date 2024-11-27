#include <fstream>
#include <iostream>
#include <string>

bool write_to_file_example(std::ofstream& file) {

	std::cout << "write_to_file_example:\n";

	if (!file.is_open()) {
		std::cout << "Error! File was not opened!\n";
		return false;
	}

	file << 42; // decimal constant example
	file << 3.1415f; // float constant example
	file << "hello!"; // string constant example

	int someVariable = 56;
	file << someVariable; // variable example

	// The result:
	// 423.1415hello!56

	return true;
}

bool read_from_file(std::ifstream& file) {
	std::cout << "read_from_file:\n";

	if (!file.is_open()) {
		std::cout << "Error! File was not opened!\n";
		return false;
	}

	// We can't read to constans... So, we need variables
	float f_value = 0;
	std::string str_value;
	int i_value = 0;

	// Source file content:
	// 423.1415hello!56

	file >> f_value; // 423.1415
	file >> str_value; // hello!56
	file >> i_value; // 0

	std::cout << "f_value = " << f_value << '\n';
	std::cout << "str_value = " << str_value << '\n';
	std::cout << "i_value = " << i_value << '\n';

	return true;
}

bool read_write_file_example(std::fstream& file) {
	std::cout << "read_write_file_example:\n";

	if (!file.is_open()) {
		std::cout << "Error! File was not opened!\n";
		return false;
	}

	// Just write some data and read them back.

	file << 42 << ' ';
	file << "hello!" << ' ';
	file << 3.1415 << '\n';
	file << "some other string" << '\n';

	// file.flush(); // It is not required
	// file.seekg(0); // This is required! :)

	int i_value = 0;
	file >> i_value;
	std::string s_value;
	file >> s_value;
	float f_value = 0.f;
	file >> f_value;
	std::string other_s_value;
	// file >> other_s_value;

	// file.seekg(pos);

	file.ignore();
	std::getline(file, other_s_value);

	std::cout << "i_value = " << i_value << '\n';
	std::cout << "s_value = " << s_value << '\n';
	std::cout << "f_value = " << f_value << '\n';
	std::cout << "other_s_value = " << other_s_value << '\n';

	return true;
}

int main()
{

	const std::string filename = "testFile.txt";

	std::ofstream o_file{ filename };
	bool success = write_to_file_example(o_file);

	if (success) {
		std::cout << "Write to file succeeded!\n";
	}
	else {
		std::cout << "Write to file failed!\n";
		return -1;
	}

	o_file.close(); // Close file to flush all data

	std::ifstream i_file{filename};
	success = read_from_file(i_file);

		if (success) {
		std::cout << "Read from file succeeded!\n";
	}
	else {
		std::cout << "Read from file failed!\n";
		return -1;
	}


	const std::string filename2 = "testFile2.txt";
	std::fstream io_file{filename2, std::ios_base::in | std::ios_base::out | std::fstream::app};
	read_write_file_example(io_file);
}