#pragma once
#include "ChessPiece.h"
//#include "TextureManager.h"
class Bishop :
    public ChessPiece
{
public:
    //construtor
    Bishop(bool, bool);
    //moves method for a bishop piece
    virtual bool moves(ChessPiece***) const;

    //highligthMoves method for a bishop piece
    virtual void highligthMoves(ChessPiece***, std::vector<std::pair<int, int>>&) const;

    //returns the valie of the bishopColor bool member 
    bool getBishopColor() const;
private:
    bool bishopColor; //exclusive to the bishops, true = white board bishop, false = black board bishop
};

