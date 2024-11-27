#pragma once

#include "menu.h"

#include <filesystem>
#include <fstream>
#include <iostream>

#include <cstdlib>

namespace {
	bool from_int(int value, menu::MainSection& result) {
		result = static_cast<menu::MainSection>(value);
		switch(result) {
			case menu::MainSection::NewGame:
			case menu::MainSection::LoadGame:
			case menu::MainSection::SaveGame:
			case menu::MainSection::Quit:
				return true;
		}
		return false;
	}

	bool from_int(int value, menu::NewGameSection& result) {
		result = static_cast<menu::NewGameSection>(value);
		switch(result) {
			case menu::NewGameSection::ManualDeploy:
			case menu::NewGameSection::AutoDeploy:
			case menu::NewGameSection::Back:
				return true;
		}
		return false;
	}

	void clear_screen() {
		return;
#ifdef _WIN32
		system("cls");
#else
		system("clear");
#endif
	}

	void clear_cin() {
		std::cin.clear();
		std::cin.sync();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

menu::MainSection menu::main() {
	clear_screen();

	menu::MainSection result_section;
	for (;;) {
		std::cout << "Wellcome to the super game!"
			"\nPlease, enter the main menu section to open."
			"\n1. New game"
			"\n2. Load the previous game"
			"\n3. Save the current game"
			"\n4. Quit" << std::endl;

		int user_input = -1;
		std::cin >> user_input;

		bool convert_result = from_int(user_input, result_section);
		if(!std::cin.fail() && convert_result) {
			break;
		}
		clear_cin();
		std::cout << "An incorrect value was entered. Try again, please!\n";
	}
	return result_section;
}

std::string menu::folder_path() {
	clear_screen();

	std::string result_folder;
	for (;;) {
		std::cout << "Enter the folder path:" << std::endl;

		std::cin >> result_folder;

		std::filesystem::path path{result_folder};
		if(std::filesystem::is_directory(path)) {
			break;
		}

		clear_cin();
		std::cout << "Folder " << result_folder << " could not be read!"
			<< " Please, enther the correct folder path!" << std::endl;
	}
	return result_folder;
}


menu::NewGameSection menu::new_game() {
	clear_screen();

	menu::NewGameSection result_section;
	for (;;) {
		std::cout << "New game."
			"\nPlease, enter the ship deployment mode."
			"\n1. Manual deploy players ships"
			"\n2. Automatically deploy players ships"
			"\n3. Back the the previous menu section" << std::endl;

		int user_input = -1;
		std::cin >> user_input;

		bool convert_result = from_int(user_input, result_section);
		if(!std::cin.fail() && convert_result) {
			break;
		}
		clear_cin();
		std::cout << "An incorrect value was entered. Try again, please!\n";
	}
	return result_section;
}

menu::CoordinatesSection menu::coordinates(int size, int& x, int& y) {
	clear_screen();

	for (;;) {
		std::cout << "Enter the next coordinates in the next format [x y] or Back to exit"
			"\nExample: " << size - 1 << ' ' << size - 2
			 << std::endl;

		int input_x = -1;
		int input_y = -1;
		std::cin >> input_x >> input_y;
		if(std::cin.fail()) {
			std::cin.clear();
			std::string str;
			std::cin >> str;
			if(str == "Back") {
				return menu::CoordinatesSection::Back;
			}
		}

		bool x_correct = (input_x >= 0) && (input_x < size);
		bool y_correct = (input_y >= 0) && (input_y < size);

		if(!std::cin.fail() && x_correct && y_correct) {
			x = input_x;
			y = input_y;
			break;
		}
		clear_cin();
		std::cout << "An incorrect value was entered!";
		if(!x_correct) {
			std::cout << "\n\tx coordinate is out of field width!";
		}
		if(!y_correct) {
			std::cout << "\n\ty coordinate is out of field height!";
		};
		std::cout << "\nTry again, please!" << std::endl;
	}
	return menu::CoordinatesSection::Next;
}