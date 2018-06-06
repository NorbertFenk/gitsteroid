#pragma once

#include <cmath>

#include <SFML/Graphics.hpp>

class Ship: public sf::Drawable, public sf::Transformable
{
	static const float acceleration;
	static const float maxSpeed;
	static const float rotationSpeed;

public:
	Ship();
	~Ship();

	void update(float frameTime);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	void reset();
	void onEvent(const sf::Event &event);

private:
	sf::Vector2f speed;
	sf::ConvexShape shape;

	float rotationDirection;
	float moveDirection;
};


