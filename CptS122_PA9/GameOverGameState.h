#pragma once

#include "GameState.h"
class GameState;
#include "MenuGameState.h"

#include <SFML/Graphics.hpp>

#include "TextObject.h"

#define GAME_OVER_COUNTDOWN_TIME 6.0f

/**
Game state for when the game is over.
*/
class GameOverGameState : public GameState {
public:
	/**
	Constructs a game over game state.
	@param game Pointer to game class.
	*/
	GameOverGameState(Game*const& game);
	
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
	float _gameOverCountdown;
};