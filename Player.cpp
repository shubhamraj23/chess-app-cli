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
}

// Copy Constructor for the player.
Player::Player(const Player& player) {
  colour = player.colour;
  currentTurn = player.currentTurn;
  check = player.check;
  checkmate = player.checkmate;
  kingCell = NULL;
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

// Function to empty the list of piece locations.
void Player::emptyLocations() {
  pieceLocations.clear();
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
  // Find the rook's initial position.
  int row = kingCell->getRow();
  int column = (side) ? 8 : 1;
  std::string rookPosition = std::string(1, char(column+96)) + std::string(1, char(row+48));
  Cell* rookCell = board->findCell(rookPosition);

  // Invalid cases come here.
  // If the rook or king have moved or the player is in check, the player cannot castle.
  bool kingMoved = kingCell->getPiece()->getMoved();
  bool rookMoved = rookCell->getPiece()->getMoved();
  if (rookMoved || kingMoved || check) return false;

  // If any cell in between the king and the rook is not empty, the player cannot castle.
  int increment = (side) ? 1 : -1;
  for (int i = 5 + increment; i != column; i += increment) {
    if (!board->checkCellEmpty(row - 1, i - 1)) return false;
  }

  // If all the above cases are not true, the player can castle.
  return true;
}