#pragma once

#include "GameState.h"

#define GAME_WINDOW_WIDTH 1280
#define GAME_WINDOW_HEIGHT 720

#define CAMERA_PLAYER_OFFSET -50

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