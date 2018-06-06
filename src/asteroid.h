#pragma once

#include "gameobject.h"

class Asteroid: public GameObject
{
	static const float radius;

public:
	Asteroid();
	~Asteroid() override;

	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	void update(float frameTime) override;

	bool collide(sf::Vector2f pos);
	void explode();

private:
	sf::CircleShape shape;
	sf::Vector2f direction;
	float speed = 0.03f;
};
