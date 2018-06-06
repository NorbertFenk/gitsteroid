#include "game.h"

#include "constants.h"
#include "bullet.h"

Game::Game()
	:
	running(false)
{}

void Game::init()
{
	for (int i = 0; i < game::NUM_OF_ASTEROIDS; ++i) {
		Asteroid a;
		asteroids.push_back(a);
	}

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

	updateAsteroids(frameTime);
	updateBullets(frameTime);
}

void Game::render(sf::RenderTarget &target)
{
	for (auto it : asteroids) {
		target.draw(it);
	}

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

void Game::updateAsteroids(float frameTime)
{
	auto asteroidIt = asteroids.begin();
	while (asteroidIt != asteroids.end()) {
		if (asteroidIt->isExist()) {
			asteroidIt->update(frameTime);
			++asteroidIt;
		}
		else {
			asteroidIt = asteroids.erase(asteroidIt);
		}
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
