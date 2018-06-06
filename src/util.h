#pragma once

#include <cmath>

#include <SFML/System/Vector2.hpp>

namespace util
{

float length(const sf::Vector2f &source)
{
	return sqrt((source.x * source.x) + (source.y * source.y));
}

sf::Vector2f normalize(const sf::Vector2f &source)
{
	float len = length(source);
	if (len != 0) {
		return source / len;
	}
	else {
		return source;
	}
}

}
