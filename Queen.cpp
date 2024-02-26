#include "Queen.h"

//construtor
Queen::Queen(bool chessPiece) : ChessPiece('Q', chessPiece)
{
}

//moves method for a queen piece
bool Queen::moves(ChessPiece*** board) const
{
	int temp = 1;
	while (this->x + temp <= 7) {
		if (board[this->x + temp][this->y] != nullptr) {
			if (this->pieceColor != board[this->x + temp][this->y]->getColor()) {
				if (board[this->x + temp][this->y]->getPiece() == 'k') return false;
				else if (board[this->x + temp][this->y]->getPiece() == 'K') return false;
				//std::cout << "asdasd" << std::endl;
				else break;
			}
			else break;
		}
		else temp++;
	}
	temp = 1;
	while (this->x - temp >= 0) {
		if (board[this->x - temp][this->y] != nullptr) {
			if (this->pieceColor != board[this->x - temp][this->y]->getColor()) {
				if (board[this->x - temp][this->y]->getPiece() == 'k') return false;
				else if (board[this->x - temp][this->y]->getPiece() == 'K') return false;
				else break;
			}
			else break;
		}
		else temp++;
	}
	temp = 1;
	while (this->y + temp <= 7) {
		if (board[this->x][this->y + temp] != nullptr) {
			if (this->pieceColor != board[this->x][this->y + temp]->getColor()) {
				if (board[this->x][this->y + temp]->getPiece() == 'k') return false;
				else if (board[this->x][this->y + temp]->getPiece() == 'K') return false;
				else break;
			}
			else break;
		}
		else temp++;
	}
	temp = 1;
	while (this->y - temp >= 0) {
		if (board[this->x][this->y - temp] != nullptr) {
			if (this->pieceColor != board[this->x][this->y - temp]->getColor()) {
				if (board[this->x][this->y - temp]->getPiece() == 'k') return false;
				else if (board[this->x][this->y - temp]->getPiece() == 'K') return false;
				else break;
			}
			else break;
		}
		else temp++;
	}
	temp = 1;
	while (this->x + temp <= 7 && this->y + temp <= 7) {
		if (board[this->x + temp][this->y + temp] != nullptr) {
			if (this->pieceColor != board[this->x + temp][this->y + temp]->getColor()) {
				if (board[this->x + temp][this->y+temp]->getPiece() == 'k') return false;
				else if (board[this->x + temp][this->y+temp]->getPiece() == 'K') return false;
				//std::cout << "asdasd" << std::endl;
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
				//std::cout << "asdasd" << std::endl;
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
				//std::cout << "asdasd" << std::endl;
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
				//std::cout << "asdasd" << std::endl;
				else break;
			}
			else break;
		}
		else temp++;
	}
	return true;
}

//highligthMoves method for a queen piece
void Queen::highligthMoves(ChessPiece*** board, std::vector<std::pair<int, int>>& moves)const
{
	int temp = 1;
	while (this->x + temp <= 7) {
		if (board[this->x + temp][this->y] == nullptr) {

			moves.push_back(std::make_pair(x + temp, y));
			temp++;
		}
		else if (this->pieceColor != board[this->x + temp][this->y]->getColor()) {
			moves.push_back(std::make_pair(x + temp, y));
			break;
		}
		else break;
	}
	temp = 1;
	while (this->x - temp >= 0) {
		if (board[this->x - temp][this->y] == nullptr) {

			moves.push_back(std::make_pair(x - temp, y));
			temp++;
		}
		else if (this->pieceColor != board[this->x - temp][this->y]->getColor()) {
			moves.push_back(std::make_pair(x - temp, y));
			break;
		}
		else break;
	}
	temp = 1;
	while (this->y + temp <= 7) {
		if (board[this->x][this->y + temp] == nullptr) {

			moves.push_back(std::make_pair(x, y + temp));
			temp++;
		}
		else if (this->pieceColor != board[this->x][this->y + temp]->getColor()) {
			moves.push_back(std::make_pair(x, y + temp));
			break;
		}
		else break;
	}
	temp = 1;
	while (this->y - temp >= 0) {
		if (board[this->x][this->y - temp] == nullptr) {

			moves.push_back(std::make_pair(x, y - temp));
			temp++;
		}
		else if (this->pieceColor != board[this->x][this->y - temp]->getColor()) {
			moves.push_back(std::make_pair(x, y - temp));
			break;
		}
		else break;
	}

	temp = 1;
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
