#pragma once

#include "FallingPhysicsObject.h"
#include "Enemy.h"

#define BOUNCING_ENEMY_WIDTH 50
#define BOUNCING_ENEMY_HEIGHT 50

#define BOUNCING_ENEMY_BOUNCE_PERIOD 1
#define BOUNCING_ENEMY_JUMP_VELOCITY -350
#define BOUNCING_ENEMY_TRACKING_X_VEL 100

#include "Player.h"

class BouncingEnemy: public Enemy, public FallingPhysicsObject {
public:

	BouncingEnemy(const sf::Color &color, const sf::Vector2f &position);

	void update(std::set<GameObject*>& gameObjects, const sf::Time& dt);
	void draw(sf::RenderWindow& window);
	const sf::Vector2f& getPosition() const;
	const float& getRotation() const;
	sf::FloatRect getBoundingBox() const;

protected:
	void move(const float& dx, const float& dy);
	void bounce();

private:
	sf::RectangleShape _rectShape;
	double _bounceTime = 0.0;
};