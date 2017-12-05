#include <SFML/Graphics.hpp>
#include "Game.h"
#include "MenuGameState.h"

int main() {
	Game game;
	game.changeState(new MenuGameState(&game));
	game.run();

	return 0;
}