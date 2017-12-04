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
		deleteObjects();

		// Render
		_window.clear();
		_window.setView(_camera);
		drawAll();
		_window.display();
	}
}

void Game::createLevel() {
	_gameObjects.insert(new Player(sf::Vector2f(400, 0)));

	// Floors
	LevelBuilder levelBuilder(&_gameObjects);
	levelBuilder.set(0, 0);
	levelBuilder.drawVertical(300);
	levelBuilder.drawHorizontal(600);
	
	levelBuilder.drawVertical(-50);
	levelBuilder.drawHorizontal(50);
	levelBuilder.drawVertical(-50);
	levelBuilder.drawHorizontal(50);

	levelBuilder.drawVertical(50);
	levelBuilder.drawHorizontal(50);
	levelBuilder.drawVertical(50);
	levelBuilder.drawHorizontal(50);
	
	levelBuilder.drawHorizontal(600);

	// Enemies
	_gameObjects.insert(new SineEnemy(sf::Vector2f(50, 50), sf::Color::Yellow, sf::Vector2f(1100, 0)));
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
void Game::deleteObjects() {
	std::set<GameObject*>::iterator iterator = _gameObjects.begin();
	std::set<GameObject*>::iterator temp;

	while (iterator != _gameObjects.end() ) {
		GameObject* gameObject = *iterator;

		if (gameObject->toDelete()){ // Delete object
			temp = iterator;
			temp++;
			_gameObjects.erase(iterator);
			iterator = temp;
			delete gameObject;
		}
		else {
			iterator++;
		}
	}
}