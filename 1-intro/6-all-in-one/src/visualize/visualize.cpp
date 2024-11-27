#include "visualize.h"

#include <iostream>
#include <cassert>

namespace visualize {

	namespace {
		void print_line(int width) {
			for(int i = 0; i < (width + 1)*3 + 1; ++i)
				std::cout << '-';
			std::cout << std::endl;
		}

		char state_to_symbol(gamestate::State state) {
			switch(state) {
				case gamestate::State::Empty:
					return ' ';
				case gamestate::State::Ship:
					return 'o';
				case gamestate::State::Hit:
					return 'x';
				case gamestate::State::Unknown:
					return 'u';
			}
			assert(false);
			return ' ';
		}
	}

	// -------------
	// | o | x | x |
	// -------------
	// | u |   | u |
	// -------------
	// |   | o | o |
	// -------------
	// o - part of a ship
	// x - hitten part of a ship
	// u - unknown content
	//   - "empty" - empty field


	void draw_field(const gamestate::State* const field, int size) {
		for(int row = 0; row < size; ++row) {
			print_line(size);
			for(int col = 0; col < size+1; ++col) {
				gamestate::State state;
				gamestate::get_state(field, row, col, state);
				std::cout << "| " << state_to_symbol(state) << ' ';
			}
			std::cout << std::endl;
		}
		print_line(size);
	}

} // namespace visualize



static int test_main() {

	gamestate::State* player1_field = gamestate::get_player1_field();
	gamestate::State* player1_intel = gamestate::get_player1_intel();
	gamestate::State* player2_field = gamestate::get_player2_field();
	gamestate::State* player2_intel = gamestate::get_player2_intel();

	const int size = 3;
	int field[size][size] = {
		{1, 2, 2},
		{0, 3, 3},
		{0, 1, 1}
	};
	gamestate::set_field_size(size);

	gamestate::debug::fill(player1_field, &field[0][0], size);
	gamestate::debug::fill(player2_field, &field[0][0], size);

	std::cout << "Player1 field: " << std::endl;
	visualize::draw_field(player1_field, size);

	std::cout << "Player2 field: " << std::endl;
	visualize::draw_field(player2_field, size);

	return 0;
}
