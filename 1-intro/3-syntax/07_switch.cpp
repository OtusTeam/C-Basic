#include <bitset>
#include <iostream>
#include <vector>

int main(int, char *[]) {
	int counter = 0;
	short int value = 25;
	
	switch (value) {
	case 25:
		counter += 1;
		std::cout << "First case is selected\n";
		break;
	case 34:
		counter += 10;
		std::cout << "Second case is selected\n";
		break;
	case 56:
		counter += 100;
		std::cout << "Third case is selected\n";
		break;
	default:
		counter = 2000;
	}
	std::cout << " Counter is equal to: " << counter << std::endl;


	int level = 0;
	switch(level) {
		case 0:
			// study 0 level
		case 1:
			// study 1 level
		case 2:
			// study 2 level
		case 3:
			// study 3 level
		default:
			// error
	};


	// ------------------------------------------------------------------------

	const int LEFT_BTN = 1;
	const int MIDDLE_BTN = 3;
	const int RIGHT_BTN = 2;
	const int EXTRA_BTN = 0;
	int mouse_btn = RIGHT_BTN;
	switch (mouse_btn) {
	case LEFT_BTN:
		std::cout << " Left button is pressed. Processing it ... " << std::endl;
		// nested if
		if (true) {
			std::cout << "Operator if invocation\n";
		}
		// Left button is pressed
		break;
	case MIDDLE_BTN:
		// Middle button is pressed
		break;
	case RIGHT_BTN:
		// Right button is pressed
		break;
	case EXTRA_BTN:
		std::cout << " Extra button is pressed. Processing it ... " << std::endl;
		break;
		// is an option but good practice
	default:
		// Do something else if needed
		std::cout << "Dropped into default case scenario" << std::endl;
	}

	return 0;
}