#include "gamestate.h"

namespace gamestate {

	int size = MaxSize;

	State player1_field[MaxSize][MaxSize] = {};
	State player1_intel[MaxSize][MaxSize] = {};

	State player2_field[MaxSize][MaxSize] = {};
	State player2_intel[MaxSize][MaxSize] = {};


	State* get_player1_field() { return &player1_field[0][0]; }
	State* get_player1_intel() { return &player1_intel[0][0]; }
	State* get_player2_field() { return &player2_field[0][0]; }
	State* get_player2_intel() { return &player2_intel[0][0]; }

	int get_field_size() { return size; }

	void set_field_size(int new_size) { size = new_size; }

	bool get_state(const State* const field, int row, int col, State& out) {
		if((row >= MaxSize) || (col >= MaxSize)) {
			return false;
		}
		out = field[row*MaxSize + col];
		return true;
	}

	bool set_state(State* field, int row, int col, State state) {
		if((row >= MaxSize) || (col >= MaxSize)) {
			return false;
		}
		field[row*MaxSize + col] = state;
		return true;
	}

	void debug::fill(State* field, int*array, int size) {
		for(int row = 0; row < size; ++row) {
			for(int col = 0; col < size; ++col) {
				State state = static_cast<State>(array[col + row*size]);
				if(!set_state(field, row, col, state)) {
					return;
				}
			}
		}
	}

} // namespace gamestate
