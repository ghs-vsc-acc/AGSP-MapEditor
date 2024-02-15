#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <nlohmann/json.hpp>
#include <string>

#include "consts.hpp" // adjust values within

struct Tile {
	// position within array
	int arr_x;
	int arr_y;

	// in-game position
	int x_pos;
	int y_pos;

	// color value (later to be texture path index)
	int t_col;
};

class TileMap {
	private:
		std::vector<std::vector<Tile>> tileVector;
		nlohmann::json m_jsonData;

	public:
		TileMap(std::string manifest_fp);

		nlohmann::json readMapData(std::string manifest_fp);
		std::vector<std::vector<Tile>> getTileVector();
		void draw(sf::RenderWindow& m_window_instance);
};
