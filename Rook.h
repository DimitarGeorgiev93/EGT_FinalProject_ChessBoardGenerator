#pragma once
#include "ChessPiece.h"
class Rook :
    public ChessPiece
{
public:
    //constructor
    Rook(bool);
    //moves method for a rook piece
    virtual bool moves(ChessPiece***) const;
    //highlightMoves method for a rook piece
    virtual void highligthMoves(ChessPiece***, std::vector<std::pair<int, int>>&) const;
private:
};

