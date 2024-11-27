#pragma once 

#include <string>

// ┌───────┐       ┌─────────┐
// │ Begin ├──────►│MainMenu │
// └───────┘       └───┬─────┘
//                     │
//                     │ ┌─────────┐
//                     ├─► LoadGame│
//                     │ └─────────┘       ┌────────────┐
//                     │                 ┌─►ManualDeploy│
//                     │                 │ └────────────┘
//                     │ ┌─────────┐     │ ┌────────────┐
//                     ├─► NewGame ├─────┼──►AutoDeploy │
//                     │ └─────────┘     │ └────────────┘
//                     │                 │ 
//                     │ ┌─────────┐     │ ┌───────────┐
//                     └─► Quit    │     └─► Back      │
//                       └─────────┘       └───────────┘
//


namespace menu {

	enum class MainSection {
		NewGame  = 1,
		LoadGame = 2,
		SaveGame = 3,
		Quit     = 4
	};
	MainSection main();

	std::string folder_path();

	enum class NewGameSection {
		ManualDeploy = 1,
		AutoDeploy = 2,
		Back = 3
	};
	NewGameSection new_game();

	enum class CoordinatesSection {
		Next = 1,
		Back = 2
	};

	CoordinatesSection coordinates(int size, int& x, int& y);

} // menu
