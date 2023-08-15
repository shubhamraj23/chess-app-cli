#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Piece.h"

class Piece;

class Player {
  private:
    std::string colour;
    bool check;
    bool checkmate;
    std::vector< Piece* > pieces;

  public:
    Player();
    Player(std::string colour);
    std::string getColour();
    bool getCheck();
    void setCheck(bool c);
    bool getCheckmate();
    void setCheckmate(bool c);
    std::vector< Piece* >* getPieces();
    void addPiece(Piece* p);
    void removePiece(Piece* p);
};

#endif