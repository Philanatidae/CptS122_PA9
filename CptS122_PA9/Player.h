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

/**
A class for the player object.
*/
class Player : public FallingPhysicsObject
{
	public:
		/**
		Constructs a new player object.
		@param position Position of player.
		*/
		Player(const sf::Vector2f& position);
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
		float _shotTimer;

		/**
		Causes the player to jump.
		*/
		void jump();

};