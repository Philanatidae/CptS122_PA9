#pragma once

#include "GameObject.h"
#include "FallingPhysicsObject.h"

#define PLAYER_HORIZONTAL_VELOCITY 200

class Player : public FallingPhysicsObject
{
	public:
		Player();
		void update(std::vector<GameObject*>& gameObjects, const sf::Time& dt);
		void draw(sf::RenderWindow& window);
		const sf::Vector2f& getPosition() const;
		const float& getRotation() const;
		sf::FloatRect getBoundingBox() const;

	protected:
		void move(const float& dx, const float& dy);

	private:
		sf::RectangleShape _rectShape;

};