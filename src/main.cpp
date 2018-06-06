#include "game.h"

int main()
{
	srand(time(nullptr));

	Game game;
	game.init();
	game.run();

	return 0;
}
