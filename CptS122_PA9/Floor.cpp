#include "Floor.h"

Floor::Floor(const sf::Vector2f& position, const float& width, const float& height)
	:_floorEntity(sf::Vector2f(width, height)) {
	_floorEntity.setPosition(position);
	_floorEntity.setFillColor(sf::Color::White);
}

void Floor::update(std::set<GameObject*>& gameObjects, const sf::Time& dt) {

}
void Floor::draw(sf::RenderWindow &window)
{
	window.draw(_floorEntity);
}
const sf::Vector2f& Floor::getPosition() const
{
	return _floorEntity.getPosition();
}
const float& Floor::getRotation() const
{
	return _floorEntity.getRotation();
}
sf::FloatRect Floor::getBoundingBox() const
{
	return _floorEntity.getGlobalBounds();
}