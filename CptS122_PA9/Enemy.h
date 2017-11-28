#pragma once

#pragma once

#include "FallingPhysicsObject.h"
#include<Math.h>

class Enemy : public FallingPhysicsObject
{
public:
	
	Enemy(const sf::Vector2f &size, const sf::Color &color, const sf::Vector2f &position);

	void update(std::set<GameObject*>& gameObjects, const sf::Time& dt);
	void draw(sf::RenderWindow& window);
	const sf::Vector2f& getPosition() const;
	const float& getRotation() const;
	sf::FloatRect getBoundingBox() const;

protected:
	void move(const float& dx, const float& dy);

private:
	sf::RectangleShape _rectShape;
	double _elapsedTime = 0.0;

};