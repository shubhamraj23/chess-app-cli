#include "Player.h"
#include "Board.h"

// Default constructor for initialization.
Player::Player() {}

// Constructor for players specifying a colour.
Player::Player(std::string c) {
  colour = c;
  currentTurn = false;
  check = false;
  checkmate = false;
  kingMoved = false;
  kingSideRookMoved = false;
  queenSideRookMoved = false;
}

// Function to get the name of the player.
std::string Player::getColour() {
  return colour;
}

// Function to check if the current turn is of the player or not.
bool Player::getCurrentTurn() {
  return currentTurn;
}

// Function to set if the current turn is of the player or not.
void Player::setCurrentTurn(bool turn) {
  currentTurn = turn;
}

// Function to get if the player is under check.
bool Player::getCheck() {
  return check;
}

// Function to set if the player is under check.
void Player::setCheck(bool c) {
  check = c;
}

// Function to get if the player is under checkmate.
bool Player::getCheckmate() {
  return checkmate;
}

// Function to set if the player is under checkmate.
void Player::setCheckmate(bool c) {
  checkmate = c;
}

// Function to get all the piece locations of a player.
std::vector< Cell* >* Player::getPieceLocations() {
  return &pieceLocations;
}

// Function to add a new piece location to the list of existing piece locations.
void Player::addPieceLocation(Cell* cell) {
  pieceLocations.push_back(cell);
}

// Fuction to remove a piece location from the list of existing piece locations.
void Player::removePieceLocation(Cell* cell) {
  int index = 0;
  for (int i = 0; i < pieceLocations.size(); i++) {
    if (pieceLocations[i] == cell) {
      index = i;
      break;
    }
  }
  std::vector< Cell* >::iterator it = pieceLocations.begin() + index;
  pieceLocations.erase(it);
}

// Function to get king's cell.
Cell* Player::getKingCell() {
  return kingCell;
}

// Function to set king's cell.
void Player::setKingCell(Cell* cell) {
  kingCell = cell;
}

// Function to set the value of kingMoved.
void Player::setKingMoved(bool m) {
  kingMoved = m;
}

// Function to set the value of kingSideRookMoved.
void Player::setKingSideRookMoved(bool m) {
  kingSideRookMoved = m;
}

// Function to set the value of queenSideRookMoved.
void Player::setQueenSideRookMoved(bool m) {
  queenSideRookMoved = m;
}

// Function to see if the current player has a check threat from the opponent.
bool Player::playerInCheck(Board* board) {
  Player* opponent = (this == board->getFirstPlayer()) ? board->getSecondPlayer() : board->getFirstPlayer();
  std::vector< Cell* >* opponentPieceLocationsAddress = opponent->getPieceLocations();
  std::vector< Cell* > opponentPieceLocations = *opponentPieceLocationsAddress;
  for (int i = 0; i < opponentPieceLocations.size(); i++) {
    Cell* location = opponentPieceLocations[i];
    Piece* p = location->getPiece();
    if (p->isValid(location, kingCell, board)) return true; 
  }
  return false;
}

// Function to check if the player can castle or not.
bool Player::canCastle(bool side, Board* board) {

}