#include "FallingPhysicsObject.h"

FallingPhysicsObject::FallingPhysicsObject()
	:_yVel(-500),_isGrounded(false) {

}

void FallingPhysicsObject::update(std::set<GameObject*>& gameObjects, const sf::Time& dt) {
	const float totAccel = GRAVITY_CONST;
	_yVel += totAccel * dt.asSeconds();
	move(0, _yVel * dt.asSeconds() + 0.5f * totAccel * dt.asSeconds() * dt.asSeconds());
	// Assume not grounded (this is checked later)
	_isGrounded = false;

	// Floor collision check
	const sf::FloatRect myBoundingBox = getBoundingBox();
	for (std::set<GameObject*>::iterator iterator = gameObjects.begin();
		iterator != gameObjects.end();
		iterator++) {
		GameObject* gameObject = *iterator;
		if (gameObject == this) {
			continue;
		}

		// Only perform collision for "PlatformPhysicsObject"
		PlatformPhysicsObject* platformPhysicsObject = dynamic_cast<PlatformPhysicsObject*>(gameObject);
		if (platformPhysicsObject == nullptr) {
			continue;
		}

		// If colliding, move up so that we aren't colliding anymore
		const sf::FloatRect platformPhysicsObjectBoundingBox = platformPhysicsObject->getBoundingBox();
		if (platformPhysicsObject->getBoundingBox().intersects(getBoundingBox())) {
			// Detemine normal of the platform physics object
			// This will be the direction which the platform will push the falling physics object.
			sf::Vector2i norm(0, 0);
			// Source for algorithm to part of rectangle colliding:
			// https://gamedev.stackexchange.com/questions/29786/a-simple-2d-rectangle-collision-algorithm-that-also-determines-which-sides-that
			const float w = 0.5f * (platformPhysicsObjectBoundingBox.width + myBoundingBox.width);
			const float h = 0.5f * (platformPhysicsObjectBoundingBox.height + myBoundingBox.height);
			const float dx = (platformPhysicsObjectBoundingBox.left + platformPhysicsObjectBoundingBox.width / 2)
				- (myBoundingBox.left + myBoundingBox.width / 2);
			const float dy = (platformPhysicsObjectBoundingBox.top + platformPhysicsObjectBoundingBox.height / 2)
				- (myBoundingBox.top + myBoundingBox.height / 2);

			const float wy = w * dy;
			const float hx = h * dx;

			// Normal is relative to the platform, not "this" object
			if (wy > hx) {
				if (wy > -hx) {
					// Top
					norm.y = -1;
				}
				else {
					// Right
					norm.x = 1;
				}
			}
			else {
				if (wy > -hx) {
					// Left
					norm.x = -1;
				}
				else {
					// Bottom
					norm.y = 1;
				}
			}

			// Determine overlap
			const sf::Vector2f myEdge(myBoundingBox.left + myBoundingBox.width / 2 - norm.x * myBoundingBox.width / 2,
				myBoundingBox.top + myBoundingBox.height / 2 - norm.y * myBoundingBox.height / 2);
			const sf::Vector2f platformEdge(platformPhysicsObjectBoundingBox.left + platformPhysicsObjectBoundingBox.width / 2 + norm.x * platformPhysicsObjectBoundingBox.width / 2,
				platformPhysicsObjectBoundingBox.top + platformPhysicsObjectBoundingBox.height / 2 + norm.y * platformPhysicsObjectBoundingBox.height / 2);
			const sf::Vector2f overlap = myEdge - platformEdge;

			// Move in the direction of the normal
			move(norm.x * overlap.x, norm.y * overlap.y);
			// If normal is facing upward (top of platform)
			if (norm.y > 0) {
				// Hit a ceiling, no more vertical velocity
				_yVel = 0;
			}
			if (norm.y < 0) {
				// Hit a floor, no more vertical velocity
				_yVel = 0;
				// We are now grounded
				_isGrounded = true;
			}
		}
	}
}
const bool& FallingPhysicsObject::isGrounded() const {
	return _isGrounded;
}

const float& FallingPhysicsObject::getYVelocity() const {
	return _yVel;
}

void FallingPhysicsObject::setYVelocity(const float& yvel) {
	_yVel = yvel;
}