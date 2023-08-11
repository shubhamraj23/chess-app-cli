#include <string>
#include "Player.h"

// Constructor
Player::Player(std::string n) {
  name = n;
}

std::string Player::getName() {
  return name;
}

bool Player::getCheck() {
  return check;
}

void Player::setCheck(bool c) {
  check = c;
}

bool Player::getCheckmate() {
  return checkmate;
}

void Player::setCheckmate(bool c) {
  checkmate = c;
}