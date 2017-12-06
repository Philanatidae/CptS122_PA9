#pragma once

#include "Game.h"
class Game; // Forward declare

#include <set>
#include <SFML/Graphics.hpp>

#include "GameObject.h"
#include "Player.h"

class GameState {
public:
	GameState(Game*const& game);
	virtual ~GameState();

	virtual void init() = 0;

	virtual void update(const sf::Time& dt);
	virtual void draw(sf::RenderWindow& window);

	Game*const& getGame() const;

protected:
	std::set<GameObject*> _gameObjects;

private:
	Game* const _gamePtr;

	void updateAll(const sf::Time& dt);
	void drawAll(sf::RenderWindow& window);
	void deleteObjects();
};