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
    bool currentTurn;
    bool check;
    bool checkmate;
    std::vector< Cell* > pieceLocations;
    Cell* kingCell;
    bool kingMoved;
    bool kingSideRookMoved;
    bool queenSideRookMoved;

  public:
    Player();
    Player(std::string colour);
    Player(const Player& player);
    std::string getColour();
    bool getCurrentTurn();
    void setCurrentTurn(bool turn);
    bool getCheck();
    void setCheck(bool c);
    bool getCheckmate();
    void setCheckmate(bool c);
    std::vector< Cell* >* getPieceLocations();
    void addPieceLocation(Cell* cell);
    void removePieceLocation(Cell* cell);
    void emptyLocations();
    Cell* getKingCell();
    void setKingCell(Cell* cell);
    void setKingMoved(bool m);
    void setKingSideRookMoved(bool m);
    void setQueenSideRookMoved(bool m);
    bool playerInCheck(Board* board);
    bool canCastle(bool side, Board* board);
};

#endif