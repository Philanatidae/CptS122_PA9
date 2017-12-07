#include "GoalGameObject.h"

/**
Constructs the goal object.
*/
GoalGameObject::GoalGameObject(const sf::Vector2f& position, const sf::Color& color)
	:_elapsedTime(0) {
	_goalEntity.setPosition(position);
	_goalEntity.setFillColor(color);
	_goalEntity.setSize(sf::Vector2f(75, 75));
}

/**
Updates the object.
@param gameObjects Global list of game objects.
@param dt Time since last frame (change in time since last frame).
*/
void GoalGameObject::update(std::set<GameObject*>& gameObjects, const sf::Time& dt) {
	_elapsedTime += dt.asSeconds();

	_goalEntity.move(0, 10 * cos(_elapsedTime) * dt.asSeconds());
}
/**
Draws the object to the window.
@param window SFML Window to draw to.
*/
void GoalGameObject::draw(sf::RenderWindow& window) {
	window.draw(_goalEntity);
}

/**
Returns the position of the object.
@return Position of the object.
*/
const sf::Vector2f& GoalGameObject::getPosition() const {
	return _goalEntity.getPosition();
}
/**
Returns the rotation of the object, in degrees.
@return Rotation of the object.
*/
const float& GoalGameObject::getRotation() const {
	return _goalEntity.getRotation();
}
/**
Returns the bounding box of the object for collision
detection.
@return Bounding box of the object.
*/
sf::FloatRect GoalGameObject::getBoundingBox() const {
	return _goalEntity.getGlobalBounds();
}