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
		*/
		void update(std::set<GameObject*>& gameObjects, const sf::Time& dt);
		/**
		Draws _circleShape member variable to window parameter
		*/
		void draw(sf::RenderWindow& window);
		/**
		returns reference to position of _circleShape member variable
		*/
		const sf::Vector2f& getPosition() const;
		/**
		returns rotation of _circleShape member variable, in degrees*/
		const float& getRotation() const;
		/**
		returns bounding box of _circleShape for purposes of detecting collisions
		*/
		sf::FloatRect getBoundingBox() const;

	private:
		sf::CircleShape _circleShape;
		float _xVel; // stores x-direcrion velocity of projectile
		Target _target; // stores the type of object the projectile can damage

		/**
		moves _circleShape member variable by dx in x-direction and dy in y-direction
		*/
		void move(const float& dx, const float& dy);
};