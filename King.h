#pragma once
#include "ChessPiece.h"

class King :
    public ChessPiece
{
public:
    //constructor
    King(bool);
    //move method for a king piece
    virtual bool moves(ChessPiece***) const;
    //highligthMoves method for a king piece
    virtual void highligthMoves(ChessPiece***, std::vector<std::pair<int, int>>&) const;
private:

};

