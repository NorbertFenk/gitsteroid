#pragma once

#include <math.h>

#include <SFML/Graphics.hpp>

class GameObject: public sf::Drawable, public sf::Transformable
{
public:
	GameObject();
	virtual ~GameObject() = default;
	virtual void update(float frameTime) = 0;
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;

	bool isExist() const;

protected:
	bool exist;
};
