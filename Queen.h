#pragma once
#include "ChessPiece.h"
class Queen :
    public ChessPiece
{
public:
    //constructor
    Queen(bool);
    //highlightMoves method for a queen piece
    virtual bool moves(ChessPiece***) const;
    //highlightMoves method for a queen piece
    virtual void highligthMoves(ChessPiece***, std::vector<std::pair<int, int>>&) const;
private:
};

