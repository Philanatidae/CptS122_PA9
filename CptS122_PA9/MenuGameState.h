#pragma once

#include "GameState.h"
#include "MainGameState.h"
class GameState;
class Game;

#include "TextObject.h"

#include <math.h>
#include <iostream>

/**
Game state for the menu.
*/
class MenuGameState : public GameState {
public:
	/**
	Constructs a game state for the menu.
	@param game Pointer to game class.
	*/
	MenuGameState(Game*const& game);

	/**
	Initializes the game state.
	*/
	virtual void init();

	/**
	Updates the game state.
	@param dt Change in time since last frame.
	*/
	void update(const sf::Time& dt);
	/**
	Draws the game state.
	@param window Window to render to.
	*/
	void draw(sf::RenderWindow& window);

private:
	TextObject* _flashingObject = nullptr;
	float _elapsedTime;
};