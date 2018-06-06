#include "bullet.h"

#include "constants.h"

const float Bullet::speed = 0.9f;

const float Bullet::bulletLength = 20.0f;

Bullet::Bullet(sf::Vector2f position, float angle)
	:
	GameObject(),
	direction(cos(angle * math::DEG_TO_RAD), sin(angle * math::DEG_TO_RAD))
{
	setPosition(position);
}

Bullet::~Bullet()
{}

void Bullet::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	sf::Vertex line[] = {
		sf::Vertex(getPosition()),
		sf::Vertex(getPosition() + (direction * bulletLength))
	};
	target.draw(line, 2, sf::Lines, states);
}

void Bullet::update(float frametime)
{
	if (!exist) {
		return;
	}

	sf::Vector2f distance = direction * speed * frametime;
	move(distance);
}

void Bullet::impact()
{
	exist = false;
}

bool Bullet::isOnScreen()
{
	sf::Vector2f position = getPosition();

	if ((position.x > graphics::APP_WIDTH || position.x < 0) ||
		(position.y > graphics::APP_HEIGHT || position.y < 0)) {
		return false;
	}

	return true;
}
