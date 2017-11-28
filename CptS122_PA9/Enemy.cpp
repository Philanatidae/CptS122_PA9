#include"Enemy.h"

Enemy::Enemy(const sf::Vector2f& size, const sf::Color& color, const sf::Vector2f& position)
	:_rectShape(size), _initialXPosition(position.x)
{
	_rectShape.setFillColor(color);
	_rectShape.setPosition(position);
}
void Enemy::update(std::vector<GameObject*>& gameObjects, const sf::Time& dt)
{
	float yPosition = _rectShape.getPosition().y;

	_elapsedTime += dt.asSeconds();
	_rectShape.setPosition(100 * sin(_elapsedTime) + _initialXPosition, yPosition);
}
void Enemy::draw(sf::RenderWindow& window)
{
	window.draw(_rectShape);
}
const sf::Vector2f& Enemy::getPosition() const
{
	return _rectShape.getPosition();
}
const float& Enemy::getRotation() const
{
	return _rectShape.getRotation();
}
sf::FloatRect Enemy::getBoundingBox() const
{
	return _rectShape.getGlobalBounds();
}