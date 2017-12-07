#include "SineEnemy.h"

/**
Constructs a sine enemy object.
@param size Size of the enemy.
@param color Color of the enemy.
@param position Position of the enemy.
*/
SineEnemy::SineEnemy(const sf::Vector2f& size, const sf::Color& color, const sf::Vector2f& position)
	:_rectShape(size)
{
	_rectShape.setFillColor(color);
	_rectShape.setPosition(position);
}
/**
Updates the object.
@param gameObjects Global list of game objects.
@param dt Time since last frame (change in time since last frame).
*/
void SineEnemy::update(std::set<GameObject*>& gameObjects, const sf::Time& dt)
{
	_elapsedTime += dt.asSeconds();
	// Move to sine wave (velocity, so we use the derivative of sin and integrate)
	move(100 * cos(_elapsedTime) * dt.asSeconds(), 0);

	// Update physics last
	FallingPhysicsObject::update(gameObjects, dt);
}
/**
Draws the object to the window.
@param window SFML Window to draw to.
*/
void SineEnemy::draw(sf::RenderWindow& window)
{
	window.draw(_rectShape);
}
/**
Returns the position of the object.
@return Position of the object.
*/
const sf::Vector2f& SineEnemy::getPosition() const
{
	return _rectShape.getPosition();
}
/**
Returns the rotation of the object, in degrees.
@return Rotation of the object.
*/
const float& SineEnemy::getRotation() const
{
	return _rectShape.getRotation();
}
/**
Returns the bounding box of the object for collision
detection.
@return Bounding box of the object.
*/
sf::FloatRect SineEnemy::getBoundingBox() const
{
	return _rectShape.getGlobalBounds();
}

/**
Moves the object an x-distance and y-distance.
@param dx Change in x position.
@param dy Change in y position.
*/
void SineEnemy::move(const float& dx, const float& dy) {
	_rectShape.move(dx, dy);
}