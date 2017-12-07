#pragma once

#include "GameState.h"
class GameState;
#include "MenuGameState.h"

#include <SFML/Graphics.hpp>

#include "TextObject.h"

#define WIN_COUNTDOWN_TIME 6.0f

/**
Game state for winning the game.
*/
class WinGameState : public GameState {
public:
	/**
	Constructs a game state for winning the game.
	@param game Pointer to game class.
	*/
	WinGameState(Game*const& game);

	/**
	Initializes the game state.
	*/
	void init();

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
	float _winCountdown;
};