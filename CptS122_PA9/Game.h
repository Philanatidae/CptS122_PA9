#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "GameObject.h"

#include "Player.h"
#include "Floor.h"

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

private:
	std::vector<GameObject*> _gameObjects;
	sf::RenderWindow _window;

	/**
	Creates the level out of GameObjects.
	*/
	void createLevel();

	/**
	Updates all GameObjects with dt (delta time since last
	frame).
	@dt Change in time since last frame.
	*/
	void updateAll(const sf::Time& dt);
	/**
	Draws all GameObjects to the window.
	*/
	void drawAll();
};