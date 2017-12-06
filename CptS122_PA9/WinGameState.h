#pragma once

#include "GameState.h"
class GameState;
#include "MenuGameState.h"

#include <SFML/Graphics.hpp>

#include "TextObject.h"

#define WIN_COUNTDOWN_TIME 6.0f

class WinGameState : public GameState {
public:
	WinGameState(Game*const& game);

	void init();

	void update(const sf::Time& dt);
	void draw(sf::RenderWindow& window);

private:
	float _winCountdown;
};