#pragma once

#include <gamestate/gamestate.h>

namespace serialize {

	// Expects that size == width == height
	bool save(const char* filename, const gamestate::State* const state, int size);
	bool load(const char* filename, gamestate::State* const state, int& size);

} // namespace serialize
