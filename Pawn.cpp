#include "Pawn.h"

Pawn::Pawn( bool color):ChessPiece('P',color)
{
}


//movement method for a pawn piece
bool Pawn::moves(ChessPiece*** board) const
{
	//movement for a white pawn
	if (this->pieceColor == true) {
		if (this->x - 1 >= 0 && this->y + 1 <= 7 && board[this->x - 1][this->y + 1] != nullptr) {
			if (board[this->x - 1][this->y + 1]->getPiece() == 'k') return false;
		}
		if (this->x - 1 >= 0 && this->y - 1 >= 0 && board[this->x - 1][this->y - 1] != nullptr){
			if (board[this->x - 1][this->y - 1]->getPiece() == 'k') return false;
		} 
	} 
	else {//movement for a black pawn
		if (this->x + 1 <= 7 && this->y + 1 <= 7 && board[this->x + 1][this->y + 1] != nullptr) {
			if (board[this->x + 1][this->y + 1]->getPiece() == 'K') return false;
		}
		if (this->x + 1 <= 7 && this->y - 1 >= 0 && board[this->x + 1][this->y - 1] != nullptr) {
			if (board[this->x + 1][this->y - 1]->getPiece() == 'K') return false;
		}
	} 
	return true;
}
//highligthMoves method for a pawn piece
void Pawn::highligthMoves(ChessPiece*** board, std::vector<std::pair<int, int>>& moves) const
{
	//for a white pawn
	if (this->pieceColor == true) {
		if (this->x - 1 >= 0 && board[this->x - 1][this->y] == nullptr) {
			moves.push_back(std::make_pair(x - 1, y));
		}
		if (this->x - 1 >= 0 && this->y + 1 <= 7 && board[this->x - 1][this->y + 1] != nullptr && board[this->x - 1][this->y + 1]->getColor() != this->pieceColor) {
			moves.push_back(std::make_pair(x - 1, y + 1));

		}
		if (this->x - 1 >= 0 && this->y - 1 >= 0 && board[this->x - 1][this->y - 1] != nullptr && board[this->x - 1][this->y - 1]->getColor() != this->pieceColor) {
			moves.push_back(std::make_pair(x - 1, y - 1));
		}
		if (this->x == 6 && board[5][this->y] == nullptr && board[4][this->y] == nullptr) {
			moves.push_back(std::make_pair(4, y));
		}
	} // for a black pawn
	else {
		if (this->x + 1 <= 7 && board[this->x + 1][this->y] == nullptr) {
			moves.push_back(std::make_pair(x + 1, y));
		}
		if (this->x + 1 <= 7 && this->y + 1 <= 7 && board[this->x + 1][this->y + 1] != nullptr && board[this->x + 1][this->y + 1]->getColor() != this->pieceColor) {
			moves.push_back(std::make_pair(x + 1, y + 1));

		}
		if (this->x + 1 <= 7 && this->y - 1 >= 0 && board[this->x + 1][this->y - 1] != nullptr && board[this->x + 1][this->y - 1]->getColor() != this->pieceColor) {
			moves.push_back(std::make_pair(x + 1, y - 1));
		}
		if (this->x == 1 && board[2][this->y] == nullptr && board[3][this->y] == nullptr) {
			moves.push_back(std::make_pair(3, y));
		}
	} 
}

