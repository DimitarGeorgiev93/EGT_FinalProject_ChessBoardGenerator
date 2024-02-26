#pragma once
#include "ChessPiece.h"
class Pawn :
    public ChessPiece
{
public:
    //constructor
    Pawn(bool);

    //move method a pawn
    virtual bool moves(ChessPiece***) const;
    //highlightmoves method for a pawn
    virtual void highligthMoves(ChessPiece***, std::vector<std::pair<int, int>>&) const;
private:

};

