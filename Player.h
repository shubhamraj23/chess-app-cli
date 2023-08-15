#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Cell.h"
#include "Piece.h"

class Cell;
class Piece;
class Board;

class Player {
  private:
    std::string colour;
    bool check;
    bool checkmate;
    std::vector< Cell* > pieceLocations;
    Cell* kingCell;

  public:
    Player();
    Player(std::string colour);
    std::string getColour();
    bool getCheck();
    void setCheck(bool c);
    bool getCheckmate();
    void setCheckmate(bool c);
    std::vector< Cell* >* getPieceLocations();
    void addPieceLocation(Cell* cell);
    void removePieceLocation(Cell* cell);
    Cell* getKingCell();
    void setKingCell(Cell* cell);
    bool playerInCheck(Player* opponent, Board* board);
};

#endif