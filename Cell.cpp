#include "Cell.h"

// Default constructor for initialization.
Cell::Cell() {}

// Constructor for cells without a piece.
Cell::Cell(int i, int j) {
  Cell::assignCellName(i, j);
  empty = true;
}

// Constructor for cells with a piece.
Cell::Cell(int i, int j, Piece* p) {
  Cell::assignCellName(i, j);
  empty = false;
  piece = p;
}

// Function to assign the cell name to the cell.
void Cell::assignCellName(int i, int j) {
  cellName = char(97 + i) + char(49 + j);
}