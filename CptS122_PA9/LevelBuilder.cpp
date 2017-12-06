#include "LevelBuilder.h"

LevelBuilder::LevelBuilder(std::set<GameObject*>* const & gameObjectsPtr)
	:_gameObjectsPtr(gameObjectsPtr),_currPosition(0, 0) {

}

void LevelBuilder::drawHorizontal(const float& dx) {
	sf::Vector2f position = _currPosition;
	float ddx = dx;

	if (dx < 0) { // Left
		position.x += FLOOR_THICKNESS;
		ddx -= FLOOR_THICKNESS;
	}

	_gameObjectsPtr->insert(new Floor(position, ddx, FLOOR_THICKNESS));
	_currPosition.x += dx;
}
void LevelBuilder::drawVertical(const float& dy) {
	sf::Vector2f position = _currPosition;
	float ddy = dy;

	if (dy < 0) { // Up
		position.y += FLOOR_THICKNESS;
		ddy -= FLOOR_THICKNESS;
	}

	_gameObjectsPtr->insert(new Floor(position, FLOOR_THICKNESS, ddy));
	_currPosition.y += dy;
}
void LevelBuilder::move(const float& dx, const float& dy) {
	_currPosition.x += dx;
	_currPosition.y += dy;
}
void LevelBuilder::set(const float& x, const float& y) {
	_currPosition.x = x;
	_currPosition.y = y;
}

const sf::Vector2f& LevelBuilder::getPosition() const {
	return _currPosition;
}