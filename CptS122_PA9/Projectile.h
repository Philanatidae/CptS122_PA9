#pragma once

#include "GameObject.h"
#include "Enemy.h"
#include "Player.h"
#include "Floor.h"
#include "Target.h"

#define PROJECTILE_HORIZONTAL_VELOCTIY 300

class Projectile : public GameObject
{
	public:
		/**
		Constructor - sets radius, initial position, direction of motion, and 
		the target that the projectile will damage
		*/
		Projectile(const float& radius, const sf::Vector2f& position, const float& direction, 
			const Target& target);

		/**
		Updates position and member variables of Projectile
		@param gameObjects Global list of game objects.
		@param dt Time since last frame (change in time since last frame).
		*/
		void update(std::set<GameObject*>& gameObjects, const sf::Time& dt);
		/**
		Draws _circleShape member variable to window parameter.
		@param window SFML Window to draw to.
		*/
		void draw(sf::RenderWindow& window);
		/**
		@return Position of _circleShape member variable
		*/
		const sf::Vector2f& getPosition() const;
		/**
		@return Rotation of _circleShape member variable, in degrees.
		*/
		const float& getRotation() const;
		/**
		@return Bounding box of _circleShape for purposes of detecting collisions.
		*/
		sf::FloatRect getBoundingBox() const;

	private:
		sf::CircleShape _circleShape;
		float _xVel; // stores x-direcrion velocity of projectile
		Target _target; // stores the type of object the projectile can damage

		/**
		moves _circleShape member variable by dx in x-direction and dy in y-direction
		@param dx - change in x position
		@param dy - change in y position
		*/
		void move(const float& dx, const float& dy);
};