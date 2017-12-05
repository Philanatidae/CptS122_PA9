#include "MainGameState.h"

MainGameState::MainGameState(Game*const& game)
	:_camera(sf::FloatRect(0, 0, GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT)),
	GameState(game) {
}

void MainGameState::init() {
	createLevel();
}

void MainGameState::update(const sf::Time& dt) {
	GameState::update(dt);

	bool foundPlayer = false;
	for (std::set<GameObject*>::iterator iterator = _gameObjects.begin();
		iterator != _gameObjects.end();
		iterator++) {
		if (dynamic_cast<Player*>(*iterator)) {
			foundPlayer = true;
			_camera.setCenter((*iterator)->getPosition());
			break;
		}
	}
	if (!foundPlayer) {
		getGame()->changeState(new GameOverGameState(getGame()));
		return;
	}
}
void MainGameState::draw(sf::RenderWindow& window) {
	window.setView(_camera);
	GameState::draw(window);
}

void MainGameState::createLevel() {
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
	_gameObjects.insert(new BouncingEnemy(sf::Color::Red, sf::Vector2f(1200, 0)));
}