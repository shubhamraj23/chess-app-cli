#ifndef MOVE_H
#define MOVE_H

#include <string>
#include "Board.h"
#include "Cell.h"
#include "Piece.h"
#include "Player.h"

class Board;
class Cell;
class Piece;
class Player;

class Move {
  private:
    Piece* piece;
    Cell* source;
    Cell* destination;

  public:
    Move(Piece* piece, Cell* source, Cell* destination);
    Piece* getPiece();
    Cell* getSource();
    Cell* getDestination();
    bool checkValidMove(Board* board);
    void movePiece(Board* board, bool checkmateMove);
    static bool checkInput(std::string input);
};

#endif