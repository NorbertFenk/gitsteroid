#pragma once

#include <cmath>

#include <SFML/Graphics.hpp>

#include "gameobject.h"

class Ship: public GameObject
{
	static const float acceleration;
	static const float maxSpeed;
	static const float rotationSpeed;

public:
	Ship();
	~Ship() override;

	void update(float frameTime) override;
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

	void reset();
	void onEvent(const sf::Event &event);

private:
	sf::Vector2f speed;
	sf::ConvexShape shape;

	float rotationDirection;
	float moveDirection;
};


