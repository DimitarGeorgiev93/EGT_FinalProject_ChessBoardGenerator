#pragma once

#include "utility.h"


//class ChessBoard, holds the 64 fiends ( each pointing to a figure or to a nullptr )
class ChessBoard
{
public:
	//constructor
	ChessBoard();
	//fills the board with 24 random figures following the rules
	//void fillBoard(SDL_Renderer*, SDL_Window*);
	void fillBoard();
	//renders the full board
	void renderBoard(SDL_Renderer*, SDL_Window*) const;
	//cleans the board of figures
	void cleanBoard();
	//highlights squres the current figure can move 
	void highlightMoves(SDL_Renderer*,int,int);
	//returns a pointer to the currently selected chess piece
	ChessPiece* highligthedPiece(int,int) const;
	//destructor
	~ChessBoard();
private:

	//two dimensional array of ChessPiece pointers
	ChessPiece*** board;

};

