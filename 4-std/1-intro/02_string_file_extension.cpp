#include <iostream>
#include <string>


/*
  Test cases:
	./02_string_file_extension file
	./02_string_file_extension file.txt
	./02_string_file_extension file.tmp
*/

int main(int argc, char *argv[]) {
	// 0. Preliminary declarations
	std::string file_name;
	std::string base_name;
	std::string ext_name;
	std::string tmp_name;

	const std::string suffix("tmp");

	// 1. Parse command line arguments
	for (int i = 1; i < argc; ++i) {
		file_name = argv[i];

		// 2. Filename does not contain any period
		const std::string::size_type idx = file_name.find('.');
		if (idx == std::string::npos) {
			tmp_name = file_name + '.' + suffix;
		} else {
			base_name = file_name.substr(0, idx);
			ext_name = file_name.substr(idx + 1);

			if (ext_name.empty()) {
				tmp_name = file_name; // "qwerty."
				tmp_name += suffix;

			} else if (ext_name == suffix) {
				tmp_name = file_name;
				tmp_name.replace(idx + 1, ext_name.size(), "dat");
			} else {
				tmp_name = file_name;
				tmp_name.replace(idx + 1, std::string::npos, suffix);
			}
		}
		std::cout << file_name << " --> " << tmp_name << '\n';
	}

	return 0;
}