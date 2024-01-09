#include <SFML/Graphics.hpp>
#include "consts.hpp"

int main(int argc, char *argv[]) {
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "AGSP-MapEditor++", sf::Style::Close);

    // example shape
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            }
        }

        // clear frame
        window.clear();

        // draw/update stuff
        window.draw(shape);

        // render new frame
        window.display();
    }

    return 0;
}
