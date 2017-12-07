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
		/**
		Constructor - Initializes _rectShape's position, color and dimensions
		*/
		Player(const sf::Vector2f& position);

		/**
		Updates rectShape's position and allows player to shoot a projectile.
		Detects collisions with enemies and platforms in gameObjects set and updates 
		player accordingly
		*/
		void update(std::set<GameObject*>& gameObjects, const sf::Time& dt);
		/**
		Draws _rectShape to window
		*/
		void draw(sf::RenderWindow& window);
		/**
		returns position of _rectShape
		*/
		const sf::Vector2f& getPosition() const;
		/**
		returns rotation of _rectShape in degrees
		*/
		const float& getRotation() const;
		/**
		returns bounding box of _rectShape for purposes of detecting collisions
		*/
		sf::FloatRect getBoundingBox() const;

	protected:
		/**
		Changes _rectShape's position by dx in x-direct, and dy in y-direct
		*/
		void move(const float& dx, const float& dy);

	private:
		sf::RectangleShape _rectShape;
		float _shotTimer;

		void jump();

};