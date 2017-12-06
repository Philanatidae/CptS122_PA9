#pragma once

#include "GameObject.h"

#include <SFML/Graphics.hpp>
#include <math.h>

class GoalGameObject : public GameObject {
public:
	GoalGameObject(const sf::Vector2f& position, const sf::Color& color = sf::Color::Green);

	void update(std::set<GameObject*>& gameObjects, const sf::Time& dt);
	void draw(sf::RenderWindow& window);

	const sf::Vector2f& getPosition() const;
	const float& getRotation() const;
	sf::FloatRect getBoundingBox() const;

private:
	sf::RectangleShape _goalEntity;
	float _elapsedTime;
};