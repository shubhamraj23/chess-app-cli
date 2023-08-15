#include "Move.h"

// Constructor
Move::Move(Piece* p, Cell* s, Cell* d) {
  piece = p;
  source = s;
  destination = d;
  capturedPiece = NULL;
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
void Move::movePiece(Board* board) {
  // Get the player and the opponent.
  Player* player = (board->getFirstPlayer()->getCurrentTurn()) ? board->getFirstPlayer() : board->getSecondPlayer();
  Player* opponent = (board->getFirstPlayer()->getCurrentTurn()) ? board->getSecondPlayer() : board->getFirstPlayer();

  // If the destination cell is not empty, remove the piece.
  if (!destination->getEmpty()) {
    Piece* p = destination->getPiece();
    p->setAlive(false);
    capturedPiece = p;
    opponent->removePieceLocation(destination);
  }

  // Move the piece.
  destination->setEmpty(false);
  destination->setPiece(piece);
  source->setEmpty(true);
  source->setPiece(NULL);
  player->removePieceLocation(source);
  player->addPieceLocation(destination);

  // If the moved piece was a king, set the new king location.
  if (piece->getType() == "king") player->setKingCell(destination);
}

// Function to rollback the move.
void Move::rollback(Board* board) {
  // Get the player and the opponent.
  Player* player = (board->getFirstPlayer()->getCurrentTurn()) ? board->getFirstPlayer() : board->getSecondPlayer();
  Player* opponent = (board->getFirstPlayer()->getCurrentTurn()) ? board->getSecondPlayer() : board->getFirstPlayer();

  // Move the piece back.
  source->setEmpty(false);
  source->setPiece(piece);
  destination->setEmpty(true);
  destination->setPiece(NULL);
  player->removePieceLocation(destination);
  player->addPieceLocation(source);

  // If the moved piece was a king, set the original king location.
  if (piece->getType() == "king") player->setKingCell(source);

  // If a piece was captured, place the original piece back on the board.
  if (capturedPiece != NULL) {
    capturedPiece->setAlive(true);
    destination->setEmpty(false);
    destination->setPiece(capturedPiece);
    opponent->addPieceLocation(destination);
  }
}

// Static Functions go here.
// Function to check if the input provided by the user is correct or not.
bool Move::checkInput(std::string input) {
  if (input == "print") return true;
  if (input.length() != 7) return false;
  if (input[0] != 'P' && input[0] != 'R' && input[0] != 'N' && input[0] != 'B' && input[0] != 'Q' && input[0] != 'K') return false;
  if (input[1] != ' ' || input[4] != ' ') return false;
  if (!Board::checkValidCell(input[2], input[3]) || !Board::checkValidCell(input[5], input[6])) return false;
  if (input.substr(2, 2) == input.substr(5, 2)) return false;
  return true;
}