#include "Move.h"

// Constructor
Move::Move(Piece* p, Cell s, Cell d) {
  piece = p;
  source = s;
  destination = d;
}

// Function to get the piece that is moving.
Piece* Move::getPiece() {
  return piece;
}

// Function to get the starting cell of the move.
Cell Move::getSource() {
  return source;
}

// Function to get the ending cell of the move.
Cell Move::getDestination() {
  return destination;
}

// Function to check if the move is a valid move or not.
bool Move::checkValidMove(Board board) {
  // Other checks. King goes in check. King still in check. //TODO
  return piece->isValid(source, destination, board);
}

// Function to move the piece from source to destination.
void Move::movePiece() {
  piece->move(source, destination);
}

// Function to check if the input provided by the user is correct or not.
bool Move::checkInput(std::string input) {
  if (input == "print") return true;
  if (input.length() != 7) return false;
  if (input[0] != 'P' && input[0] != 'R' && input[0] != 'N' && input[0] != 'B' && input[0] != 'Q' && input[0] != 'K') return false;
  if (input[1] != ' ' || input[4] != ' ') return false;
  if (!checkCell(input[2], input[3]) || !checkCell(input[5], input[6])) return false;
  return true;
}


// Helper functions.
// Function to check if the provided cell is a valid chess cell or not.
bool checkCell(char letter, char number) {
  if (int(letter) < 97 || int(letter) > 104) return false;
  if (int(number) < 49 || int(number) > 56) return false;
  return true;
}