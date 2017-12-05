#include "MenuGameState.h"

MenuGameState::MenuGameState(Game*const& game)
	:_elapsedTime(0), GameState(game) {
}

void MenuGameState::init() {
	_gameObjects.insert(new TextObject(sf::Vector2f(100, 100), "CptS PA 9", sf::Color::White, 40));
	_gameObjects.insert(new TextObject(sf::Vector2f(100, 150), "By Philip Rader and Navdeep Singh", sf::Color::White));

	_gameObjects.insert(new TextObject(sf::Vector2f(100, 250), "Goal: Reach the end of the level", sf::Color::White));
	_gameObjects.insert(new TextObject(sf::Vector2f(100, 285), "A/D ~ Move Left/Right", sf::Color::White));
	_gameObjects.insert(new TextObject(sf::Vector2f(100, 320), "W ~ Jump", sf::Color::White));
	_gameObjects.insert(new TextObject(sf::Vector2f(100, 355), "Left/Right Arrows ~ Shoot Left/Right", sf::Color::White));

	_flashingObject = new TextObject(sf::Vector2f(100, 450), "");
	_gameObjects.insert(_flashingObject);
}

void MenuGameState::update(const sf::Time& dt) {
	_elapsedTime += dt.asSeconds();
	if (cos(_elapsedTime * 2 * 3.14159265f) > 0) {
		_flashingObject->setContent("Press Enter to Play");
	}
	else {
		_flashingObject->setContent("");
	}

	GameState::update(dt);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)) {
		getGame()->changeState(new MainGameState(getGame()));
	}
}
void MenuGameState::draw(sf::RenderWindow& window) {
	window.setView(window.getDefaultView());
	GameState::draw(window);
}