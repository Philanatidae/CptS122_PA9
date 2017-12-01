#pragma once

#include "GameObject.h"
#include "Enemy.h"

#define PROJECTILE_HORIZONTAL_VELOCTIY 300

class Projectile : public GameObject
{
	public:
		Projectile(const float& radius, const sf::Vector2f& position);

		void update(std::set<GameObject*>& gameObjects, const sf::Time& dt);
		void draw(sf::RenderWindow& window);
		const sf::Vector2f& getPosition() const;
		const float& getRotation() const;
		sf::FloatRect getBoundingBox() const;

	private:
		sf::CircleShape _circleShape;

		void move(const float& dx, const float& dy);
};