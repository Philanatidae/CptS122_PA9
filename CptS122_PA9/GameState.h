#pragma once

#include "Game.h"
class Game; // Forward declare

#include <set>
#include <SFML/Graphics.hpp>

#include "GameObject.h"
#include "Player.h"

/**
A base class for the game state.
*/
class GameState {
public:
	/**
	Constructs a game state.
	@param game Pointer to game class.
	*/
	GameState(Game*const& game);
	virtual ~GameState();

	/**
	Initializes the game state.
	*/
	virtual void init() = 0;

	/**
	Updates the game state.
	@param dt Change in time since last frame.
	*/
	virtual void update(const sf::Time& dt);
	/**
	Draws the game state.
	@param window Window to render to.
	*/
	virtual void draw(sf::RenderWindow& window);

	/**
	Returns the pointer to the game class.
	@return Pointer to the game class.
	*/
	Game*const& getGame() const;

protected:
	std::set<GameObject*> _gameObjects;

private:
	Game* const _gamePtr;

	/**
	Updates all the entities.
	@param dt Change in time since last frame.
	*/
	void updateAll(const sf::Time& dt);
	/**
	Draws all the entities.
	@param window Window to render to.
	*/
	void drawAll(sf::RenderWindow& window);
	/**
	Deletes objects that have their delete flag set.
	*/
	void deleteObjects();
};