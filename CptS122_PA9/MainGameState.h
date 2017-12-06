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

class MainGameState : public GameState {
public:
	MainGameState(Game*const& game);

	virtual void init();

	void update(const sf::Time& dt);
	void draw(sf::RenderWindow& window);

private:
	sf::View _camera;
	void createLevel();

};