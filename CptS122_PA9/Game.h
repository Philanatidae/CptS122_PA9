#pragma once

#include <set>
#include <SFML/Graphics.hpp>

#include "GameState.h"
class GameState; // Forward declare

#define GAME_WINDOW_WIDTH 1280
#define GAME_WINDOW_HEIGHT 720

/**
Class for main game.
*/
class Game {
public:
	Game();
	~Game();

	/**
	Runs the game (blocks).
	*/
	void run();

	void changeState(GameState*const& gameState);

private:
	GameState* _gameState;
	sf::RenderWindow _window;
};