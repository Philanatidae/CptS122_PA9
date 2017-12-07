#pragma once

#include "GameState.h"
class GameState;
class Game;

#include "LevelBuilder.h"

#include "Player.h"
#include "SineEnemy.h"
#include "BouncingEnemy.h"
#include "ShootingEnemy.h"
#include "Projectile.h"
#include "GoalGameObject.h"

#include "GameOverGameState.h"
#include "WinGameState.h"

#define GAME_WINDOW_WIDTH 1280
#define GAME_WINDOW_HEIGHT 720

/**
Class for the main game state.
*/
class MainGameState : public GameState {
public:
	/**
	Constructs a main game state.
	@param game Pointer to game class.
	*/
	MainGameState(Game*const& game);

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
	sf::View _camera;
	/**
	Creates the level.
	*/
	void createLevel();

};