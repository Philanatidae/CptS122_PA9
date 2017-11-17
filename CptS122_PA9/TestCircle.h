#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>

#include "GameObject.h"

/**
A GameObject that draws a circle that moves
back and forth.
*/
class TestCircle : public GameObject {
public:
	/**
	Constructs a TestCircle.
	@param radius Radius of circle.
	*/
	TestCircle(const float& radius);

	/**
	Updates the object.
	@param gameObjects Global list of game objects.
	@param dt Time since last frame (change in time since last frame).
	*/
	void update(std::vector<GameObject*>& gameObjects, const sf::Time& dt);
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
	const sf::FloatRect& getBoundingBox() const;

private:
	sf::CircleShape _circleShape;
	double _elapsedTime = 0.0;
};