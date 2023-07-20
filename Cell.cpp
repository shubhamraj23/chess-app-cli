#include "Cell.h"

Cell::Cell() {
  
}

Cell::Cell(int i, int j) {
  Cell::assignCellName(i, j);
  empty = true;
}

Cell::Cell(int i, int j, Piece* p) {
  Cell::assignCellName(i, j);
  empty = false;
  piece = p;
}

void Cell::assignCellName(int i, int j) {
  cellName = char(97 + i) + char(49 + j);
}