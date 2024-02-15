#include <iostream>
#include "game.hpp"

int main(void) {
	std::cout << "[LOG]: Application begin..." << std::endl;
	Game g_instance("C:/Users/aaronbergmann_glouce/Documents/AGSP/Debug/generated_data.json");

	return g_instance.run();
}
