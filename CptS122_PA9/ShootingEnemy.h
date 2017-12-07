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
		Constructs the ShootingEnemy class.
		*/
		ShootingEnemy(const sf::Color& color, const sf::Vector2f& position);

		/**
		Updates the object.
		@param gameObjects Global list of game objects.
		@param dt Time since last frame (change in time since last frame).
		*/
		void update(std::set<GameObject*>& gameObjects, const sf::Time& dt);
		/**
		Draws the object to the window.
		@param window SFML Window to draw to.
		*/
		void draw(sf::RenderWindow& window);
		/**
		Returns the position of the object.
		@return Position of the object.
		*/
		const sf::Vector2f& getPosition() const;
		/**
		Returns the rotation of the object, in degrees.
		@return Rotation of the object.
		*/
		const float& getRotation() const;
		/**
		Returns the bounding box of the object for collision
		detection.
		@return Bounding box of the object.
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
