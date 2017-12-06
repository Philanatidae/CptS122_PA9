#pragma once

#include "Enemy.h"
#include "FallingPhysicsObject.h"
#include "Projectile.h"

#define SHOOTING_ENEMY_WIDTH 100.0f
#define SHOOTING_ENEMY_HEIGHT 100.0f
#define SHOOTING_ENEMY_PROJECTILE_RADIUS 25.0f

#define SHOOTING_ENEMY_SHOOT_PERIOD 1.5f

class ShootingEnemy : public Enemy, public FallingPhysicsObject
{
	public:
		ShootingEnemy(const sf::Color& color, const sf::Vector2f& position);

		void update(std::set<GameObject*>& gameObjects, const sf::Time& dt);
		void draw(sf::RenderWindow& window);
		const sf::Vector2f& getPosition() const;
		const float& getRotation() const;
		sf::FloatRect getBoundingBox() const;

	protected:
		void move(const float& dx, const float& dy);

	private:
		sf::RectangleShape _rectShape;
		float _shootTimer;
};
