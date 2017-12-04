#include"Projectile.h"

Projectile::Projectile(const float& radius, const sf::Vector2f& position, const float& direction)
	: _circleShape(radius),_xVel(direction / abs(direction) * PROJECTILE_HORIZONTAL_VELOCTIY)
{
	_circleShape.setFillColor(sf::Color::Green);
	_circleShape.setPosition(position);
}

void Projectile::update(std::set<GameObject*>& gameObjects, const sf::Time& dt)
{
	move(_xVel * dt.asSeconds(), 0);

	//Enemy Collision check
	const sf::FloatRect myBoundingBox = getBoundingBox();

	for (std::set<GameObject*>::iterator iterator = gameObjects.begin();
		iterator != gameObjects.end(); 
		iterator++)
	{
		GameObject *pGameObject = *iterator;

		// Projectile can collide with Enemy
		if (dynamic_cast<Enemy*>(pGameObject) != nullptr) {
			//If colliding with enemy, projectile and enemy can be set toDelete
			if (pGameObject->getBoundingBox().intersects(getBoundingBox()))
			{
				_toDelete = true;
				pGameObject->setToDelete();
			}
		}
		// Delete projectile if it has hit the floor
		if (dynamic_cast<Floor*>(pGameObject) != nullptr) {
			//If colliding with floor, projectile only is set toDelete
			if (pGameObject->getBoundingBox().intersects(getBoundingBox()))
			{
				_toDelete = true;
			}
		}
	}

}
void Projectile::draw(sf::RenderWindow& window)
{
	window.draw(_circleShape);
}
const sf::Vector2f& Projectile::getPosition() const
{
	return _circleShape.getPosition();
}
const float& Projectile::getRotation() const
{
	return _circleShape.getRotation();
}
sf::FloatRect Projectile::getBoundingBox() const
{
	return _circleShape.getGlobalBounds();
}

void Projectile::move(const float& dx, const float& dy)
{
	_circleShape.move(sf::Vector2f(dx, dy));
}