#pragma once

#include "GameObject.h"
#include "PlatformPhysicsObject.h"
#include <iostream>
#include <math.h>

#define GRAVITY_CONST 900.0f

/**
A base class for game objects that can fall onto other
objects.
*/
class FallingPhysicsObject : public GameObject {
public:
	/**
	Constructs a FallingPhysicsObject.
	*/
	FallingPhysicsObject();

	virtual void update(std::set<GameObject*>& gameObjects, const sf::Time& dt);

	/**
	Returns the current Y-velocity (positive down).
	@return y-velocity of the object.
	*/
	const float& getYVelocity() const;
	/**
	Returns true if the object is groudned.
	@return true if grounded, false if not.
	*/
	const bool& isGrounded() const;

protected:
	/**
	Moves the object an x-distance and y-distance.
	@param dx Change in x position.
	@param dy Change in y position.
	*/
	virtual void move(const float& dx, const float& dy) = 0;
	/**
	Sets the Y-velocity of the object (positive down).
	@param yvel New y-velocity of the object.
	*/
	void setYVelocity(const float& yvel);

private:
	float _yVel;
	bool _isGrounded;
};