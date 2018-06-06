#include "game.h"

#include <constants.h>
#include <bullet.h>

Game::Game()
	:
	running(false)
{}

void Game::init()
{
	createWindow();
}

Game::~Game()
{
	window.close();
}

void Game::run()
{
	running = true;

	sf::Clock clock;

	while (running) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				running = false;
			}
			onEvent(event);
		}

		window.clear();
		update(clock.restart().asMilliseconds());
		render(window);
		window.display();
	}
}

void Game::createWindow()
{
	if (window.isOpen()) {
		window.close();
	}

	window.create(sf::VideoMode(graphics::APP_WIDTH, graphics::APP_HEIGHT), game::GAME_NAME);
	window.setFramerateLimit(graphics::APP_FPS);
	window.setKeyRepeatEnabled(false);
}

void Game::update(float frameTime)
{
	if (shoot) {
		generateBullet();
		shoot = false;
	}

	ship.update(frameTime);

	updateBullets(frameTime);
}

void Game::render(sf::RenderTarget &target)
{
	target.draw(ship);

	for (auto it : bullets) {
		target.draw(it);
	}
}

void Game::onEvent(const sf::Event &event)
{
	ship.onEvent(event);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		shoot = true;
	}
}

void Game::updateBullets(float frameTime)
{
	auto it = bullets.begin();
	while (it != bullets.end()) {
		if (it->isExist() && it->isOnScreen()) {
			it->update(frameTime);
			++it;
		}
		else {
			it = bullets.erase(it);
		}
	}
}

void Game::generateBullet()
{
	Bullet bullet(ship.getPosition(), ship.getRotation());
	bullets.push_back(bullet);
}
