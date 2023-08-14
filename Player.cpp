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