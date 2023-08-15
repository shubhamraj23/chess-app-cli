#include "Piece.h"
#include "Board.h"

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

// Function to move a piece from the source to the destination.
void Piece::move(Cell* source, Cell* destination, Player* opponent) {
  // If the destination cell is not empty, remove the piece.
  if (!destination->getEmpty()) {
    Piece* p = destination->getPiece();
    p->setAlive(false);
    opponent->removePiece(p);
    free(p);
  }

  // Move the piece.
  Piece* p = source->getPiece();
  destination->setEmpty(false);
  destination->setPiece(p);
  source->setEmpty(true);
  source->setPiece(NULL);
}

// Implementation for Pawn Class
// Constructor
Pawn::Pawn(std::string c) : Piece(c) {
  type = "pawn";
}

// Function to check if the move is a valid move or not for a pawn.
bool Pawn::isValid(Cell* source, Cell* destination, Board* board) {
  std::string colour = getColour();

  // If the destination cell has a piece of the same colour, the move is invalid.
  if (!destination->getEmpty() && board->checkCellPieceColour(destination, colour)) return false;
  
  // All the valid cases come here.
  // Pawn moves forward one step.
  // The column number is the same and destination cell should be empty.
  if (source->getColumn() == destination->getColumn() && destination->getEmpty()) {
    // If the piece is white, the row number must increment by one, else decrement by one.
    if (colour == "White" && (destination->getRow() == source->getRow() + 1)) return true;
    if (colour == "Black" && (destination->getRow() == source->getRow() - 1)) return true;
  }

  // Pawn moves forward two steps.
  // The column number is the same and destination cell should be empty.
  if (source->getColumn() == destination->getColumn() && destination->getEmpty()) {
    // This logic holds if the piece is a white piece.
    if (colour == "White") {
      // Source cell must have row number 2 and destination cell must have row number 4.
      if (source->getRow() == 2 && destination->getRow() == 4) {
        // The cell in the column at row number 3 must be empty.
        std::string cellName = std::string(1, char(96 + source->getColumn())) + std::string(1, '3');
        Cell* between = board->findCell(cellName);
        if (between->getEmpty()) return true; 
      }
    }

    // This logic holds if the piece is a black piece.
    if (colour == "Black") {
      // Source cell must have row number 7 and destination cell must have row number 5.
      if (source->getRow() == 7 && destination->getRow() == 5) {
        // The cell in the column at row number 6 must be empty.
        std::string cellName = std::string(1, char(96 + source->getColumn())) + std::string(1, '6');
        Cell* between = board->findCell(cellName);
        if (between->getEmpty()) return true; 
      }
    }
  }

  // Pawn captures a piece.
  // The destination cell is not empty.
  if (!destination->getEmpty()) {
    // The destination cell has a piece of different colour.
    if (!board->checkCellPieceColour(destination, colour)) {
      // The difference in column numbers must be either 1 or -1.
      if ((source->getColumn() == destination->getColumn() + 1 ) || (source->getColumn() == destination->getColumn() - 1)) {
        // If the piece is white, the row number must increment by one, else decrement by one.
        if (colour == "White" && (destination->getRow() == source->getRow() + 1)) return true;
        if (colour == "Black" && (destination->getRow() == source->getRow() - 1)) return true;
      }
    }
  }

  // En pass

  // If none of the conditions satisfy, the move is invalid.
  return false;
}


// Implementation for Rook Class
// Constructor
Rook::Rook(std::string c) : Piece(c) {
  type = "rook";
}

// Function to check if the move is a valid move or not for a rook.
bool Rook::isValid(Cell* source, Cell* destination, Board* board) {
  // All the invalid cases come here.
  // If the destination cell has a piece of the same colour.
  if (!destination->getEmpty() && board->checkCellPieceColour(destination, colour)) return false;

  // If both the row number and column number of source and destination are not the same.
  if (source->getRow() != destination->getRow() && source->getColumn() != destination->getColumn()) return false;

  // If any of the cells in between is not empty.
  // If the traversal is across the rows.
  if (source->getColumn() == destination->getColumn()) {
    int increment = (source->getRow() < destination->getRow()) ? 1: -1;
    for (int i = source->getRow() + increment; i != destination->getRow(); i += increment) {
      if (!board->checkCellEmpty(i - 1, source->getColumn() - 1)) return false;
    }
  }

  // If the traversal is across the columns.
  if (source->getRow() == destination->getRow()) {
    int increment = (source->getColumn() < destination->getColumn()) ? 1: -1;
    for (int i = source->getColumn() + increment; i != destination->getColumn(); i += increment) {
      if (!board->checkCellEmpty(source->getRow() - 1, i - 1)) return false;
    }
  }

  // If all the above cases are not true, it is a valid move.
  return true;
}


// Implementation for Knight Class
// Constructor
Knight::Knight(std::string c) : Piece(c) {
  type = "knight";
}

// Function to check if the move is a valid move or not for a knight.
bool Knight::isValid(Cell* source, Cell* destination, Board* board) {
  // If the destination cell has a piece of the same colour, the move is invalid.
  if (!destination->getEmpty() && board->checkCellPieceColour(destination, colour)) return false;

  // For a valid case, the product of absolute value of difference between source and destination must be 2.
  int diffRow = std::abs(source->getRow() - destination->getRow());
  int diffColumn = std::abs(source->getColumn() - destination->getColumn());
  if (diffRow * diffColumn == 2) return true;
  return false;
}


// Implementation for Bishop Class
// Constructor
Bishop::Bishop(std::string c) : Piece(c) {
  type = "bishop";
}

// Function to check if the move is a valid move or not for a bishop.
bool Bishop::isValid(Cell* source, Cell* destination, Board* board) {
  // All the invalid cases come here.
  // If the destination cell has a piece of the same colour.
  if (!destination->getEmpty() && board->checkCellPieceColour(destination, colour)) return false;

  // If the number of cells traversed along rows and columns is different.
  int diffRow = std::abs(source->getRow() - destination->getRow());
  int diffColumn = std::abs(source->getColumn() - destination->getColumn());
  if (diffRow != diffColumn) return false;

  // If any of the cells in between is not empty.
  int rowIncrement = (source->getRow() < destination->getRow()) ? 1: -1;
  int colIncrement = (source->getColumn() < destination->getColumn()) ? 1: -1;
  int i = source->getRow() + rowIncrement;
  int j = source->getColumn() + colIncrement;
  while (i != destination->getRow() && j != destination->getColumn()) {
    if (!board->checkCellEmpty(i - 1, j - 1)) return false;
    i += rowIncrement;
    j += colIncrement;
  }

  // If all the above cases are not true, it is a valid move.
  return true;
}

// Implementation for Queen Class
// Constructor
Queen::Queen(std::string c) : Piece(c) {
  type = "queen";
}

// Function to check if the move is a valid move or not for a queen.
bool Queen::isValid(Cell* source, Cell* destination, Board* board) {
  // If the destination cell has a piece of the same colour, the move is invalid.
  if (!destination->getEmpty() && board->checkCellPieceColour(destination, colour)) return false;

  // All the invalid cases come here.
  // If the difference is neither 0 for either row or column, nor equal.
  int diffRow = std::abs(source->getRow() - destination->getRow());
  int diffColumn = std::abs(source->getColumn() - destination->getColumn());
  if (diffRow != diffColumn && diffRow != 0 && diffColumn!= 0) return false;

  // If any of the cells in between is not empty.
  int rowIncrement = 0, colIncrement = 0;
  if (source->getRow() < destination->getRow()) rowIncrement = 1;
  if (source->getRow() > destination->getRow()) rowIncrement = -1;
  if (source->getColumn() < destination->getColumn()) colIncrement = 1;
  if (source->getColumn() > destination->getColumn()) colIncrement = -1;
  int i = source->getRow() + rowIncrement;
  int j = source->getColumn() + colIncrement;
  while (i != destination->getRow() && j != destination->getColumn()) {
    if (!board->checkCellEmpty(i - 1, j - 1)) return false;
    i += rowIncrement;
    j += colIncrement;
  }

  // If all the above cases are not true, it is a valid move.
  return true;
}


// Implementation for King Class
// Constructor
King::King(std::string c) : Piece(c) {
  type = "king";
}

// Function to check if the move is a valid move or not for a king.
bool King::isValid(Cell* source, Cell* destination, Board* board) {
  // If the destination cell has a piece of the same colour, the move is invalid.
  if (!destination->getEmpty() && board->checkCellPieceColour(destination, colour)) return false;

  // For a valid case, the absolute value of difference between source and destination must be 0 or 1.
  int diffRow = std::abs(source->getRow() - destination->getRow());
  int diffColumn = std::abs(source->getColumn() - destination->getColumn());
  if ((diffRow == 0 || diffRow == 1) && (diffColumn == 0 || diffColumn == 1)) return true;
  return false;
}