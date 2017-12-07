#pragma once

#include "Enemy.h"
#include "FallingPhysicsObject.h"
#include <Math.h>

/**
A class for a enemy that moves back and forth to a sine wave.
*/
class SineEnemy : public Enemy, public FallingPhysicsObject
{
public:
	/**
	Constructs a sine enemy object.
	@param size Size of the enemy.
	@param color Color of the enemy.
	@param position Position of the enemy.
	*/
	SineEnemy(const sf::Vector2f &size, const sf::Color &color, const sf::Vector2f &position);

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
	double _elapsedTime = 0.0;

};