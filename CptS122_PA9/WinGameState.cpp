#include "WinGameState.h"

/**
Constructs a game state for winning the game.
@param game Pointer to game class.
*/
WinGameState::WinGameState(Game*const& game)
	:_winCountdown(WIN_COUNTDOWN_TIME), GameState(game) {
}

/**
Initializes the game state.
*/
void WinGameState::init() {
	_gameObjects.insert(new TextObject(sf::Vector2f(100, 100), "You win!", sf::Color::White, 50));
}

/**
Updates the game state.
@param dt Change in time since last frame.
*/
void WinGameState::update(const sf::Time& dt) {
	_winCountdown -= dt.asSeconds();
	if (_winCountdown <= 0) {
		getGame()->changeState(new MenuGameState(getGame()));
		return; // Return or else there are issues
	}

	GameState::update(dt);
}

/**
Draws the game state.
@param window Window to render to.
*/
void WinGameState::draw(sf::RenderWindow& window) {
	window.setView(window.getDefaultView());
	GameState::draw(window);
}