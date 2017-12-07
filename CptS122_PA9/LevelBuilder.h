#pragma once

#include <set>
#include "GameObject.h"
#include "Floor.h"

#define FLOOR_THICKNESS 20

/**
Class for building levels.
*/
class LevelBuilder {
public:
	/**
	Constructs a level builder.
	@param gameObjectsPtr Pointer to set of game objects (non-owning).
	*/
	LevelBuilder(std::set<GameObject*>* const & gameObjectsPtr);

	/**
	Draws the level horizontally.
	@param dx Change in x direction.
	*/
	void drawHorizontal(const float& dx);
	/**
	Draws the level vertically.
	@param dy Change in y direction.
	*/
	void drawVertical(const float& dy);
	/**
	Moves the "cursor" of the level builder without
	drawing.
	@param dx Change in x direction.
	@param dy Change in y direction.
	*/
	void move(const float& dx, const float& dy);
	/**
	Sets the position of the level builder without drawing.
	*/
	void set(const float& x, const float& y);

	/**
	Returns the current position of the level builder.
	@return Current position of the level builder.
	*/
	const sf::Vector2f& getPosition() const;

private:
	std::set<GameObject*>* const _gameObjectsPtr;
	sf::Vector2f _currPosition;
};