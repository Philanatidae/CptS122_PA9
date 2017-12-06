#include "GoalGameObject.h"

GoalGameObject::GoalGameObject(const sf::Vector2f& position, const sf::Color& color)
	:_elapsedTime(0) {
	_goalEntity.setPosition(position);
	_goalEntity.setFillColor(color);
	_goalEntity.setSize(sf::Vector2f(75, 75));
}

void GoalGameObject::update(std::set<GameObject*>& gameObjects, const sf::Time& dt) {
	_elapsedTime += dt.asSeconds();

	_goalEntity.move(0, 10 * cos(_elapsedTime) * dt.asSeconds());
}
void GoalGameObject::draw(sf::RenderWindow& window) {
	window.draw(_goalEntity);
}

const sf::Vector2f& GoalGameObject::getPosition() const {
	return _goalEntity.getPosition();
}
const float& GoalGameObject::getRotation() const {
	return _goalEntity.getRotation();
}
sf::FloatRect GoalGameObject::getBoundingBox() const {
	return _goalEntity.getGlobalBounds();
}