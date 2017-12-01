#pragma once

#include <set>
#include <SFML/Graphics.hpp>

#include "GameObject.h"

#include "LevelBuilder.h"

#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"

#define GAME_WINDOW_WIDTH 1280
#define GAME_WINDOW_HEIGHT 720

#define CAMERA_PLAYER_OFFSET -50

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
	std::set<GameObject*> _gameObjects;
	sf::View _camera;
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
	/**
	Delete all GameObjects that are no longer needed.
	*/
	void deleteObjects();
};