#include <string>
#include "Piece.h"

class Cell {
  private:
    std::string cellName;
    bool empty;
    Piece* piece;

  public:
    Cell();
    Cell(int i, int j);
    Cell(int i, int j, Piece* p);
    bool getEmpty();
    void setEmpty(bool e);
    Piece* getPiece();
    void setPiece(Piece* p);
};