#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <string>

#include "tileMap.hpp"

class Game {
	public:
		Game(std::string tilemap_path);
		int run();

		sf::RenderWindow& getRenderWindow();

	private:
		sf::RenderWindow m_window;
		TileMap m_tilemap;

		void handleEvents();
		void update();
		void render();

		//void handleInteractiveEvents(sf::Event t_event, sf::RenderWindow& m_window_obj, TileMap t_tilemapvar);
};
