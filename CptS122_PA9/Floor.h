#pragma once

#include "PlatformPhysicsObject.h"

/**
Class for the floor (and walls, apparently).
*/
class Floor : public PlatformPhysicsObject {
public:
	/**
	Constructs a floor object.
	@param position Position of the floor.
	@param width Width of the floor.
	@param height Height of the floor.
	*/
	Floor(const sf::Vector2f& position, const float& width, const float& height);
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

private:
	sf::RectangleShape _floorEntity;
};