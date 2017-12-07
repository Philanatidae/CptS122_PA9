#include "Floor.h"

/**
Constructs a floor object.
@param position Position of the floor.
@param width Width of the floor.
@param height Height of the floor.
*/
Floor::Floor(const sf::Vector2f& position, const float& width, const float& height)
	:_floorEntity(sf::Vector2f(width, height)) {
	_floorEntity.setPosition(position);
	_floorEntity.setFillColor(sf::Color::White);
}

/**
Updates the object.
@param gameObjects Global list of game objects.
@param dt Time since last frame (change in time since last frame).
*/
void Floor::update(std::set<GameObject*>& gameObjects, const sf::Time& dt) {

}
/**
Draws the object to the window.
@param window SFML Window to draw to.
*/
void Floor::draw(sf::RenderWindow &window)
{
	window.draw(_floorEntity);
}
/**
Returns the position of the object.
@return Position of the object.
*/
const sf::Vector2f& Floor::getPosition() const
{
	return _floorEntity.getPosition();
}
/**
Returns the rotation of the object, in degrees.
@return Rotation of the object.
*/
const float& Floor::getRotation() const
{
	return _floorEntity.getRotation();
}
/**
Returns the bounding box of the object for collision
detection.
@return Bounding box of the object.
*/
sf::FloatRect Floor::getBoundingBox() const
{
	return _floorEntity.getGlobalBounds();
}