#include "Move.h"

// Constructor
Move::Move(Piece* p, Cell* s, Cell* d) {
  piece = p;
  source = s;
  destination = d;
}

// Function to get the piece that is moving.
Piece* Move::getPiece() {
  return piece;
}

// Function to get the starting cell of the move.
Cell* Move::getSource() {
  return source;
}

// Function to get the ending cell of the move.
Cell* Move::getDestination() {
  return destination;
}

// Function to check if the move is a valid move or not.
bool Move::checkValidMove(Board* board) {
  return piece->isValid(source, destination, board);
}

// Function to move the piece from source to destination.
void Move::movePiece(Board* board, bool opponentMove) {
  // Get the player and the opponent.
  Player* player; 
  Player* opponent;
  if (opponentMove) {
    player = (board->getFirstPlayer()->getCurrentTurn()) ? board->getSecondPlayer() : board->getFirstPlayer();
    opponent = (board->getFirstPlayer()->getCurrentTurn()) ? board->getFirstPlayer() : board->getSecondPlayer();
  }
  else {
    player = (board->getFirstPlayer()->getCurrentTurn()) ? board->getFirstPlayer() : board->getSecondPlayer();
    opponent = (board->getFirstPlayer()->getCurrentTurn()) ? board->getSecondPlayer() : board->getFirstPlayer();
  }

  // If the destination cell is not empty, remove the piece.
  if (!destination->getEmpty()) {
    Piece* p = destination->getPiece();
    p->setAlive(false);
    opponent->removePieceLocation(destination);
  }

  // Move the piece.
  destination->setEmpty(false);
  destination->setPiece(piece);
  source->setEmpty(true);
  source->setPiece(NULL);
  player->removePieceLocation(source);
  player->addPieceLocation(destination);
  piece->setMoved(true);

  // If the moved piece was a king, set the new king location.
  if (piece->getType() == "king") player->setKingCell(destination);
}

// Check if the move is a valid enpass move.
bool Move::enPassCheck(std::string prevMove) {
  if (prevMove.size() != 7) return false;

  // Check if the last move was a pawn moving two pieces.
  int steps = std::abs(prevMove[3] - prevMove[6]);
  if (prevMove[0] != 'P' || steps != 2) return false;

  // The piece moving must be a pawn.
  if (piece->getType() == "pawn") {
    // Destination cell must be empty.
    if (destination->getEmpty()) {
      // The difference in column numbers must be either 1 or -1.
      if ((source->getColumn() == destination->getColumn() + 1 ) || (source->getColumn() == destination->getColumn() - 1)) {
        // Destination column must be same as that of previously moved pawn.
        if (destination->getColumn() == (prevMove[5] - 'a') + 1) {
          if (piece->getColour() == "White") {
            if (source->getRow() == 5 && destination->getRow() == 6) return true;
          }
          if (piece->getColour() == "Black") {
            if (source->getRow() == 4 && destination->getRow() == 3) return true;
          }
        }
      }
    }
  }

  // If the any of the above case is not true, return false.
  return false;
}

// Static Functions go here.
// Function to check if the input provided by the user is correct or not.
bool Move::checkInput(std::string input) {
  if (input == "print" || input == "0-0" || input == "0-0-0") return true;
  if (input.length() != 7) return false;
  if (input[0] != 'P' && input[0] != 'R' && input[0] != 'N' && input[0] != 'B' && input[0] != 'Q' && input[0] != 'K') return false;
  if (input[1] != ' ' || input[4] != ' ') return false;
  if (!Board::checkValidCell(input[2], input[3]) || !Board::checkValidCell(input[5], input[6])) return false;
  if (input.substr(2, 2) == input.substr(5, 2)) return false;
  return true;
}