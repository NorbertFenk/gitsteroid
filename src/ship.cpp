#include "ship.h"

#include "constants.h"
#include "util.h"

const float Ship::acceleration = 300.0f;

const float Ship::maxSpeed = 300.0f;

const float Ship::rotationSpeed = 180.0f;

Ship::Ship()
{
	shape.setPointCount(3);
	shape.setPoint(0, sf::Vector2f(10.0f, 0.0f));
	shape.setPoint(1, sf::Vector2f(-10.0f, 7.5f));
	shape.setPoint(2, sf::Vector2f(-10.0f, -7.5f));

	shape.setFillColor(sf::Color::Black);
	shape.setOutlineColor(sf::Color::White);
	shape.setOutlineThickness(1);
	shape.setPosition(0.0f, 0.0f);

	rotationDirection = 0;
	moveDirection = 0;

	reset();
}

Ship::~Ship()
{}

void Ship::update(float frameTime)
{
	frameTime /= 1000.0f;

	if (rotationDirection != 0) {
		rotate(rotationDirection * rotationSpeed * frameTime);
	}

	if (moveDirection != 0) {
		float rotation = getRotation();
		sf::Vector2f direction;
		direction.x = cos(rotation * math::DEG_TO_RAD);
		direction.y = sin(rotation * math::DEG_TO_RAD);

		speed += direction * frameTime * acceleration * moveDirection;

		if (util::length(speed) > maxSpeed) {
			speed = util::normalize(speed) * maxSpeed;
		}
	}
	move(speed * frameTime);

	sf::Vector2f position = getPosition();

	if (position.x < -10.0f) {
		position.x = graphics::APP_WIDTH;
	}
	else if (position.x > graphics::APP_WIDTH + 10.0f) {
		position.x = 0.0f;
	}

	if (position.y < -10.0f) {
		position.y = graphics::APP_HEIGHT;
	}
	else if (position.y > graphics::APP_HEIGHT + 10.0f) {
		position.y = 0.0f;
	}

	setPosition(position);
}

void Ship::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(shape, states);
}

void Ship::reset()
{
	setPosition(graphics::APP_HEIGHT / 2, graphics::APP_WIDTH / 2);
	setRotation(0.0f);
	speed.x = 0;
	speed.y = 0;
}

void Ship::onEvent(const sf::Event &event)
{
	rotationDirection = 0;
	moveDirection = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		moveDirection = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		moveDirection = -1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		rotationDirection = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		rotationDirection = -1;
	}
}
