#include "Player.h"
#include "Board.h"

// Default constructor for initialization.
Player::Player() {}

// Constructor for players specifying a colour.
Player::Player(std::string c) {
  colour = c;
  check = false;
  checkmate = false;
}

// Function to get the name of the player.
std::string Player::getColour() {
  return colour;
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

// Function to see if the current player has a check threat from the opponent.
bool Player::playerInCheck(Player* opponent, Board* board) {
  std::vector< Cell* >* opponentPieceLocationsAddress = opponent->getPieceLocations();
  std::vector< Cell* > opponentPieceLocations = *opponentPieceLocationsAddress;
  for (int i = 0; i < opponentPieceLocations.size(); i++) {
    Cell* location = opponentPieceLocations[i];
    Piece* p = location->getPiece();
    if (p->isValid(location, kingCell, board)) return true; 
  }
  return false;
}