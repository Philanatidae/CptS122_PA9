#include "ShootingEnemy.h"

/**
Constructor - Initializes _rectShape with color, position, and dimensions.
Initializes _shootTimer
*/
ShootingEnemy::ShootingEnemy(const sf::Color& color, const sf::Vector2f& position)
	: _rectShape(sf::Vector2f(SHOOTING_ENEMY_WIDTH, SHOOTING_ENEMY_HEIGHT)),
	_shootTimer(SHOOTING_ENEMY_SHOOT_PERIOD)
{
	_rectShape.setFillColor(color);
	_rectShape.setPosition(position);
}
/**
Update's position of _rectShape (physics through collisions with floor).
Allows ShootingEnemy to shoot a projectile when _shootTimer expires.
*/
void ShootingEnemy::update(std::set<GameObject*>& gameObjects, const sf::Time& dt)
{
	_shootTimer -= dt.asSeconds(); // update time until next shot

	// Shoot if _shootTimer expired (every second)
	if (_shootTimer <= 0) 
	{
		_shootTimer = SHOOTING_ENEMY_SHOOT_PERIOD; // reset shooting timer
		
		// shoot
		gameObjects.insert(new Projectile(SHOOTING_ENEMY_PROJECTILE_RADIUS, sf::Vector2f(getPosition().x, getPosition().y + 50), 
			-1.0f, Target(player)));
	}
	// Update Physics
	FallingPhysicsObject::update(gameObjects, dt);
}
/**
Draws _rectShape to window
*/
void ShootingEnemy::draw(sf::RenderWindow& window)
{
	window.draw(_rectShape);
}
/**
returns position of _rectShape
*/
const sf::Vector2f& ShootingEnemy::getPosition() const
{
	return _rectShape.getPosition();
}
/**
returns rotation of _rectShape
*/
const float& ShootingEnemy::getRotation() const
{
	return _rectShape.getRotation();
}
/**
returns bounding box of _rectShape for purposes of collision detection
*/
sf::FloatRect ShootingEnemy::getBoundingBox() const
{
	return _rectShape.getGlobalBounds();
}
/**
Moves the object an x-distance and y-distance.
@param dx Change in x position.
@param dy Change in y position.
*/
void ShootingEnemy::move(const float& dx, const float& dy) 
{
	_rectShape.move(dx, dy);
};
