#include "game.hpp"

#include "tileMap.hpp"
#include "utils.hpp"

#include <SFML/Window/Event.hpp>
#include <iostream>
#include <vector>


Game::Game(std::string tilemap_path) :
		m_tilemap(tilemap_path), m_window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "AGSP Interactive Map Editor Test...", sf::Style::Close) {
	std::cout << "[TEST]: Hello, World! This print is being executed from within the declaration of 'Game::Game'!" << std::endl;
}

int Game::run() {
	// DEBUG
	debug_setPositionToTopLeftOnSpawn(m_window);

	sf::VideoMode screenSize = sf::VideoMode::getDesktopMode();
	std::cout << "[SCREEN-SIZE-W]: " << screenSize.width << std::endl;
	std::cout << "[SCREEN-SIZE-H]: " << screenSize.height << std::endl;
	// =====

	std::cout << "[LOG]: Entering into main window loop." << std::endl;
	while (m_window.isOpen()) {
		handleEvents();
		update();
		render();
	}

	std::cout << "[LOG]: Application exiting..." << std::endl;
	return 0;
}

/*
*	TODO:
*		- figure out how tf i can reference the actual object and not just my shitty Tile struct
* 
void Game::handleInteractiveEvents(sf::Event t_event, sf::RenderWindow& m_window_obj, TileMap t_tilemapvar) {
	std::vector<std::vector<Tile>> t_tmapdata = t_tilemapvar.getTileVector();

	if (t_event.type == sf::Event::MouseButtonPressed) {
		if (t_event.mouseButton.button == sf::Mouse::Left) {
			sf::Vector2f t_mousePos = m_window_obj.mapPixelToCoords(sf::Mouse::getPosition(m_window_obj));
			for (int i = 0; i < TILE_SIZE; i++) {
				for (int k = 0; k < TILE_SIZE; k++) {
					if (t_tmapdata[i][k].getGlobalBounds().contains(t_mousePos)) {
						t_tmapdata[i][k].setFillColor(sf::Color::Black); // if is clicked, set color to black
					}
				}
			}
		}
	}
}
*/

void Game::handleEvents() {
	sf::Event event;
	while (m_window.pollEvent(event)) {
		// DEBUG
		debug_applicationQuickEscQuickExit(event, m_window);

		if (event.type == sf::Event::Closed) m_window.close();
		// TODO: uncomment when issues is solved (see description of issue above function definition)
		//handleInteractiveEvents(event, m_window, m_tilemap);
	}
}

void Game::update() {
	// update game logic here...
}

void Game::render() {
	// clear old frame
	m_window.clear();
	
	// render stuff...
	m_tilemap.draw(m_window);

	// render new frame
	m_window.display();
}

sf::RenderWindow& Game::getRenderWindow() {
	return m_window;
}
