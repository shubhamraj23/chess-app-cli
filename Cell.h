#ifndef CELL_H
#define CELL_H

#include <string>
#include "Piece.h"

class Piece;

class Cell {
  private:
    int row;
    int column;
    bool empty;
    Piece* piece;

  public:
    Cell();
    Cell(int i, int j);
    Cell(int i, int j, Piece* p);
    Cell(const Cell& cell);
    int getRow();
    int getColumn();
    bool getEmpty();
    void setEmpty(bool e);
    Piece* getPiece();
    void setPiece(Piece* p);
};

#endif