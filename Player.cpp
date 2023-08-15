#include "Player.h"

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

// Function to get all the pieces of a player.
std::vector< Piece* >* Player::getPieces() {
  return &pieces;
}

// Function to add a new piece to the list of existing pieces.
void Player::addPiece(Piece* p) {
  pieces.push_back(p);
}

// Fuction to remove a piece from the list of existing pieces.
void Player::removePiece(Piece* p) {
  int index = 0;
  for (int i = 0; i < pieces.size(); i++) {
    if (pieces[i] == p) {
      index = i;
      break;
    }
  }
  std::vector< Piece* >::iterator it = pieces.begin() + index;
  pieces.erase(it);
}