#include "GameOverGameState.h"

GameOverGameState::GameOverGameState(Game*const& game)
	:_gameOverCountdown(GAME_OVER_COUNTDOWN_TIME), GameState(game) {
}

void GameOverGameState::init() {
	_gameObjects.insert(new TextObject(sf::Vector2f(100, 100), "Game Over!", sf::Color::White, 50));
}

void GameOverGameState::update(const sf::Time& dt) {
	_gameOverCountdown -= dt.asSeconds();
	if (_gameOverCountdown <= 0) {
		getGame()->changeState(new MenuGameState(getGame()));
		return; // Return or else there are issues
	}

	GameState::update(dt);
}

void GameOverGameState::draw(sf::RenderWindow& window) {
	window.setView(window.getDefaultView());
	GameState::draw(window);
}