
#include "Game.h"


using namespace std;

Game* game = NULL;
const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 600;

//int TextureManager::x = 0;
//int TextureManager::y = 0;

int main(int argc, char* argv[]) {
	game = new Game();
	game->init("Chess Generator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);
	game->tft_init();

	game->render();
	while (game->isRunning()) {

		if (SDL_GetTicks() % 100 ==0) {
			game->handleEvents();
		}
	}

	game->clean();
	return 0;
}


