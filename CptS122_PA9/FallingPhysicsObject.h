#pragma once

#include "GameObject.h"
#include "PlatformPhysicsObject.h"
#include <iostream>
#include <math.h>

#define GRAVITY_CONST 900.0f

class FallingPhysicsObject : public GameObject {
public:
	FallingPhysicsObject();

	virtual void update(std::vector<GameObject*>& gameObjects, const sf::Time& dt);

	const float& getYVelocity() const;
	const bool& isGrounded() const;

protected:
	virtual void move(const float& dx, const float& dy) = 0;
	void setYVelocity(const float& yvel);

private:
	float _yVel;
	bool _isGrounded;
};