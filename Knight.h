#pragma once
#include "ChessPiece.h"

class Knight :
    public ChessPiece
{
public:
    //costructor
    Knight(bool);
    //moves method for a knight piece
    virtual bool moves(ChessPiece***) const;
    //highlightMoves method for a knight piece
    virtual void highligthMoves(ChessPiece***, std::vector<std::pair<int, int>>&)const;
private:

};

