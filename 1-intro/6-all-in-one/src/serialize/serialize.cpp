#include "serialize.h"

#include <fstream>
#include <iostream>

#include <cassert>

namespace serialize {

	bool save(const char* filename, const gamestate::State* const field, int size) {
		std::ofstream output{filename};
		if(!output.is_open()) {
			return false;
		}

		// Field width and height
		output << size << ' ' << size << std::endl;
		// Content of each cells
		for(int row = 0; row < size; ++row) {
			if(row != 0) {
				output << std::endl;
			}
			for(int col = 0; col < size; ++col) {
				if(col != 0) {
					output << ' ';
				}
				gamestate::State state;
				if(!gamestate::get_state(field, row, col, state)) {
					return false;
				}
				output << static_cast<int>(state);
			}
		}
		return true;
	}

	bool load(const char* filename, gamestate::State* const field, int& size) {
		std::ifstream input{filename};
		if(!input.is_open()) {
			return false;
		}

		// Read field widht/heidht
		int width, height;
		input >> width >> height;
		if(width != height)
			return false;

		size = width;
		for(int row = 0; row < size; ++row) {
			if(row != 0) {
				input.ignore(); // ignore the endline symbol
			}
			int value;
			for(int col = 0; col < size; ++col) {
				input >> value;
				gamestate::State state = static_cast<gamestate::State>(value);
				if(!gamestate::set_state(field, row, col, state)) {
					return false;
				}
			}
		}

		return true;
	}

} // namespace serialize

static int test_main() {
		gamestate::State* player1_field = gamestate::get_player1_field();
		gamestate::State* player1_intel = gamestate::get_player1_intel();
		gamestate::State* player2_field = gamestate::get_player2_field();
		gamestate::State* player2_intel = gamestate::get_player2_intel();

		const int size = 3;
		int field[size][size] = {
			{1, 2, 2},
			{0, 0, 0},
			{0, 1, 1}
		};
		gamestate::set_field_size(size);

		gamestate::debug::fill(player1_field, &field[0][0], size);
		gamestate::debug::fill(player2_field, &field[0][0], size);

		const char* filename1 = "player1_field.txt";
		bool saveResult1 = serialize::save(filename1, player1_field, size);
		if(saveResult1) {
			std::cout << "The game state was saved successfully into the file: " << filename1 << std::endl;
		}
		else {
			std::cout << "Failed to save the game state into the file: " << filename1 << std::endl;
		}

		const char* filename2 = "player2_field.txt";
		bool saveResult2 = serialize::save(filename2, player2_field, size);
		if(saveResult2) {
			std::cout << "The game state was saved successfully into the file: " << filename2 << std::endl;
		}
		else {
			std::cout << "Failed to save the game state into the file: " << filename2 << std::endl;
		}

		gamestate::State actual_field1[gamestate::MaxSize][gamestate::MaxSize] = {};
		int actual_size1 = 0;
		bool loadResult1 = serialize::load(filename1, &actual_field1[0][0], actual_size1);
		if(loadResult1) {
			std::cout << "The game state was saved loaded from the file: " << filename1 << std::endl;
		}
		else {
			std::cout << "Failed to loaded the game from into the file: " << filename1 << std::endl;
		}
		// Check 
		bool check_result1 = true;
		check_result1 &= (actual_size1 == size);
		for(int row = 0; row < size; ++row) {
			for(int col = 0; col < size; ++col) {
				check_result1 &= (static_cast<int>(actual_field1[row][col]) == field[row][col]);
				if(!check_result1) {
					std::cout << "Invalid value for row = " << row << " col = " << col << std::endl;
				}
			}
		}
		if(check_result1) {
			std::cout << "The game state is valid!" << std::endl;
		}
		else {
			std::cout << "The game state is invalid!" << std::endl;
		}

		return 0;
}