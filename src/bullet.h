#pragma once

#include "gameobject.h"

class Bullet: public GameObject
{
	static const float speed;
	static const float bulletLength;

public:
	Bullet(sf::Vector2f position, float angle);
	~Bullet() override;

	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	void update(float frameTime) override;

	bool isOnScreen();
	void impact();

private:
	sf::Vector2f direction;
};
