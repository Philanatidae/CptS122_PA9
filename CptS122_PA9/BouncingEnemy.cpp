#include "BouncingEnemy.h"

/**
Constructs a bouncing enemy.
@param color Color of enemy.
@param position Position of enemy.
*/
BouncingEnemy::BouncingEnemy(const sf::Color& color, const sf::Vector2f& position)
	:_rectShape(sf::Vector2f(BOUNCING_ENEMY_WIDTH, BOUNCING_ENEMY_HEIGHT))
{
	_rectShape.setFillColor(color);
	_rectShape.setPosition(position);
}
/**
Updates the object.
@param gameObjects Global list of game objects.
@param dt Time since last frame (change in time since last frame).
*/
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
/**
Draws the object to the window.
@param window SFML Window to draw to.
*/
void BouncingEnemy::draw(sf::RenderWindow& window)
{
	window.draw(_rectShape);
}
/**
Returns the position of the object.
@return Position of the object.
*/
const sf::Vector2f& BouncingEnemy::getPosition() const
{
	return _rectShape.getPosition();
}
/**
Returns the rotation of the object, in degrees.
@return Rotation of the object.
*/
const float& BouncingEnemy::getRotation() const
{
	return _rectShape.getRotation();
}
/**
Returns the bounding box of the object for collision
detection.
@return Bounding box of the object.
*/
sf::FloatRect BouncingEnemy::getBoundingBox() const
{
	return _rectShape.getGlobalBounds();
}

/**
Moves the object an x-distance and y-distance.
@param dx Change in x position.
@param dy Change in y position.
*/
void BouncingEnemy::move(const float& dx, const float& dy) {
	_rectShape.move(dx, dy);
}
/**
Bounces the enemy.
*/
void BouncingEnemy::bounce() {
	setYVelocity(BOUNCING_ENEMY_JUMP_VELOCITY);
	_bounceTime = BOUNCING_ENEMY_BOUNCE_PERIOD;
}