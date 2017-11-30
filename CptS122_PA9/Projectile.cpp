#include"Projectile.h"

Projectile::Projectile(const float& radius, const sf::Vector2f& position)
	: _circleShape(radius)
{
	_circleShape.setFillColor(sf::Color::Green);
	_circleShape.setPosition(position);
}

void Projectile::update(std::set<GameObject*>& gameObjects, const sf::Time& dt)
{
	move(PROJECTILE_HORIZONTAL_VELOCTIY * dt.asSeconds(), 0);

	//Enemy Collision check
	const sf::FloatRect myBoundingBox = getBoundingBox();

	for (std::set<GameObject*>::iterator iterator = gameObjects.begin();
		iterator != gameObjects.end(); 
		iterator++)
	{
		GameObject *pGameObject = *iterator;

		//Projectile can only collide with Enemy
		Enemy *pEnemy = dynamic_cast<Enemy*>(pGameObject);

		if (pEnemy == nullptr)
			continue;

		//If colliding with enemy, destroy enemy and projectile
		if (pEnemy->getBoundingBox().intersects(getBoundingBox()))
		{
			//unfinished, not sure how we wanna handle deleting GameObjects
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