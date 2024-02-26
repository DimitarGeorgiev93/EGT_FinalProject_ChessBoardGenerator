#include "Bishop.h"


//constructor with an extra bool member for a bishop piece 
//exclusive to the bishops, true = white board bishop, false = black board bishop
Bishop::Bishop(bool pieceColor, bool bishopColor) : ChessPiece('B', pieceColor), bishopColor(bishopColor)
{
}

//moves method for a bishop piece
bool Bishop::moves(ChessPiece*** board) const
{
	int temp = 1;
	while (this->x + temp <= 7 && this->y + temp <= 7) {
		if (board[this->x + temp][this->y + temp] != nullptr) {
			if (this->pieceColor != board[this->x + temp][this->y + temp]->getColor()) {
				if (board[this->x + temp][this->y + temp]->getPiece() == 'k') return false;
				else if (board[this->x + temp][this->y + temp]->getPiece() == 'K') return false;
				else break;
			}
			else break;
		}
		else temp++;
	}
	temp = 1;
	while (this->x - temp >= 0 && this->y + temp <= 7) {
		if (board[this->x - temp][this->y + temp] != nullptr) {
			if (this->pieceColor != board[this->x - temp][this->y + temp]->getColor()) {
				if (board[this->x - temp][this->y + temp]->getPiece() == 'k') return false;
				else if (board[this->x - temp][this->y + temp]->getPiece() == 'K') return false;
				else break;
			}
			else break;
		}
		else temp++;
	}
	temp = 1;
	while (this->x - temp >= 0 && this->y - temp >= 0) {
		if (board[this->x - temp][this->y - temp] != nullptr) {
			if (this->pieceColor != board[this->x - temp][this->y - temp]->getColor()) {
				if (board[this->x - temp][this->y - temp]->getPiece() == 'k') return false;
				else if (board[this->x - temp][this->y - temp]->getPiece() == 'K') return false;
				else break;
			}
			else break;
		}
		else temp++;
	}
	temp = 1;
	while (this->x + temp <= 7 && this->y - temp >= 0) {
		if (board[this->x + temp][this->y - temp] != nullptr) {
			if (this->pieceColor != board[this->x + temp][this->y - temp]->getColor()) {
				if (board[this->x + temp][this->y - temp]->getPiece() == 'k') return false;
				else if (board[this->x + temp][this->y - temp]->getPiece() == 'K') return false;
				else break;
			}
			else break;
		}
		else temp++;
	}
	return true;
}

//highligthMoves method for a bishop piece
void Bishop::highligthMoves(ChessPiece*** board, std::vector<std::pair<int, int>>& moves) const
{
	int temp = 1;
	while (this->x + temp <= 7 && this->y + temp <= 7) {
		if (board[this->x + temp][this->y + temp] == nullptr) {

			moves.push_back(std::make_pair(x + temp, y + temp));
			temp++;
		}
		else if (this->pieceColor != board[this->x + temp][this->y + temp]->getColor()) {
			moves.push_back(std::make_pair(x + temp, y + temp));
			break;
		}
		else break;
	}
	temp = 1;
	while (this->x - temp >= 0 && this->y + temp <= 7) {
		if (board[this->x - temp][this->y + temp] == nullptr) {

			moves.push_back(std::make_pair(x - temp, y + temp));
			temp++;
		}
		else if (this->pieceColor != board[this->x - temp][this->y + temp]->getColor()) {
			moves.push_back(std::make_pair(x - temp, y + temp));
			break;
		}
		else break;
	}
	temp = 1;
	while (this->x - temp >= 0 && this->y - temp >= 0) {
		if (board[this->x - temp][this->y - temp] == nullptr) {

			moves.push_back(std::make_pair(x - temp, y - temp));
			temp++;
		}
		else if (this->pieceColor != board[this->x - temp][this->y - temp]->getColor()) {
			moves.push_back(std::make_pair(x - temp, y - temp));
			break;
		}
		else break;
	}
	temp = 1;
	while (this->x + temp <= 7 && this->y - temp >= 0) {
		if (board[this->x + temp][this->y - temp] == nullptr) {

			moves.push_back(std::make_pair(x + temp, y - temp));
			temp++;
		}
		else if (this->pieceColor != board[this->x + temp][this->y - temp]->getColor()) {
			moves.push_back(std::make_pair(x + temp, y - temp));
			break;
		}
		else break;
	}

}


bool Bishop::getBishopColor() const
{
	return this->bishopColor;
}
