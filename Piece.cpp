#include "Board.h"
#include "Cell.h"

// Implementation for Piece Class
// Constructor
Piece::Piece(std::string c) {
  colour = c;
  alive = true;
}

// Function to get the colour of the piece.
std::string Piece::getColour() {
  return colour;
}

// Function to get the type of the piece.
std::string Piece::getType() {
  return type;
}

// Function to get if the piece is alive or not.
bool Piece::getAlive() {
  return alive;
}

// Function to set the alive status of a piece.
void Piece::setAlive(bool a) {
  alive = a;
}


// Implementation for Pawn Class
// Constructor
Pawn::Pawn(std::string c) : Piece(c) {
  type = "pawn";
}

bool Pawn::isValid(Cell source, Cell destination, Board board) {
  std::string colour = getColour();
  
  // All the valid cases come here.
  // Pawn moves forward one step.
  // The column number is the same and destination cell should be empty.
  if (source.getColumn() == destination.getColumn() && destination.getEmpty()) {
    // If the piece is white, the row number must increment by one, else decrement by one.
    if (colour == "white" && (destination.getRow() == source.getRow() + 1)) return true;
    if (colour == "black" && (destination.getRow() == source.getRow() - 1)) return true;
  }

  // Pawn moves forward two steps.
  // The column number is the same and destination cell should be empty.
  if (source.getColumn() == destination.getColumn() && destination.getEmpty()) {
    // This logic holds if the piece is a white piece.
    if (colour == "white") {
      // Source cell must have row number 2 and destination cell must have row number 4.
      if (source.getRow() == 2 && destination.getRow() == 4) {
        // The cell in the column at row number 3 must be empty.
        std::string cellName = std::string(1, char(96 + source.getColumn())) + std::string(1, '3');
        Cell between = board.findCell(cellName);
        if (between.getEmpty()) return true; 
      }
    }

    // This logic holds if the piece is a black piece.
    if (colour == "black") {
      // Source cell must have row number 7 and destination cell must have row number 5.
      if (source.getRow() == 7 && destination.getRow() == 5) {
        // The cell in the column at row number 6 must be empty.
        std::string cellName = std::string(1, char(96 + source.getColumn())) + std::string(1, '6');
        Cell between = board.findCell(cellName);
        if (between.getEmpty()) return true; 
      }
    }
  }

  // Pawn captures a piece.
  // The destination cell is not empty.
  if (!destination.getEmpty()) {
    // The difference in column numbers must be either 1 or -1.
    if ((source.getColumn() == destination.getColumn() + 1 ) || (source.getColumn() == destination.getColumn() - 1)) {
      // If the piece is white, the row number must increment by one, else decrement by one.
      if (colour == "white" && (destination.getRow() == source.getRow() + 1)) return true;
      if (colour == "black" && (destination.getRow() == source.getRow() - 1)) return true;
    }
  }

  // En pass
}


// Implementation for Rook Class
// Constructor
Rook::Rook(std::string c) : Piece(c) {
  type = "rook";
}


// Implementation for Knight Class
// Constructor
Knight::Knight(std::string c) : Piece(c) {
  type = "knight";
}


// Implementation for Bishop Class
// Constructor
Bishop::Bishop(std::string c) : Piece(c) {
  type = "bishop";
}


// Implementation for Queen Class
// Constructor
Queen::Queen(std::string c) : Piece(c) {
  type = "queen";
}


// Implementation for King Class
// Constructor
King::King(std::string c) : Piece(c) {
  type = "king";
}