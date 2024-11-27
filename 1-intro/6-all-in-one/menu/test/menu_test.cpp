#include <menu.h>

#include <iostream>

int main() {

	int fake = 0;
	menu::MainSection main_section;
	do {
		main_section = menu::main();
		std::cout << "Section: " << static_cast<int>(main_section) << std::endl;

		switch(main_section) {
			case menu::MainSection::LoadGame: {
				std::string result_filename = menu::folder_path();
				std::cout << "result_filename = " << result_filename;
				break;
			}
			case menu::MainSection::NewGame: {
				menu::NewGameSection new_game_section;
				do {
					new_game_section = menu::new_game();
					std::cout << "new game section = " << static_cast<int>(new_game_section) << std::endl;

					if(new_game_section == menu::NewGameSection::ManualDeploy) {
						menu::CoordinatesSection coordinates_section;
						do {
							int x, y;
							coordinates_section = menu::coordinates(3, x, y);
							std::cout << "x = " << x << " y = " << y << std::endl;
						} while(coordinates_section != menu::CoordinatesSection::Back);
					}

				} while(new_game_section != menu::NewGameSection::Back);
			}
			case menu::MainSection::Quit:
				break;
		}
	} while(main_section != menu::MainSection::Quit);

	return 0;
}