#include "Cell.h"

// Default constructor for initialization.
Cell::Cell() {}

// Constructor for cells without a piece.
Cell::Cell(int i, int j) {
  assignCellName(i, j);
  empty = true;
}

// Constructor for cells with a piece.
Cell::Cell(int i, int j, Piece* p) {
  assignCellName(i, j);
  empty = false;
  piece = p;
}

// Function to assign the cell name to the cell.
void Cell::assignCellName(int i, int j) {
  cellName = char(97 + j) + char(49 + i);
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