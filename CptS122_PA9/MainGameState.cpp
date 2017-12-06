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
	bool foundGoal = false;
	for (std::set<GameObject*>::iterator iterator = _gameObjects.begin();
		iterator != _gameObjects.end();
		iterator++) {
		if (dynamic_cast<Player*>(*iterator)) {
			foundPlayer = true;
			_camera.setCenter((*iterator)->getPosition());
		}
		if (dynamic_cast<GoalGameObject*>(*iterator)) {
			foundGoal = true;
		}
	}
	if (!foundPlayer) {
		getGame()->changeState(new GameOverGameState(getGame()));
		return;
	}
	if (!foundGoal) {
		getGame()->changeState(new WinGameState(getGame()));
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
	levelBuilder.set(0, -1000);
	levelBuilder.drawVertical(1300);
	levelBuilder.drawHorizontal(600);

	levelBuilder.drawVertical(-50);
	_gameObjects.insert(new BouncingEnemy(sf::Color::Red, sf::Vector2f(levelBuilder.getPosition().x + 200, 100)));
	levelBuilder.drawHorizontal(100);
	levelBuilder.drawVertical(-50);
	levelBuilder.drawHorizontal(200);

	levelBuilder.drawVertical(50);
	levelBuilder.drawHorizontal(100);
	levelBuilder.drawVertical(50);
	levelBuilder.drawHorizontal(100);

	_gameObjects.insert(new BouncingEnemy(sf::Color::Red, sf::Vector2f(levelBuilder.getPosition().x + 200, 100)));
	_gameObjects.insert(new BouncingEnemy(sf::Color::Red, sf::Vector2f(levelBuilder.getPosition().x + 400, 100)));

	_gameObjects.insert(new SineEnemy(sf::Vector2f(50, 50), sf::Color::Yellow, sf::Vector2f(levelBuilder.getPosition().x + 300, 100)));

	levelBuilder.drawHorizontal(600);

	levelBuilder.drawVertical(50);
	levelBuilder.drawHorizontal(200);
	levelBuilder.drawVertical(50);
	levelBuilder.drawHorizontal(300);

	_gameObjects.insert(new SineEnemy(sf::Vector2f(50, 50), sf::Color::Yellow, sf::Vector2f(levelBuilder.getPosition().x + 100, 100)));
	_gameObjects.insert(new BouncingEnemy(sf::Color::Red, sf::Vector2f(levelBuilder.getPosition().x + 100, 100)));

	levelBuilder.drawVertical(-50);
	levelBuilder.drawHorizontal(200);
	levelBuilder.drawVertical(-50);
	levelBuilder.drawHorizontal(100);

	_gameObjects.insert(new BouncingEnemy(sf::Color::Red, sf::Vector2f(levelBuilder.getPosition().x, 100)));

	levelBuilder.drawVertical(300);

	_gameObjects.insert(new BouncingEnemy(sf::Color::Red, sf::Vector2f(levelBuilder.getPosition().x + 100, 100)));

	//-- GAP
	levelBuilder.drawHorizontal(170);
	levelBuilder.move(200, 0);
	levelBuilder.drawHorizontal(140);
	//--

	levelBuilder.drawVertical(-100);
	levelBuilder.drawHorizontal(10);
	levelBuilder.drawVertical(100);
	levelBuilder.drawHorizontal(100);

	levelBuilder.drawVertical(-150);
	levelBuilder.drawHorizontal(10);
	levelBuilder.drawVertical(150);
	levelBuilder.drawHorizontal(20);
	
	// Bottom route
	levelBuilder.move(140, -250);
	levelBuilder.drawVertical(400);
	std::cout << levelBuilder.getPosition().x << std::endl;
	_gameObjects.insert(new SineEnemy(sf::Vector2f(50, 50), sf::Color::Yellow, sf::Vector2f(levelBuilder.getPosition().x - 250, levelBuilder.getPosition().y - 75)));
	levelBuilder.drawHorizontal(-550);
	levelBuilder.drawVertical(-50);
	levelBuilder.drawHorizontal(-50);
	levelBuilder.drawVertical(-50);
	levelBuilder.drawHorizontal(-40);
	levelBuilder.drawVertical(-40);

	// Upper route
	levelBuilder.move(650, -260);
	_gameObjects.insert(new SineEnemy(sf::Vector2f(50, 50), sf::Color::Yellow, sf::Vector2f(levelBuilder.getPosition().x + 250, levelBuilder.getPosition().y - 75)));
	levelBuilder.drawHorizontal(500);
	levelBuilder.drawVertical(500);
	_gameObjects.insert(new ShootingEnemy(sf::Color::Magenta, sf::Vector2f(levelBuilder.getPosition().x + 600, levelBuilder.getPosition().y - 75)));
	levelBuilder.drawHorizontal(1000);

	// WALL (catches stray bullets)
	levelBuilder.drawVertical(-1000);

	// Goal
	_gameObjects.insert(new GoalGameObject(sf::Vector2f(levelBuilder.getPosition().x - 200, levelBuilder.getPosition().y + 1000 - 200))); // +1000 b/c of the wall
}