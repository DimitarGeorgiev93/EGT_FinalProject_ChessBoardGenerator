#pragma once

#include <iostream>
#include "SDL.h"
#include <vector>


//case chess piece class
class ChessPiece
{
public:
	ChessPiece(char, bool);
	//virtual moves method, each piece follows different rules
	virtual bool moves(ChessPiece***) const= 0;
	//virtual highligthMoves method, each peice follows different rules ( similar to moves())
	virtual void highligthMoves(ChessPiece***, std::vector<std::pair<int, int>>&) const = 0;

	char getPiece() const;
	bool getColor() const;
	void setX(int);
	void setY(int);
	int getX() const;
	int getY() const;

	virtual ~ChessPiece();
protected:
	//board coordinates of the current piece
	int x, y;
	//type of the current piece (p = pawn, b = bishop, r = rook, n = knight, q = queen, k = king
	char piece;
	// true = white, uppercase // false = black, lowercase
	bool pieceColor;
};

