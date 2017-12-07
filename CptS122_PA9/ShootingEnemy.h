#pragma once

#include "Enemy.h"
#include "FallingPhysicsObject.h"
#include "Projectile.h"

#define SHOOTING_ENEMY_WIDTH 100.0f
#define SHOOTING_ENEMY_HEIGHT 100.0f

#define SHOOTING_ENEMY_PROJECTILE_RADIUS 25.0f
#define SHOOTING_ENEMY_SHOOT_PERIOD 1.5f

/**
An enemy game object that shoots projectiles at the player.
*/
class ShootingEnemy : public Enemy, public FallingPhysicsObject
{
	public:
		/**
		Constructor - Initializes _rectShape with color, position, and dimensions.
		Initializes _shootTimer
		*/
		ShootingEnemy(const sf::Color& color, const sf::Vector2f& position);

		/**
		Update's position of _rectShape (physics through collisions with floor).
		Allows ShootingEnemy to shoot a projectile when _shootTimer expires.
		@param gameObjects Global list of game objects.
		@param dt Time since last frame (change in time since last frame).
		*/
		void update(std::set<GameObject*>& gameObjects, const sf::Time& dt);
		/**
		Draws _rectShape to window
		@param window SFML Window to draw to.
		*/
		void draw(sf::RenderWindow& window);
		/**
		@return position of _rectShape
		*/
		const sf::Vector2f& getPosition() const;
		/**
		@return rotation of _rectShape
		*/
		const float& getRotation() const;
		/**
		@return bounding box of _rectShape for purposes of collision detection
		*/
		sf::FloatRect getBoundingBox() const;

	protected:
		/**
		Moves the object an x-distance and y-distance.
		@param dx Change in x position.
		@param dy Change in y position.
		*/
		void move(const float& dx, const float& dy);

	private:
		sf::RectangleShape _rectShape;
		float _shootTimer;
};
