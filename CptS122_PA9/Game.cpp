#include "Game.h"

Game::Game()
	:_window(sf::VideoMode(GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT), "CptS 122 Game"),_camera(sf::FloatRect(0, 0, GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT)) {
	createLevel();
}

Game::~Game() {
	while (_gameObjects.begin() != _gameObjects.end()) {
		GameObject* gameObject = *_gameObjects.begin();
		delete gameObject;
		_gameObjects.erase(_gameObjects.begin());
	}
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
		updateAll(elapsed);

		// Render
		_window.clear();
		_window.setView(_camera);
		drawAll();
		_window.display();
	}
}

void Game::createLevel() {
	_gameObjects.insert(new Player());
	_gameObjects.insert(new Floor(sf::Vector2f(400.0f, 600.0f), 300, 20)); // Bottom floor
	_gameObjects.insert(new Floor(sf::Vector2f(700.0f, 300.0f), 20, 300)); // Right floor
}

void Game::updateAll(const sf::Time& dt) {
	// While loop is necessary otherwise an invalid iterator will occur
	std::set<GameObject*>::iterator iterator = _gameObjects.begin();
	while (iterator != _gameObjects.end()) {
		GameObject* gameObject = *(iterator++);
		gameObject->update(_gameObjects, dt);

		Player* player = dynamic_cast<Player*>(gameObject);
		if (player != nullptr) {
			// View updates to the player's position
			_camera.setCenter(player->getPosition().x, player->getPosition().y + CAMERA_PLAYER_OFFSET);
		}
	}
}
void Game::drawAll() {
	for (std::set<GameObject*>::iterator iterator = _gameObjects.begin();
		iterator != _gameObjects.end();
		iterator++) {
		GameObject* gameObject = *iterator;

		gameObject->draw(_window);
	}
}