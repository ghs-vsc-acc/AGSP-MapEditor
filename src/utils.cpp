#include "utils.hpp"

void debug_setPositionToTopLeftOnSpawn(sf::RenderWindow& m_window_obj) {
	m_window_obj.setPosition(sf::Vector2i(10, 10));
}

void debug_applicationQuickEscQuickExit(sf::Event t_event, sf::RenderWindow& m_window_obj) {
	if (t_event.type == sf::Event::KeyPressed && t_event.key.code == sf::Keyboard::Escape) {
		m_window_obj.close();
	}
}

void drawGUITemp() {
	// manually draw gui here... (since im too lazy and its too much effort to figure out linking and compiling a gui library (consider precompiling a library and then just linking the object files)
}
