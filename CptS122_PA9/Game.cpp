#include "Game.h"

Game::Game():
	_window(sf::VideoMode(GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT), "CptS 122 Game"),
	_gameState(nullptr) {

	changeState(new MainGameState(this));
}

Game::~Game() {

}

void Game::run() {
	sf::Clock dtClock;
	while (_window.isOpen()) {
		sf::Event event;
		while(_window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				_window.close();
			}
		}

		// Update
		sf::Time elapsed = dtClock.restart();
		_gameState->update(elapsed);

		// Render
		_window.clear();
		_gameState->draw(_window);
		_window.display();
	}
}

void Game::changeState(GameState* gameState) {
	if (_gameState != nullptr) {
		delete _gameState;
	}
	_gameState = gameState;
	_gameState->init();
}