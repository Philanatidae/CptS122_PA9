#include "GameOverGameState.h"

/**
Constructs a game over game state.
@param game Pointer to game class.
*/
GameOverGameState::GameOverGameState(Game*const& game)
	:_gameOverCountdown(GAME_OVER_COUNTDOWN_TIME), GameState(game) {
}

/**
Initializes the game state.
*/
void GameOverGameState::init() {
	_gameObjects.insert(new TextObject(sf::Vector2f(100, 100), "Game Over!", sf::Color::White, 50));
}

/**
Updates the game state.
@param dt Change in time since last frame.
*/
void GameOverGameState::update(const sf::Time& dt) {
	_gameOverCountdown -= dt.asSeconds();
	if (_gameOverCountdown <= 0) {
		getGame()->changeState(new MenuGameState(getGame()));
		return; // Return or else there are issues
	}

	GameState::update(dt);
}

/**
Draws the game state.
@param window Window to render to.
*/
void GameOverGameState::draw(sf::RenderWindow& window) {
	window.setView(window.getDefaultView());
	GameState::draw(window);
}