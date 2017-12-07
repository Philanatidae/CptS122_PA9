#include "ShootingEnemy.h"

ShootingEnemy::ShootingEnemy(const sf::Color& color, const sf::Vector2f& position)
	: _rectShape(sf::Vector2f(SHOOTING_ENEMY_WIDTH, SHOOTING_ENEMY_HEIGHT)),
	_shootTimer(SHOOTING_ENEMY_SHOOT_PERIOD)
{
	_rectShape.setFillColor(color);
	_rectShape.setPosition(position);
}
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
void ShootingEnemy::draw(sf::RenderWindow& window)
{
	window.draw(_rectShape);
}
const sf::Vector2f& ShootingEnemy::getPosition() const
{
	return _rectShape.getPosition();
}
const float& ShootingEnemy::getRotation() const
{
	return _rectShape.getRotation();
}
sf::FloatRect ShootingEnemy::getBoundingBox() const
{
	return _rectShape.getGlobalBounds();
}
void ShootingEnemy::move(const float& dx, const float& dy) 
{
	_rectShape.move(dx, dy);
};
