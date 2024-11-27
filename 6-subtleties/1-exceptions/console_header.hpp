#pragma once
#include <iostream>

struct Header {
	explicit Header(const char * msg) {
		std::cout << "****  " << msg << "  ****" << std::endl;
	}

	~Header() {
		std::cout << "  ********  " << std::endl << std::endl;
	}
};
