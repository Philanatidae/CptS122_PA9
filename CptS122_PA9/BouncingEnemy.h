#pragma once

#include "FallingPhysicsObject.h"
#include "Enemy.h"

#define BOUNCING_ENEMY_WIDTH 50
#define BOUNCING_ENEMY_HEIGHT 50

#define BOUNCING_ENEMY_BOUNCE_PERIOD 1
#define BOUNCING_ENEMY_JUMP_VELOCITY -350
#define BOUNCING_ENEMY_TRACKING_X_VEL 100

#include "Player.h"

/**
An enemy that bounces towards the player.
*/
class BouncingEnemy: public Enemy, public FallingPhysicsObject {
public:
	/**
	Constructs a bouncing enemy.
	@param color Color of enemy.
	@param position Position of enemy.
	*/
	BouncingEnemy(const sf::Color &color, const sf::Vector2f &position);

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
	/**
	Bounces the enemy.
	*/
	void bounce();

private:
	sf::RectangleShape _rectShape;
	double _bounceTime = 0.0;
};