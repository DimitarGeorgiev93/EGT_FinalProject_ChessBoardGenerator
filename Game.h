#pragma once

#include "ChessBoard.h"
#include "TextureManager.h"


class Game {
public:
	//constructor
	Game();
	//destructor
	~Game();
	//initializes starting values of the program, loads the textures 
	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
	//initial text values and locations
	bool tft_init();
	//default render function for the board, buttons and texts
	void render();
	//main event handler
	void handleEvents();
	//helper function to cleap up SDL members
	void clean();
	//bool function to help with the running of the main while cycle
	bool isRunning();

	//starts the simulation cycle
	void startSim();
	//stops the simulation cycle
	void stopSim();

private:
	//simulation texts helper functions
	std::string countToText();
	std::string totalToText();
	std::string averageToText();

	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	bool running;

	SDL_Texture* generateText, * startSimText, * stopSimText, * countText, * totalTimeText, *averageTimeText;
	SDL_Rect dRectFont1, dRectFont2, dRectFont3, dRectFont4, dRectFont5, dRectFont6;


	std::chrono::duration<double> time;

	//stores the nubmer of simulations in the current sim
	int simCount;

	//stops the simulation
	bool simStopper;
	//highligths current piece when clicked
	bool highligthed;
	//hides the "Generate" and "Start sim" buttons during a simulation
	bool hideButtons;

	ChessBoard board;

};