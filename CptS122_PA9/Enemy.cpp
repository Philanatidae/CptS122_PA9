#include"Enemy.h"

Enemy::Enemy(const sf::Vector2f& size, const sf::Color& color, const sf::Vector2f& position)
	:_rectShape(size)
{
	_rectShape.setFillColor(color);
	_rectShape.setPosition(position);
}
void Enemy::update(std::set<GameObject*>& gameObjects, const sf::Time& dt)
{
	_elapsedTime += dt.asSeconds();
	// Move to sine wave (velocity, so we use the derivative of sin and integrate)
	move(100 * cos(_elapsedTime) * dt.asSeconds(), 0);

	// Update physics last
	FallingPhysicsObject::update(gameObjects, dt);
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

void Enemy::move(const float& dx, const float& dy) {
	_rectShape.move(dx, dy);
}