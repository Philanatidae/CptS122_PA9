#pragma once

#include "PlatformPhysicsObject.h"

class Floor : public PlatformPhysicsObject {
public:
	Floor(const sf::Vector2f& position, const float& width, const float& height);
	void update(std::vector<GameObject*>& gameObjects, const sf::Time& dt);
	void draw(sf::RenderWindow& window);

	const sf::Vector2f& getPosition() const;
	const float& getRotation() const;
	sf::FloatRect getBoundingBox() const;

private:
	sf::RectangleShape _floorEntity;
};