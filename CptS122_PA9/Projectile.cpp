#include "Projectile.h"

/**
Constructor - sets radius, initial position, direction of motion, and
the target that the projectile will damage
*/
Projectile::Projectile(const float& radius, const sf::Vector2f& position, 
	const float& direction, const Target& target)
	: _circleShape(radius),_xVel(direction / abs(direction) * PROJECTILE_HORIZONTAL_VELOCTIY),
	_target(target)
{
	_circleShape.setFillColor(sf::Color::Green);
	_circleShape.setPosition(position);
}

/**
Updates position and member variables of Projectile
*/
void Projectile::update(std::set<GameObject*>& gameObjects, const sf::Time& dt)
{
	move(_xVel * dt.asSeconds(), 0);

	// Collision check
	const sf::FloatRect myBoundingBox = getBoundingBox();

	// Iterate through all existing gameObjects
	for (std::set<GameObject*>::iterator iterator = gameObjects.begin();
		iterator != gameObjects.end(); 
		iterator++)
	{
		GameObject *pGameObject = *iterator;

		// Check for collision with target
		bool isTarget = false;

		// Check if current gameObject is a target type of projectile
		switch (_target)
		{
			case player:
				isTarget = (dynamic_cast<Player*>(pGameObject) != nullptr);
				break;
			case enemy:
				isTarget = (dynamic_cast<Enemy*>(pGameObject) != nullptr);
				break;
		}
		if (isTarget)
		{
			// If projectile colliding with target, projectile and target object can be set toDelete
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
/**
Draws _circleShape member variable to window parameter
*/
void Projectile::draw(sf::RenderWindow& window)
{
	window.draw(_circleShape);
}
/**
returns reference to position of _circleShape member variable
*/
const sf::Vector2f& Projectile::getPosition() const
{
	return _circleShape.getPosition();
}
/**
returns rotation of _circleShape member variable, in degrees*/
const float& Projectile::getRotation() const
{
	return _circleShape.getRotation();
}
/**
returns bounding box of _circleShape for purposes of detecting collisions
*/
sf::FloatRect Projectile::getBoundingBox() const
{
	return _circleShape.getGlobalBounds();
}

/**
moves _circleShape member variable by dx in x-direction and dy in y-direction
*/
void Projectile::move(const float& dx, const float& dy)
{
	_circleShape.move(sf::Vector2f(dx, dy));
}