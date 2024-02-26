#include "Knight.h"

//constructor
Knight::Knight(bool pieceColor):ChessPiece('N',pieceColor)
{
}

//moves method for a knight piece
bool Knight::moves(ChessPiece*** board) const
{
	if (this->x - 2 >= 0 && this->y + 1 <= 7 && board[this->x - 2][this->y + 1] != nullptr) {
		if (this->pieceColor != board[this->x - 2][this->y + 1]->getColor()) {
			if (board[this->x - 2][this->y + 1]->getPiece() == 'k') return false;
			if (board[this->x - 2][this->y + 1]->getPiece() == 'K') return false;
		} 
	} 
	if (this->x - 2 >= 0 && this->y - 1 >= 0 && board[this->x - 2][this->y - 1] != nullptr) {
			if (this->pieceColor != board[this->x - 2][this->y - 1]->getColor()) {
				if (board[this->x - 2][this->y - 1]->getPiece() == 'k') return false;
				if (board[this->x - 2][this->y - 1]->getPiece() == 'K') return false;
			}
		}
	if (this->x - 1 >= 0 && this->y - 2 >= 0 && board[this->x - 1][this->y - 2] != nullptr) {
		if (this->pieceColor != board[this->x - 1][this->y - 2]->getColor()) {
			if (board[this->x - 1][this->y - 2]->getPiece() == 'k') return false;
			if (board[this->x - 1][this->y - 2]->getPiece() == 'K') return false;
		}
	} 
	if (this->x + 1 <= 7 && this->y - 2 >= 0 && board[this->x + 1][this->y - 2] != nullptr) {
		if (this->pieceColor != board[this->x + 1][this->y - 2]->getColor()) {
			if (board[this->x + 1][this->y - 2]->getPiece() == 'k') return false;
			if (board[this->x + 1][this->y - 2]->getPiece() == 'K') return false;
		}
	} 
	if (this->x + 2 <= 7 && this->y - 1 >= 0 && board[this->x + 2][this->y - 1] != nullptr) {
		if (this->pieceColor != board[this->x + 2][this->y - 1]->getColor()) {
			if (board[this->x + 2][this->y - 1]->getPiece() == 'k') return false;
			if (board[this->x + 2][this->y - 1]->getPiece() == 'K') return false;
		}
	} 
	if (this->x + 2 <= 7 && this->y + 1 <= 7 && board[this->x + 2][this->y + 1] != nullptr) {
		if (this->pieceColor != board[this->x + 2][this->y + 1]->getColor()) {
			if (board[this->x + 2][this->y + 1]->getPiece() == 'k') return false;
			if (board[this->x + 2][this->y + 1]->getPiece() == 'K') return false;
		}
	} 
	if (this->x + 1 <= 7 && this->y + 2 <= 7 && board[this->x + 1][this->y + 2] != nullptr) {
		if (this->pieceColor != board[this->x + 1][this->y + 2]->getColor()) {
			if (board[this->x + 1][this->y + 2]->getPiece() == 'k') return false;
			if (board[this->x + 1][this->y + 2]->getPiece() == 'K') return false;
		}
	} 
	if (this->x - 1 >= 0 && this->y + 2 <= 7 && board[this->x - 1][this->y + 2] != nullptr) {
		if (this->pieceColor != board[this->x - 1][this->y + 2]->getColor()) {
			if (board[this->x - 1][this->y + 2]->getPiece() == 'k') return false;
			if (board[this->x - 1][this->y + 2]->getPiece() == 'K') return false;
		}
	}
	return true;
}

//highligthMoves method for a knight piece
void Knight::highligthMoves(ChessPiece*** board, std::vector<std::pair<int, int>>& moves) const
{
	if (this->x - 2 >= 0 && this->y + 1 <= 7) {
		if (board[this->x - 2][this->y + 1] != nullptr && this->pieceColor != board[this->x - 2][this->y + 1]->getColor()) {
			moves.push_back(std::make_pair(x - 2, y + 1));
		}
		else if (board[this->x - 2][this->y + 1] == nullptr) {
			moves.push_back(std::make_pair(x - 2, y + 1));
		}
	}
	if (this->x - 2 >= 0 && this->y - 1 >= 0) {
		if (board[this->x - 2][this->y - 1] != nullptr && this->pieceColor != board[this->x - 2][this->y - 1]->getColor()) {
			moves.push_back(std::make_pair(x - 2, y - 1));
		}
		else if (board[this->x - 2][this->y - 1] == nullptr) {
			moves.push_back(std::make_pair(x - 2, y - 1));
		}
	}
	if (this->x - 1 >= 0 && this->y - 2 >= 0) {
		if (board[this->x - 1][this->y - 2] != nullptr && this->pieceColor != board[this->x - 1][this->y - 2]->getColor()) {
			moves.push_back(std::make_pair(x - 1, y - 2));
		}
		else if (board[this->x - 1][this->y - 2] == nullptr) {
			moves.push_back(std::make_pair(x - 1, y - 2));
		}
	}
	if (this->x + 1 <= 7 && this->y - 2 >= 0) {
		if (board[this->x + 1][this->y - 2] != nullptr && this->pieceColor != board[this->x + 1][this->y - 2]->getColor()) {
			moves.push_back(std::make_pair(x + 1, y - 2));
		}
		else if (board[this->x + 1][this->y - 2] == nullptr) {
			moves.push_back(std::make_pair(x + 1, y - 2));
		}
	}
	if (this->x + 2 <= 7 && this->y - 1 >= 0) {
		if (board[this->x + 2][this->y - 1] != nullptr && this->pieceColor != board[this->x + 2][this->y - 1]->getColor()) {
			moves.push_back(std::make_pair(x + 2, y - 1));
		}
		else if (board[this->x + 2][this->y - 1] == nullptr) {
			moves.push_back(std::make_pair(x + 2, y - 1));
		}
	}
	if (this->x + 2 <= 7 && this->y + 1 <= 7) {
		if (board[this->x + 2][this->y + 1] != nullptr && this->pieceColor != board[this->x + 2][this->y + 1]->getColor()) {
			moves.push_back(std::make_pair(x + 2, y + 1));
		}
		else if (board[this->x + 2][this->y + 1] == nullptr) {
			moves.push_back(std::make_pair(x + 2, y + 1));
		}
	}
	if (this->x + 1 <= 7 && this->y + 2 <= 7) {
		if (board[this->x + 1][this->y + 2] != nullptr && this->pieceColor != board[this->x + 1][this->y + 2]->getColor()) {
			moves.push_back(std::make_pair(x + 1, y + 2));
		}
		else if (board[this->x + 1][this->y + 2] == nullptr) {
			moves.push_back(std::make_pair(x + 1, y + 2));
		}
	}
	if (this->x - 1 >= 0 && this->y + 2 <= 7) {
		if (board[this->x - 1][this->y + 2] != nullptr && this->pieceColor != board[this->x - 1][this->y + 2]->getColor()) {
			moves.push_back(std::make_pair(x - 1, y + 2));
		}
		else if (board[this->x - 1][this->y + 2] == nullptr) {
			moves.push_back(std::make_pair(x - 1, y + 2));
		}
	}
}
