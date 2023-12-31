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
    bool moved;

  public:
    Piece(std::string colour);
    Piece(const Piece& p);
    std::string getColour();
    std::string getType();
    bool getAlive();
    void setAlive(bool a);
    bool getMoved();
    void setMoved(bool m);
    virtual bool isValid(Cell* source, Cell* destination, Board* board) = 0;
};

class Pawn : public Piece {
  public:
    Pawn(std::string colour);
    Pawn(const Piece& p);
    bool isValid(Cell* source, Cell* destination, Board* board) override;
};

class Rook : public Piece {
  public:
    Rook(std::string colour);
    Rook(const Piece& p);
    bool isValid(Cell* source, Cell* destination, Board* board) override;
};

class Knight : public Piece {
  public:
    Knight(std::string colour);
    Knight(const Piece& p);
    bool isValid(Cell* source, Cell* destination, Board* board) override;
};

class Bishop : public Piece {
  public:
    Bishop(std::string colour);
    Bishop(const Piece& p);
    bool isValid(Cell* source, Cell* destination, Board* board) override;
};

class Queen : public Piece {
  public:
    Queen(std::string colour);
    Queen(const Piece& p);
    bool isValid(Cell* source, Cell* destination, Board* board) override;
};

class King : public Piece {
  public:
    King(std::string colour);
    King(const Piece& p);
    bool isValid(Cell* source, Cell* destination, Board* board) override;
};

#endif