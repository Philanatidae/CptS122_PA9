#include"Player.h"

Player::Player() 
	: _rectShape(sf::Vector2f(50.0f, 100.0f))
{
	_rectShape.setFillColor(sf::Color::Blue);
	_rectShape.setPosition(sf::Vector2f(400.0f, 400.0f));
}
void Player::update(std::vector<GameObject*>& gameObjects, const sf::Time& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) //move right
	{
		move(PLAYER_HORIZONTAL_VELOCITY * dt.asSeconds(), 0.0f);
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) //move left
	{
		move(-PLAYER_HORIZONTAL_VELOCITY * dt.asSeconds(), 0.0f);
	}
	
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
