#include "Cell.h"

// Default constructor for initialization.
Cell::Cell() {}

// Constructor for cells without a piece.
Cell::Cell(int i, int j) {
  row = i+1;
  column = j+1;
  empty = true;
  piece = NULL;
}

// Constructor for cells with a piece.
Cell::Cell(int i, int j, Piece* p) {
  row = i+1;
  column = j+1;
  empty = false;
  piece = p;
}

// Copy Constructor for a cell.
Cell::Cell(const Cell& cell) {
  row = cell.row;
  column = cell.column;
  empty = cell.empty;
  if (cell.piece == NULL) {
    piece = NULL;
    return;
  }
  if ((*cell.piece).getType() == "pawn") piece = new Pawn(*cell.piece);
  if ((*cell.piece).getType() == "rook") piece = new Rook(*cell.piece);
  if ((*cell.piece).getType() == "knight") piece = new Knight(*cell.piece);
  if ((*cell.piece).getType() == "bishop") piece = new Bishop(*cell.piece);
  if ((*cell.piece).getType() == "queen") piece = new Queen(*cell.piece);
  if ((*cell.piece).getType() == "king") piece = new King(*cell.piece);
}

// Function to get the row number of the cell.
int Cell::getRow() {
  return row;
}

// Function to get column number of the cell.
int Cell::getColumn() {
  return column;
}

// Function to get the value of empty.
bool Cell::getEmpty() {
  return empty;
}

// Function to set the value of empty.
void Cell::setEmpty(bool e) {
  empty = e;
}

// Function to return the pointer to Piece.
Piece* Cell::getPiece() {
  return piece;
}

// Function to set the pointer to Piece.
void Cell::setPiece(Piece* p) {
  piece = p;
}