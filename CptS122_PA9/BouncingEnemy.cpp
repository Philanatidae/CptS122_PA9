#include "BouncingEnemy.h"

BouncingEnemy::BouncingEnemy(const sf::Color& color, const sf::Vector2f& position)
	:_rectShape(sf::Vector2f(BOUNCING_ENEMY_WIDTH, BOUNCING_ENEMY_HEIGHT))
{
	_rectShape.setFillColor(color);
	_rectShape.setPosition(position);
}
void BouncingEnemy::update(std::set<GameObject*>& gameObjects, const sf::Time& dt)
{
	if (isGrounded()) {
		_bounceTime -= dt.asSeconds();
		if (_bounceTime <= 0) {
			bounce();
		}
	}
	else { // Airborne
		sf::Vector2f playerPosition = getPosition();
		for (std::set<GameObject*>::iterator iterator = gameObjects.begin();
			iterator != gameObjects.end();
			iterator++) {
			if (dynamic_cast<Player*>(*iterator)) {
				playerPosition = (*iterator)->getPosition();
				break;
			}
		}
		sf::Vector2f difference = playerPosition - getPosition();
		float xDir = difference.x / abs(difference.x);
		move(xDir * BOUNCING_ENEMY_TRACKING_X_VEL * dt.asSeconds(), 0);
	}

	// Update physics last
	FallingPhysicsObject::update(gameObjects, dt);
}
void BouncingEnemy::draw(sf::RenderWindow& window)
{
	window.draw(_rectShape);
}
const sf::Vector2f& BouncingEnemy::getPosition() const
{
	return _rectShape.getPosition();
}
const float& BouncingEnemy::getRotation() const
{
	return _rectShape.getRotation();
}
sf::FloatRect BouncingEnemy::getBoundingBox() const
{
	return _rectShape.getGlobalBounds();
}

void BouncingEnemy::move(const float& dx, const float& dy) {
	_rectShape.move(dx, dy);
}
void BouncingEnemy::bounce() {
	setYVelocity(BOUNCING_ENEMY_JUMP_VELOCITY);
	_bounceTime = BOUNCING_ENEMY_BOUNCE_PERIOD;
}