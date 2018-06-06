#include "asteroid.h"

#include "constants.h"

const float Asteroid::radius = 20.0f;

Asteroid::Asteroid()
	:
	GameObject()
{
	int angle = rand() % 360;
	direction = sf::Vector2f(cos(angle * math::DEG_TO_RAD), sin(angle * math::DEG_TO_RAD));

	sf::Vector2f position(rand() % graphics::APP_WIDTH, rand() % graphics::APP_HEIGHT);
	setPosition(position);
	shape.setPointCount(8);
	shape.setRadius(radius);
	shape.setFillColor(sf::Color::Black);
	shape.setOutlineColor(sf::Color::White);
	shape.setOutlineThickness(1);
	shape.setOrigin(radius, radius);
}

Asteroid::~Asteroid()
{}

void Asteroid::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(shape, states);
}

void Asteroid::update(float frameTime)
{
	if (!exist) {
		return;
	}

	sf::Vector2f distance = direction * speed * frameTime;
	move(distance);

	sf::Vector2f position = getPosition();

	if (position.x < -radius) {
		position.x = graphics::APP_WIDTH;
	}
	else if (position.x > graphics::APP_WIDTH) {
		position.x = 0.0f;
	}

	if (position.y < -radius) {
		position.y = graphics::APP_HEIGHT;
	}
	else if (position.y > graphics::APP_HEIGHT) {
		position.y = 0.0f;
	}

	setPosition(position);
}

bool Asteroid::collide(sf::Vector2f point)
{
	float ax = getPosition().x;
	float ay = getPosition().y;

	float px = point.x;
	float py = point.y;

	float sqrDistance = ((ax - px) * (ax - px)) + ((ay - py) * (ay - py));
	float sqrRadius = radius * radius;

	return (sqrDistance <= sqrRadius);
}

void Asteroid::explode()
{
	exist = false;
}
