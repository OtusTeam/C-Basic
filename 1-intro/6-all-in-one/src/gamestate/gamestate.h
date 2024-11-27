#pragma once 

#include <cstdint>

namespace gamestate {

	enum class State {
		Empty   = 0,
		Ship    = 1,
		Hit     = 2,
		Unknown = 3
	};

	static const int MaxSize  = 10;

	extern int size;

	extern State player1_field[MaxSize][MaxSize];
	extern State player1_intel[MaxSize][MaxSize];

	extern State player2_field[MaxSize][MaxSize];
	extern State player2_intel[MaxSize][MaxSize];

	State* get_player1_field();
	State* get_player1_intel();
	State* get_player2_field();
	State* get_player2_intel();

	int get_field_size();
	void set_field_size(int new_size);

	bool get_state(const State* const field, int row, int col, State& out);
	bool set_state(State* field, int row, int col, State state);

	void clear_state(State* field);
	
	namespace debug {

		void fill(State* field, int*array, int size);

	} // namespace debug

} // namespace gamestate