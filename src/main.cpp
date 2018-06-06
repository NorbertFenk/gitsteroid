#include <SFML/Graphics.hpp>

#include "ship.h"
#include "constants.h"

int main()
{
	Ship ship;
	sf::RenderWindow window(sf::VideoMode(graphics::APP_WIDTH, graphics::APP_HEIGHT), game::GAME_NAME);
	window.setFramerateLimit(graphics::APP_FPS);

	sf::Clock clock;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			ship.onEvent(event);
		}

		window.clear();
		ship.update(clock.restart().asMilliseconds());
		window.draw(ship);
		window.display();
	}

	return 0;
}
