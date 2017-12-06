#include "WinGameState.h"

WinGameState::WinGameState(Game*const& game)
	:_winCountdown(WIN_COUNTDOWN_TIME), GameState(game) {
}

void WinGameState::init() {
	_gameObjects.insert(new TextObject(sf::Vector2f(100, 100), "You win!", sf::Color::White, 50));
}

void WinGameState::update(const sf::Time& dt) {
	_winCountdown -= dt.asSeconds();
	if (_winCountdown <= 0) {
		getGame()->changeState(new MenuGameState(getGame()));
		return; // Return or else there are issues
	}

	GameState::update(dt);
}

void WinGameState::draw(sf::RenderWindow& window) {
	window.setView(window.getDefaultView());
	GameState::draw(window);
}