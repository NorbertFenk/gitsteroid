#include "gameobject.h"

GameObject::GameObject()
	:
	exist(true)
{}

bool GameObject::isExist() const
{
	return exist;
}
