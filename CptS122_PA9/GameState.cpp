#include "GameState.h"

GameState::GameState(Game*const& game):_gamePtr(game) {
}
GameState::~GameState() {
	while (_gameObjects.begin() != _gameObjects.end()) {
		GameObject* gameObject = *_gameObjects.begin();
		delete gameObject;
		_gameObjects.erase(_gameObjects.begin());
	}
}

void GameState::update(const sf::Time& dt) {
	updateAll(dt);
	deleteObjects();
}
void GameState::draw(sf::RenderWindow& window) {
	drawAll(window);
}

Game*const& GameState::getGame() const {
	return _gamePtr;
}

void GameState::updateAll(const sf::Time& dt) {
	// While loop is necessary otherwise an invalid iterator will occur
	std::set<GameObject*>::iterator iterator = _gameObjects.begin();
	while (iterator != _gameObjects.end()) {
		GameObject* gameObject = *(iterator++);
		gameObject->update(_gameObjects, dt);
	}
}
void GameState::drawAll(sf::RenderWindow& window) {
	for (std::set<GameObject*>::iterator iterator = _gameObjects.begin();
		iterator != _gameObjects.end();
		iterator++) {
		GameObject* gameObject = *iterator;

		gameObject->draw(window);
	}
}
void GameState::deleteObjects() {
	std::set<GameObject*>::iterator iterator = _gameObjects.begin();
	std::set<GameObject*>::iterator temp;

	while (iterator != _gameObjects.end()) {
		GameObject* gameObject = *iterator;

		if (gameObject->toDelete()) { // Delete object
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