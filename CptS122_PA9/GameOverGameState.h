#pragma once

#include "GameState.h"
class GameState;
#include "MenuGameState.h"

#include <SFML/Graphics.hpp>

#include "TextObject.h"

#define GAME_OVER_COUNTDOWN_TIME 6.0f

class GameOverGameState : public GameState {
public:
	GameOverGameState(Game*const& game);
	
	void init();

	void update(const sf::Time& dt);
	void draw(sf::RenderWindow& window);

private:
	float _gameOverCountdown;
};