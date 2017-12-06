#include"Player.h"

Player::Player(const sf::Vector2f& position) 
	: _rectShape(sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT))
{
	_rectShape.setFillColor(sf::Color::Blue);
	_rectShape.setPosition(position);
}
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
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { // Shoot left
		if (_shotTimer <= 0) {
			_shotTimer = PLAYER_SHOT_TIMER_DURATION;
			gameObjects.insert(new Projectile(10.0f, sf::Vector2f(getPosition().x + PLAYER_WIDTH, getPosition().y + PLAYER_HEIGHT / 2), 1, Target(enemy)));
		}
	}
	else {
		_shotTimer = 0;
	}

	// Enemy/Goal Collision Check
	for (std::set<GameObject*>::iterator iterator = gameObjects.begin();
		iterator != gameObjects.end();
		iterator++)
	{
		if (dynamic_cast<Enemy*>(*iterator) != nullptr)
		{
			// Player Collided with enemy
			if (getBoundingBox().intersects((*iterator)->getBoundingBox())) 
			{
				_toDelete = true;
			}
		}
		if (dynamic_cast<GoalGameObject*>(*iterator) != nullptr) {
			// Player Collided with goal
			if (getBoundingBox().intersects((*iterator)->getBoundingBox())) {
				(*iterator)->setToDelete();
			}
		}
	}


	// Update physics after moving player
	FallingPhysicsObject::update(gameObjects, dt);
}
void Player::draw(sf::RenderWindow &window)
{
	window.draw(_rectShape);
}
const sf::Vector2f& Player::getPosition() const
{
	return _rectShape.getPosition();
}
const float& Player::getRotation() const
{
	return _rectShape.getRotation();
}
sf::FloatRect Player::getBoundingBox() const
{
	return _rectShape.getGlobalBounds();
}
void Player::move(const float& dx, const float& dy) {
	_rectShape.move(dx, dy);
}

void Player::jump() {
	setYVelocity(PLAYER_JUMP_VELOCITY);
}