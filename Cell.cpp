#include "Cell.h"

// Default constructor for initialization.
Cell::Cell() {}

// Constructor for cells without a piece.
Cell::Cell(int i, int j) {
  row = i+1;
  column = j+1;
  empty = true;
}

// Constructor for cells with a piece.
Cell::Cell(int i, int j, Piece* p) {
  row = i+1;
  column = j+1;
  empty = false;
  piece = p;
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