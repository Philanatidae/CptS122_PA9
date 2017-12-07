#include"Player.h"

/**
Constructor - Initializes _rectShape's position, color and dimensions
*/
Player::Player(const sf::Vector2f& position) 
	: _rectShape(sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT))
{
	_rectShape.setFillColor(sf::Color::Blue);
	_rectShape.setPosition(position);
}
/**
Updates rectShape's position and allows player to shoot a projectile.
Detects collisions with enemies and platforms in gameObjects set and updates
player accordingly
*/
void Player::update(std::set<GameObject*>& gameObjects, const sf::Time& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) //move right
	{
		move(PLAYER_HORIZONTAL_VELOCITY * dt.asSeconds(), 0.0f);
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) //move left
	{
		move(-PLAYER_HORIZONTAL_VELOCITY * dt.asSeconds(), 0.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { // Jump
		if (isGrounded()) {
			jump();
		}
	}

	_shotTimer -= dt.asSeconds();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { // Shoot left
		if (_shotTimer <= 0) {
			_shotTimer = PLAYER_SHOT_TIMER_DURATION;
			gameObjects.insert(new Projectile(10.0f, sf::Vector2f(getPosition().x - 10 * 2, getPosition().y + PLAYER_HEIGHT / 2), -1, Target(enemy)));
		}
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { // Shoot right
		if (_shotTimer <= 0) {
			_shotTimer = PLAYER_SHOT_TIMER_DURATION;
			gameObjects.insert(new Projectile(10.0f, sf::Vector2f(getPosition().x + PLAYER_WIDTH, getPosition().y + PLAYER_HEIGHT / 2), 1, Target(enemy)));
		}
	}
	else if(_shotTimer < 0){ // Reset timer to 0 if it becomes negative
		_shotTimer = 0;
	}

	// Enemy/Goal Collision Check
	for (std::set<GameObject*>::iterator iterator = gameObjects.begin();
		iterator != gameObjects.end();
		iterator++)
	{
		if (dynamic_cast<Enemy*>(*iterator) != nullptr) // current gameObject is an enemy
		{
			// Player Collided with enemy
			if (getBoundingBox().intersects((*iterator)->getBoundingBox())) 
			{
				_toDelete = true; // Player can be deleted
			}
		}
		if (dynamic_cast<GoalGameObject*>(*iterator) != nullptr) { // current gameObject is goal
			// Player Collided with goal
			if (getBoundingBox().intersects((*iterator)->getBoundingBox())) {
				(*iterator)->setToDelete(); // Goal can be removed
			}
		}
	}


	// Update physics after moving player
	FallingPhysicsObject::update(gameObjects, dt);
}
/**
Draws _rectShape to window
*/
void Player::draw(sf::RenderWindow &window)
{
	window.draw(_rectShape);
}
/**
returns position of _rectShape
*/
const sf::Vector2f& Player::getPosition() const
{
	return _rectShape.getPosition();
}
/**
returns rotation of _rectShape in degrees
*/
const float& Player::getRotation() const
{
	return _rectShape.getRotation();
}
/**
returns bounding box of _rectShape for purposes of detecting collisions
*/
sf::FloatRect Player::getBoundingBox() const
{
	return _rectShape.getGlobalBounds();
}
/**
Changes _rectShape's position by dx in x-direct, and dy in y-direct
*/
void Player::move(const float& dx, const float& dy) {
	_rectShape.move(dx, dy);
}

/**
Causes the player to jump.
*/
void Player::jump() {
	setYVelocity(PLAYER_JUMP_VELOCITY);
}