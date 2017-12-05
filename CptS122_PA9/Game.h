#pragma once

#include <set>
#include <SFML/Graphics.hpp>

#include "GameState.h"
#include "MainGameState.h"

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

	void changeState(GameState* gameState);

private:
	GameState* _gameState;
	sf::RenderWindow _window;
};