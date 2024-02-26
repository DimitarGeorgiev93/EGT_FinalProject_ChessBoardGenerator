#include "King.h"

//constructor
King::King( bool color):ChessPiece('K', color)
{
}

//move method for a king piece
bool King::moves(ChessPiece*** board) const
{

	if (x + 1 <= 7 && board[x + 1][y] != nullptr) return false;
	else if (x + 1 <= 7 && y+1 <= 7 && board[x + 1][y + 1] != nullptr) return false;
	else if (y + 1 <= 7 && board[x][y+1] != nullptr) return false;

	else if (x - 1 >= 0 && y + 1 <= 7 && board[x - 1 ][y + 1] != nullptr) return false;

	else if (x - 1  >= 0 && board[x - 1][y] != nullptr) return false;

	else if (x - 1 >= 0 && y - 1 >= 0 && board[x - 1][y - 1] != nullptr) return false;

	else if (y - 1 >= 0  && board[x][y - 1] != nullptr) return false;

	else if (x + 1 <= 7 && y - 1 >= 0 && board[x + 1][y - 1] != nullptr) return false;

	return true;
}

//highligthMoves method for a king piece
void King::highligthMoves(ChessPiece*** board, std::vector<std::pair<int, int>>& moves) const
{
	//1
	if (x + 1 <= 7 && board[x + 1][y] == nullptr) {
		moves.push_back(std::make_pair(x + 1, y));
	}
	else if (x + 1 <= 7 && board[x + 1][y] != nullptr && this->pieceColor != board[x + 1][y]->getColor()) {
		moves.push_back(std::make_pair(x + 1, y));
	}


	//2
	if (x + 1 <= 7 && y + 1 <= 7 && board[x + 1][y + 1] == nullptr) {
		moves.push_back(std::make_pair(x + 1, y + 1));
	}
	else if (x + 1 <= 7 && y + 1 <= 7 && board[x + 1][y + 1] != nullptr && this->pieceColor != board[x + 1][y + 1]->getColor()) {
		moves.push_back(std::make_pair(x + 1, y + 1));
	}

	//3
	if (y + 1 <= 7 && board[x][y + 1] == nullptr) {
		moves.push_back(std::make_pair(x, y + 1));
	}
	else if (y + 1 <= 7 && board[x][y + 1] != nullptr && this->pieceColor != board[x][y + 1]->getColor()) {
		moves.push_back(std::make_pair(x, y + 1));
	}

	//4
	if (x - 1 >= 0 && y + 1 <= 7 && board[x - 1][y + 1] == nullptr) {
		moves.push_back(std::make_pair(x - 1, y + 1));
	}
	else if (x - 1 >= 0 && y + 1 <= 7 && board[x - 1][y + 1] != nullptr && this->pieceColor != board[x - 1][y + 1]->getColor()) {
		moves.push_back(std::make_pair(x - 1, y + 1));
	}

	//5
	if (x - 1 >= 0 && board[x - 1][y] == nullptr) {
		moves.push_back(std::make_pair(x - 1, y));
	}
	else if (x - 1 >= 0 && board[x - 1][y] != nullptr && this->pieceColor != board[x - 1][y]->getColor()) {
		moves.push_back(std::make_pair(x - 1, y));
	}
	//6
	if (x - 1 >= 0 && y - 1 >= 0 && board[x - 1][y - 1] == nullptr) {
		moves.push_back(std::make_pair(x - 1, y - 1));
	}
	else if (x - 1 >= 0 && y - 1 >= 0 && board[x - 1][y - 1] != nullptr && this->pieceColor != board[x - 1][y - 1]->getColor()) {
		moves.push_back(std::make_pair(x - 1, y - 1));
	}

	//7
	if (y - 1 >= 0 && board[x][y - 1] == nullptr) {
		moves.push_back(std::make_pair(x, y - 1));
	}
	else if (y - 1 >= 0 && board[x][y - 1] != nullptr && this->pieceColor != board[x][y - 1]->getColor()) {
		moves.push_back(std::make_pair(x, y - 1));
	}
	//8
	if (x + 1 <= 7 && y - 1 >= 0 && board[x + 1][y - 1] == nullptr) {
		moves.push_back(std::make_pair(x + 1, y - 1));
	}
	else if (x + 1 <= 7 && y - 1 >= 0 && board[x + 1][y - 1] != nullptr && this->pieceColor != board[x + 1][y - 1]->getColor()) {
		moves.push_back(std::make_pair(x + 1, y - 1));
	}
}
