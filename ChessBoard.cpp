#include "ChessBoard.h"
#include "TextureManager.h"

//constructor
ChessBoard::ChessBoard()
{
	//this->time = 0;
	//this->sims = 0;

	board = new ChessPiece**[8];
	for (int i = 0; i < 8; i++) {
		board[i] = new ChessPiece*[8];
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			board[i][j] = nullptr;
		}
	}
}

//fills the board with 24 random figures following the rules
void ChessBoard::fillBoard()
{
	//seed for the rand() function
	size_t timeTemp = time(NULL);
	srand(timeTemp);

	std::vector<int> tempArr;
	for (int i = 0; i < 64; i++) {
		tempArr.push_back(i);
	}

	//generates all 32 chess peices and pushes them into a vector
	std::vector<ChessPiece*> pieces;
	pieces.push_back(new King(true));
	pieces.push_back(new King(false));
	pieces.push_back(new Knight(true));
	pieces.push_back(new Knight(false));
	pieces.push_back(new Knight(true));
	pieces.push_back(new Knight(false));
	pieces.push_back(new Rook(true));
	pieces.push_back(new Rook(false));
	pieces.push_back(new Rook(true));
	pieces.push_back(new Rook(false));
	pieces.push_back(new Queen(true));
	pieces.push_back(new Queen(false));
	pieces.push_back(new Bishop(true,false));
	pieces.push_back(new Bishop(true,true));
	pieces.push_back(new Bishop(false, false));
	pieces.push_back(new Bishop(false, true));
	for (int i = 0; i < 16; i++) {
		if (i % 2 == 0) {
			pieces.push_back(new Pawn(false));
		}
		else pieces.push_back(new Pawn(true));
	}
	
	//places the 2 kings first
	int maxFigures = 2;
	while (maxFigures > 0) {
		int temp = rand() % tempArr.size();

		if (board[tempArr.at(temp) / 8][tempArr.at(temp) % 8] == nullptr) {
			ChessPiece* tempPtr = pieces.front();
			tempPtr->setX(tempArr.at(temp) / 8);
			tempPtr->setY(tempArr.at(temp) % 8);



			if (tempPtr->moves(board) == false) {
				continue;
			}

			board[tempArr.at(temp) / 8][tempArr.at(temp) % 8] = tempPtr;
			

			pieces.erase(pieces.begin());

			tempArr.erase(tempArr.begin() + temp);
			maxFigures--;
		}
	}
	//shuffles the remaining 30 chess pieces
	std::random_shuffle(pieces.begin(), pieces.end());

	// picks 22 of the remaining 30 figures at random and places them on the board
	maxFigures = 22;
	
	//if a figure cannot be placed 5 times for whatever reason, the vector with the remaining chess pieces gets shuffled again
	int shuffleCount = 0;

	while (maxFigures>0) {
		if (shuffleCount == 5) {
			std::random_shuffle(pieces.begin(), pieces.end());
			shuffleCount = 0;
		}
		int temp = rand() % tempArr.size();


		if (board[tempArr.at(temp) / 8][tempArr.at(temp) % 8] == nullptr) {
			ChessPiece* tempPtr = pieces.front();
			tempPtr->setX(tempArr.at(temp) / 8);
			tempPtr->setY(tempArr.at(temp) % 8);

			if (tempPtr->getPiece() == 'B' || tempPtr->getPiece() == 'b') {
				Bishop* tempBishop = (Bishop*)tempPtr;
				//white
				if (tempBishop->getBishopColor() == true && (tempPtr->getX() + tempPtr->getY()) %2 ==1) {
					shuffleCount++;
					continue;
				} else  // black
				if (tempBishop->getBishopColor() == false && (tempPtr->getX() + tempPtr->getY()) % 2 == 0) {
					shuffleCount++;
					continue;
				}
			}

			if (tempPtr->moves(board) == false) {

				shuffleCount++;
				continue;
			}
			board[tempArr.at(temp) / 8][tempArr.at(temp) % 8] = tempPtr;

			pieces.erase(pieces.begin());
			shuffleCount = 0;
			tempArr.erase(tempArr.begin()+temp);
			maxFigures--;
		}
	}
}

//renders the figures on the board
void ChessBoard::renderBoard(SDL_Renderer* renderer, SDL_Window* window) const
{
	int ww, wh;
	SDL_GetWindowSize(window, &ww, &wh);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j] != nullptr) {
				std::string tempStr(1, board[i][j]->getPiece());
				TextureManager::Instance()->drawTexture(tempStr, 50 +  board[i][j]->getX() * 45, ww / 2 - 180 + board[i][j]->getY() * 45, 45, 45, renderer);
				SDL_RenderPresent(renderer);
			}
		}
	}
}

//void ChessBoard::print() const
//{
//	std::cout << "black pieces, lowercase" << std::endl;
//	for (int i = 0; i < 8; i++) {
//		for (int j = 0; j < 8; j++) {
//			if (board[i][j] != nullptr) {
//				std::cout << board[i][j]->getPiece() << " ";
//			}
//			else std::cout << '_' << " ";
//		}
//		std::cout << std::endl;
//	}
//	std::cout << "white pieces, uppercase" << std::endl;
//}

//cleans the board of figures, used before a new combination is generated
void ChessBoard::cleanBoard()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			delete board[i][j];
			board[i][j] = nullptr;
		}
	}
}

//highlights the squres the currently selected figure can move to
void ChessBoard::highlightMoves(SDL_Renderer* renderer, int x, int y)
{
	if (x < 0 || x > 7 || y > 7 || y < 0) return;

	std::vector<std::pair<int, int>> availableMoves;
	this->board[x][y]->highligthMoves(this->board, availableMoves);

	for (std::pair<int, int> move : availableMoves) {
		TextureManager::Instance()->drawTexture("HL", 50 + move.first * 45,
			120 + move.second * 45, 45, 45, renderer);
	}

}
//returns a pointer to the currently selected chess pieceo or a nullptr 
ChessPiece* ChessBoard::highligthedPiece(int x, int y) const
{
	if (x < 0 || x > 7 || y > 7 || y < 0) return nullptr;
	if (this->board[x][y] != nullptr) {
		return board[x][y];
	}
	else return nullptr;
}

//destructor, frees the dynamic memory used for the chess pieces
ChessBoard::~ChessBoard()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			delete board[i][j];
			board[i][j] = nullptr;
		}
	}
	for (int i = 0; i < 8; i++) {
		delete[] board[i];
		board[i] = nullptr;
	}
	delete[] board;
}
