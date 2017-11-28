#pragma once

#pragma once

#include"GameObject.h"
#include<Math.h>

class Enemy : public GameObject
{
public:
	
	Enemy(const sf::Vector2f &size, const sf::Color &color, const sf::Vector2f &position);

	void update(std::vector<GameObject*>& gameObjects, const sf::Time& dt);
	void draw(sf::RenderWindow& window);
	const sf::Vector2f& getPosition() const;
	const float& getRotation() const;
	sf::FloatRect getBoundingBox() const;

private:
	sf::RectangleShape _rectShape;
	float _initialXPosition;
	double _elapsedTime = 0.0;

};