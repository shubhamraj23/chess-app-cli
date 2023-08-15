#ifndef PIECE_H
#define PIECE_H

#include <string>
#include "Cell.h"
#include "Player.h"

class Board;
class Cell;
class Player;

class Piece {
  protected:
    std::string colour;
    std::string type;
    bool alive;

  public:
    Piece(std::string colour);
    std::string getColour();
    std::string getType();
    bool getAlive();
    void setAlive(bool a);
    virtual bool isValid(Cell* source, Cell* destination, Board* board) = 0;
};

class Pawn : public Piece {
  public:
    Pawn(std::string colour);
    bool isValid(Cell* source, Cell* destination, Board* board) override;
};

class Rook : public Piece {
  public:
    Rook(std::string colour);
    bool isValid(Cell* source, Cell* destination, Board* board) override;
};

class Knight : public Piece {
  public:
    Knight(std::string colour);
    bool isValid(Cell* source, Cell* destination, Board* board) override;
};

class Bishop : public Piece {
  public:
    Bishop(std::string colour);
    bool isValid(Cell* source, Cell* destination, Board* board) override;
};

class Queen : public Piece {
  public:
    Queen(std::string colour);
    bool isValid(Cell* source, Cell* destination, Board* board) override;
};

class King : public Piece {
  public:
    King(std::string colour);
    bool isValid(Cell* source, Cell* destination, Board* board) override;
};

#endif