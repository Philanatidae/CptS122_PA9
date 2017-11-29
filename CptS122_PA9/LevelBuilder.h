#pragma once

#include <set>
#include "GameObject.h"
#include "Floor.h"

#define FLOOR_THICKNESS 20

class LevelBuilder {
public:
	LevelBuilder(std::set<GameObject*>* const & gameObjectsPtr);

	void drawHorizontal(const float& dx);
	void drawVertical(const float& dy);
	void move(const float& dx, const float& dy);
	void set(const float& x, const float& y);

private:
	std::set<GameObject*>* const _gameObjectsPtr;
	sf::Vector2f _currPosition;
};