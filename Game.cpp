#include "Game.h"

int c = 1;

//constructor
Game::Game()
{
	this->window = nullptr;
	this->renderer = nullptr;
	this->running = true;
	this->highligthed = false;
	this->board;
	
	this->generateText = nullptr;
	this->startSimText = nullptr;
	this->stopSimText = nullptr;
	this->countText = nullptr;
	this->totalTimeText = nullptr;
	this->averageTimeText = nullptr;

	this->dRectFont1 = { 0,0,0,0 };
	this->dRectFont2 = { 0,0,0,0 };
	this->dRectFont3 = { 0,0,0,0 };
	this->dRectFont4 = { 0,0,0,0 };
	this->dRectFont5 = { 0,0,0,0 };
	this->dRectFont6 = { 0,0,0,0 };

	//this->time.zero;

	this->simCount = 0;
	this->simStopper = false;
	this->hideButtons = false;


}

//destructor
Game::~Game()
{
}

//initializes starting values of the program, loads the textures 
bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (window != 0) {

			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer != 0) {
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
				
				TextureManager::Instance()->loadTexture("assets/chess_board.bmp","board", renderer);
				TextureManager::Instance()->loadTexture("assets/king_w.svg", "K", renderer);
				TextureManager::Instance()->loadTexture("assets/king_b.svg", "k", renderer);
				TextureManager::Instance()->loadTexture("assets/queen_b.svg", "q", renderer);
				TextureManager::Instance()->loadTexture("assets/queen_w.svg", "Q", renderer);
				TextureManager::Instance()->loadTexture("assets/bishop_b.svg", "b", renderer);
				TextureManager::Instance()->loadTexture("assets/bishop_w.svg", "B", renderer);
				TextureManager::Instance()->loadTexture("assets/rook_b.svg", "r", renderer);
				TextureManager::Instance()->loadTexture("assets/rook_w.svg", "R", renderer);
				TextureManager::Instance()->loadTexture("assets/knight_b.svg", "n", renderer);
				TextureManager::Instance()->loadTexture("assets/knight_w.svg", "N", renderer);
				TextureManager::Instance()->loadTexture("assets/pawn_b.svg", "p", renderer);
				TextureManager::Instance()->loadTexture("assets/pawn_w.svg", "P", renderer);
				TextureManager::Instance()->loadTexture("assets/button.bmp", "button", renderer);
				TextureManager::Instance()->loadTexture("assets/highligthed.png", "HL", renderer);
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
	this->running = true;

	return true;
}

//default render function for the board, buttons and texts
void Game::render()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	int ww, wh;
	SDL_GetWindowSize(window, &ww, &wh);
	
	TextureManager::Instance()->drawTexture("board", 50, ww/2 - 180, 360,360,renderer);
	TextureManager::Instance()->drawTexture("button", 450, ww / 2 + 70, 110, 50, renderer);


	// does not render these while a simulation is running
	if (this->hideButtons == false) {
		TextureManager::Instance()->drawTexture("button", 450, ww / 2 - 180, 110, 50, renderer);
		TextureManager::Instance()->drawTexture("button", 450, ww / 2 - 55, 110, 50, renderer);
		SDL_RenderCopy(renderer, generateText, NULL, &dRectFont1);
		SDL_RenderCopy(renderer, startSimText, NULL, &dRectFont2);
	}

	SDL_RenderCopy(renderer, stopSimText, NULL, &dRectFont3);
	SDL_RenderCopy(renderer, countText, NULL, &dRectFont4);
	SDL_RenderCopy(renderer, totalTimeText, NULL, &dRectFont5);
	SDL_RenderCopy(renderer, averageTimeText, NULL, &dRectFont6);


	SDL_RenderPresent(renderer);
	
}

//void Game::update()
//{
//	//currentFrame = int(((SDL_GetTicks()/100)));
//}


//main event handler
//registers (X), "Generate", "Start simulation" and highligthing a piece if no simulation is running
//if starting a simulation, passes the event listener role to startSim()
void Game::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {

		int mx, my;
		int w, h;
		SDL_GetWindowSize(window, &w, &h);
		SDL_GetMouseState(&mx, &my);
		switch (event.type) {
		case SDL_QUIT:
			running = false;
			break;

		case SDL_MOUSEBUTTONDOWN:

			if (mx>= w/2 - 180  && mx <= w/2+180 && my>=50 && my<=410) {

				ChessPiece* tempPiece = this->board.highligthedPiece((my - 50) / 45, (mx - 120) / 45);

				//occupied space
				if (highligthed == false && tempPiece != nullptr) {

					this->highligthed = true;


					render();
					TextureManager::Instance()->drawTexture("HL", 50 + tempPiece->getX() * 45,
						120 + tempPiece->getY() * 45, 45, 45, renderer);

					this->board.highlightMoves(renderer, tempPiece->getX(), tempPiece->getY());

					this->board.renderBoard(renderer, window);
					SDL_RenderPresent(renderer);

				}
				/*else if (highligthed == true && tempPiece != nullptr) {
					render();
					TextureManager::Instance()->drawTexture("HL", 50 + tempPiece->getX() * 45,
						120 + tempPiece->getY() * 45, 45, 45, renderer);

					this->board.highlightMoves(renderer, tempPiece->getX(), tempPiece->getY());

					this->board.renderBoard(renderer, window);
					SDL_RenderPresent(renderer);
				}*/
				else{
					highligthed = false;
					render();
					this->board.renderBoard(renderer, window);
					SDL_RenderPresent(renderer);
				}

				//empty space 
				if (tempPiece == nullptr) {
					this->highligthed = false;
					render();
					this->board.renderBoard(renderer, window);
					SDL_RenderPresent(renderer);
				}
			}
			
			if (mx >= w / 2 - 180 && mx <= w / 2 - 60 && my >= 450 && my <= 500) {
				render();
				this->board.cleanBoard();
				//this->board.fillBoard(renderer, window);
				this->board.fillBoard();

				this->board.renderBoard(renderer, window);
			}
			else if (mx >= w / 2 - 50 && mx <= w / 2 + 70 && my >= 450 && my <= 500) {
				this->hideButtons = true;
				this->startSim();
			}

			//ignores the "Stop simulation" button, aka does nothing
			/*else if (mx >= w / 2 + 80 && mx <= w / 2 + 200 && my >= 450 && my <= 500) {
				this->hideButtons = false;
				this->stopSim();
			}*/			
			break;
		default:

			break;
		}
	}
}

//helper function to cleap up SDL members
void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

//bool function to help with the running of the main while cycle
bool Game::isRunning()
{
	return this->running;
}

//helper function for the ttf 
//calculates the count number and returns it as a string
std::string Game::countToText()
{
	std::string tempStr = "Simulation count: ";
	tempStr.append(std::to_string(this->simCount));

	return tempStr;
}

//helper function for the ttf 
//calculates the total time and returns it as a string
std::string Game::totalToText()
{
	std::string tempStr = "Total time: ";
	tempStr.append(std::to_string(this->time.count()) + "s");
	return tempStr;
}

//helper function for the ttf 
//calculates the average time and returns it as a string
std::string Game::averageToText()
{
	std::string tempStr = "Average time: ";
	tempStr.append(std::to_string(this->time.count() / this->simCount) + "s");
	return tempStr;
}

//starts the simulation cycle
// holds the event listener cycle while the simulation runs
// registers only (X) and "Stop simulation"
// the simulation "pauses" for a second after each new generation since its uses a srand(time(NULL)) seed to generate the chess pieces and positions 
void Game::startSim()
{

	this->simStopper = false;

	while (!this->simStopper && this->running ) {
		//std::cout << "sim while" << std::endl;
		if(SDL_GetTicks() % 1000 == 0){
			auto start = std::chrono::system_clock::now();

			render();
			this->board.cleanBoard();
			//this->board.fillBoard(renderer, window);
			this->board.fillBoard();

			this->board.renderBoard(renderer, window);
			auto end = std::chrono::system_clock::now();
			this->time += end - start;
			this->simCount++;
		}

		if (SDL_GetTicks() % 100 == 0) {
			SDL_Event event;
			SDL_PollEvent(&event);
			switch (event.type) {
			case SDL_QUIT:
				this->running = false;
				break;
			case SDL_MOUSEBUTTONDOWN:
				int mx, my;
				int w, h;
				SDL_GetWindowSize(window, &w, &h);
				SDL_GetMouseState(&mx, &my);
				/*if (mx >= w / 2 - 50 && mx <= w / 2 + 70 && my >= 450 && my <= 500) {
					if (!this->simStopper) {
						this->stopSim();
					}
					this->startSim();
				}*/
				//else 
				if (mx >= w / 2 + 80 && mx <= w / 2 + 200 && my >= 450 && my <= 500) {
					this->hideButtons = false;
					this->stopSim();
				}
				break;
			default:
				break;
			}
		}

	}

}

//stops the simulation cycle and shows the resutls
// count 
// total time
// average time 
// the simulation "pauses" for a second after each new generation since its uses a srand(time(NULL)) seed to generate the chess pieces and positions 
void Game::stopSim()
{
	this->simStopper = true;
	//std::cout <<"total: " << this->time.count() << " count: " << this->simCount << " sredno: " << this->time.count() / this->simCount << std::endl;
	
	if (TTF_Init() == -1) {
		return;
	}
	TTF_Font* font = TTF_OpenFont("fonts/Arcade.ttf", 20);

	if (font == nullptr) {
		return;
	}

	SDL_Surface* tempSurfaceText;


	int tw, th;


	tempSurfaceText = TTF_RenderText_Blended(font, countToText().c_str(), { 255,0,0,255 });
	countText = SDL_CreateTextureFromSurface(renderer, tempSurfaceText);

	tempSurfaceText = TTF_RenderText_Blended(font, totalToText().c_str(), { 255,0,0,255 });
	totalTimeText = SDL_CreateTextureFromSurface(renderer, tempSurfaceText);

	tempSurfaceText = TTF_RenderText_Blended(font, averageToText().c_str(), { 255,0,0,255 });
	averageTimeText = SDL_CreateTextureFromSurface(renderer, tempSurfaceText);

	SDL_QueryTexture(countText, 0, 0, &tw, &th);
	dRectFont4 = { 140, 510, tw,th };
	SDL_QueryTexture(totalTimeText, 0, 0, &tw, &th);
	dRectFont5 = { 140, 540, tw,th };
	SDL_QueryTexture(averageTimeText, 0, 0, &tw, &th);
	dRectFont6 = { 140, 570, tw,th };

	SDL_FreeSurface(tempSurfaceText);
	TTF_CloseFont(font);

	this->simCount = 0;
	this->time -= this->time;

	this->render();
	this->board.renderBoard(renderer, window);
}


//initial text values and locations
bool Game::tft_init()
{
	if (TTF_Init() == -1) {
		return false;
	}
	TTF_Font* font = TTF_OpenFont("fonts/Arcade.ttf", 20);

	if (font == nullptr ) {
		return false;
	}
	SDL_Surface* tempSurfaceText;

	tempSurfaceText = TTF_RenderText_Blended(font, "Generate", { 255,0,0,255 });
	generateText = SDL_CreateTextureFromSurface(renderer, tempSurfaceText);

	tempSurfaceText = TTF_RenderText_Blended(font, "startSim", { 255,0,0,255 });
	startSimText = SDL_CreateTextureFromSurface(renderer, tempSurfaceText);

	tempSurfaceText = TTF_RenderText_Blended(font, "Stop sim", { 255,0,0,255 });
	stopSimText = SDL_CreateTextureFromSurface(renderer, tempSurfaceText);

	tempSurfaceText = TTF_RenderText_Blended(font, "Simulation count: ", { 255,0,0,255 });
	countText= SDL_CreateTextureFromSurface(renderer, tempSurfaceText);
	
	tempSurfaceText = TTF_RenderText_Blended(font, "Total time: ", { 255,0,0,255 });
	totalTimeText = SDL_CreateTextureFromSurface(renderer, tempSurfaceText);

	tempSurfaceText = TTF_RenderText_Blended(font, "Average time: ", { 255,0,0,255 });
	averageTimeText = SDL_CreateTextureFromSurface(renderer, tempSurfaceText);


	

	int tw, th;
	SDL_QueryTexture(generateText, 0, 0, &tw, &th);
	dRectFont1 = { 140, 470, tw,th };
	SDL_QueryTexture(startSimText, 0, 0, &tw, &th);
	dRectFont2 = { 265, 470, tw,th };
	SDL_QueryTexture(stopSimText, 0, 0, &tw, &th);
	dRectFont3 = { 390, 470, tw,th };

	SDL_QueryTexture(countText, 0, 0, &tw, &th);
	dRectFont4 = { 140, 510, tw,th };
	SDL_QueryTexture(totalTimeText, 0, 0, &tw, &th);
	dRectFont5 = { 140, 540, tw,th };
	SDL_QueryTexture(averageTimeText, 0, 0, &tw, &th);
	dRectFont6 = { 140, 570, tw,th};

	SDL_FreeSurface(tempSurfaceText);
	TTF_CloseFont(font);

	return true;
}
