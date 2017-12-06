#pragma once

#include "GameObject.h"
#include "FallingPhysicsObject.h"
#include "Projectile.h"
#include "Enemy.h"
#include "GoalGameObject.h"

#define PLAYER_HORIZONTAL_VELOCITY 200
#define PLAYER_JUMP_VELOCITY -450

#define PLAYER_WIDTH 50
#define PLAYER_HEIGHT 100

#define PLAYER_SHOT_TIMER_DURATION 0.2f

class Player : public FallingPhysicsObject
{
	public:
		Player(const sf::Vector2f& position);
		void update(std::set<GameObject*>& gameObjects, const sf::Time& dt);
		void draw(sf::RenderWindow& window);
		const sf::Vector2f& getPosition() const;
		const float& getRotation() const;
		sf::FloatRect getBoundingBox() const;

	protected:
		void move(const float& dx, const float& dy);

	private:
		sf::RectangleShape _rectShape;
		float _shotTimer;

		void jump();

};