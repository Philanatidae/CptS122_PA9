#include "GameState.h"

/**
Constructs a game state.
@param game Pointer to game class.
*/
GameState::GameState(Game*const& game):_gamePtr(game) {
}
GameState::~GameState() {
	while (_gameObjects.begin() != _gameObjects.end()) {
		GameObject* gameObject = *_gameObjects.begin();
		delete gameObject;
		_gameObjects.erase(_gameObjects.begin());
	}
}

/**
Updates the game state.
@param dt Change in time since last frame.
*/
void GameState::update(const sf::Time& dt) {
	updateAll(dt);
	deleteObjects();
}
/**
Draws the game state.
@param window Window to render to.
*/
void GameState::draw(sf::RenderWindow& window) {
	drawAll(window);
}

/**
Returns the pointer to the game class.
@return Pointer to the game class.
*/
Game*const& GameState::getGame() const {
	return _gamePtr;
}

/**
Updates all the entities.
@param dt Change in time since last frame.
*/
void GameState::updateAll(const sf::Time& dt) {
	// While loop is necessary otherwise an invalid iterator will occur
	std::set<GameObject*>::iterator iterator = _gameObjects.begin();
	while (iterator != _gameObjects.end()) {
		GameObject* gameObject = *(iterator++);
		gameObject->update(_gameObjects, dt);
	}
}
/**
Draws all the entities.
@param window Window to render to.
*/
void GameState::drawAll(sf::RenderWindow& window) {
	for (std::set<GameObject*>::iterator iterator = _gameObjects.begin();
		iterator != _gameObjects.end();
		iterator++) {
		GameObject* gameObject = *iterator;

		gameObject->draw(window);
	}
}
/**
Deletes objects that have their delete flag set.
*/
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
			if (dynamic_cast<Player*>(gameObject) != nullptr) {
				// If a player was destroyed, change to game over
				// state.
				delete gameObject;
				//getGame()->changeState(new GameOverGameState(getGame()));
				return;
			}
			else {
				delete gameObject;
			}
		}
		else {
			iterator++;
		}
	}
}