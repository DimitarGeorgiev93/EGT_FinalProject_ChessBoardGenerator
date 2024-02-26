#include "ChessPiece.h"

ChessPiece::ChessPiece(char piece, bool pieceColor): piece(piece), pieceColor(pieceColor)
{
	//if the piece is black
	if (this->pieceColor == false) {
		this->piece = tolower(this->piece);
	}

	//initial values of an empty/non-assigned chess piece, not used
	this->x = -1;
	this->y = -1;
}


char ChessPiece::getPiece() const
{
	return this->piece;
}

bool ChessPiece::getColor() const
{
	return this->pieceColor;
}

void ChessPiece::setX(int x)
{
	this->x = x;
}

void ChessPiece::setY(int y)
{
	this->y = y;
}

int ChessPiece::getX() const
{
	return this->x;
}

int ChessPiece::getY() const
{
	return this->y;
}

ChessPiece::~ChessPiece()
{
	//std::cout << "deleting " << this->getPiece() << std::endl;
}
