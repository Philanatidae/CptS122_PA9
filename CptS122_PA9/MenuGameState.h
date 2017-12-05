#pragma once

#include "GameState.h"
#include "MainGameState.h"
class GameState;
class Game;

#include "TextObject.h"

#include <math.h>
#include <iostream>

class MenuGameState : public GameState {
public:
	MenuGameState(Game*const& game);

	virtual void init();

	void update(const sf::Time& dt);
	void draw(sf::RenderWindow& window);

private:
	TextObject* _flashingObject = nullptr;
	float _elapsedTime;
};