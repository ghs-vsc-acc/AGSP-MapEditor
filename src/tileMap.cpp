#include "tileMap.hpp"
#include "consts.hpp"

#include <SFML/Graphics/RectangleShape.hpp>

#include <fstream>
#include <iostream>

TileMap::TileMap(std::string manifest_fp)
		: tileVector(GRID_SIZE, std::vector<Tile>(GRID_SIZE)),
			 m_jsonData(readMapData(manifest_fp)) {
	// check map data and texture dictionary exists
	if (m_jsonData.find("map") != m_jsonData.end() && m_jsonData.find("textureDict") != m_jsonData.end()) {
		auto& mapData = m_jsonData["map"];
		auto& textureDict = m_jsonData["textureDict"];

		// check tiles exist
		if (mapData.find("tiles") != mapData.end()) {
			auto& tilesData = mapData["tiles"];

			// for each tile assign respective data
			//	   -> once complete push to main vector
			for (auto& tile : tilesData.items()) {
				Tile t_tile;

				// set position within array
				t_tile.arr_x = tile.value()["arr_x"];
				t_tile.arr_y = tile.value()["arr_y"];

				// set ingame position
				t_tile.x_pos = tile.value()["x_pos"];
				t_tile.y_pos = tile.value()["y_pos"];

				// set tile color (soon to be texture index)
				t_tile.t_col = tile.value()["t_col"];

				// push to main vector
				tileVector[t_tile.arr_x][t_tile.arr_y] = t_tile;
			}
		} else std::cerr << "[ERR]: 'tiles' not found in manifest (will not load game)" << std::endl;
	} else std::cerr << "[ERR]: 'map' not found in manifest (will not load game)" << std::endl;
}

// TODO:
//    account for:
//       - if cant read file, return should be like some specific json data
//       - check to see if that data is there, if it is, we fucked up, if not
//         all good, continue with program execution
nlohmann::json TileMap::readMapData(std::string manifest_fp) {
	std::ifstream t_file(manifest_fp);
	if (!t_file.is_open()) {
		std::cerr << "[ERR]: Failed to open manifest... (will not load game)" << std::endl;
	}

	nlohmann::json jsonData;
	t_file >> jsonData;

	return jsonData;
}

std::vector<std::vector<Tile>> TileMap::getTileVector() {
	return tileVector;
}

void TileMap::draw(sf::RenderWindow& m_window_obj) {
	nlohmann::json t_jsonData = m_jsonData["map"]["tiles"];

	int t_index = 0;
	for (int k = 0; k < GRID_SIZE; k++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			sf::RectangleShape t_tile(sf::Vector2f((float)TILE_SIZE, (float)TILE_SIZE));      // declare new tile

			t_tile.setPosition((float)tileVector[k][j].x_pos, (float)tileVector[k][j].y_pos); // set new tile position
			// set texture/color here......

			// set color (soon to be texture) ======
			nlohmann::json t_textureDict = m_jsonData["textureDict"];
			int t_col = tileVector[k][j].t_col;
			std::string tileColStr = t_textureDict[std::to_string(t_col)];

			if (tileColStr == "red") t_tile.setFillColor(sf::Color::Red);
			else if (tileColStr == "green") t_tile.setFillColor(sf::Color::Green);
			else if (tileColStr == "blue") t_tile.setFillColor(sf::Color::Blue);
			// =====================================

			// draw to screen
			m_window_obj.draw(t_tile);
		}
	}
}
