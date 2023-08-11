#include "Player.h"

// Constructor
Player::Player(std::string n) {
  name = n;
  check = false;
  checkmate = false;
}

// Function to get the name of the player.
std::string Player::getName() {
  return name;
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