#pragma once

#include "GameObject.h"

#include <SFML/Graphics.hpp>
#include <math.h>

/**
Class for the goal object.
*/
class GoalGameObject : public GameObject {
public:
	/**
	Constructs the goal object.
	*/
	GoalGameObject(const sf::Vector2f& position, const sf::Color& color = sf::Color::Green);

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
	sf::RectangleShape _goalEntity;
	float _elapsedTime;
};