#pragma once

#include <SFML/Graphics.hpp>
#include <set>

/**
Base game object class that all other
objects in the game extend from.
*/
class GameObject {
public:
	/**
	Updates the object.
	@param gameObjects Global list of game objects.
	@param dt Time since last frame (change in time since last frame).
	*/
	virtual void update(std::set<GameObject*>& gameObjects, const sf::Time& dt) = 0;
	/**
	Draws the object to the window.
	@param window SFML Window to draw to.
	*/
	virtual void draw(sf::RenderWindow& window) = 0;

	/**
	Returns the position of the object.
	@return Position of the object.
	*/
	virtual const sf::Vector2f& getPosition() const = 0;
	/**
	Returns the rotation of the object, in degrees.
	@return Rotation of the object.
	*/
	virtual const float& getRotation() const = 0;
	/**
	Returns the bounding box of the object for collision
	detection.
	@return Bounding box of the object.
	*/
	virtual sf::FloatRect getBoundingBox() const = 0;
	/**
	Returns bool to indicate whether the object is ready to be deleted
	@return toDelete
	*/
	bool toDelete() {
		return _toDelete;
	}
	/**
	Sets toDelete value to true
	*/
	void setToDelete() {
		_toDelete = true;
	}

protected:
	bool _toDelete = false;
};