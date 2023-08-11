#include "Piece.h"

// Implementation for Piece Class
// Constructor
Piece::Piece(std::string c) {
  colour = c;
  alive = true;
}

// Function to get the colour of the piece.
std::string Piece::getColour() {
  return colour;
}

// Function to get the type of the piece.
std::string Piece::getType() {
  return type;
}

// Function to get if the piece is alive or not.
bool Piece::getAlive() {
  return alive;
}

// Function to set the alive status of a piece.
void Piece::setAlive(bool a) {
  alive = a;
}


// Implementation for Pawn Class
// Constructor
Pawn::Pawn(std::string c) : Piece(c) {
  type = "pawn";
}


// Implementation for Rook Class
// Constructor
Rook::Rook(std::string c) : Piece(c) {
  type = "rook";
}


// Implementation for Knight Class
// Constructor
Knight::Knight(std::string c) : Piece(c) {
  type = "knight";
}


// Implementation for Bishop Class
// Constructor
Bishop::Bishop(std::string c) : Piece(c) {
  type = "bishop";
}


// Implementation for Queen Class
// Constructor
Queen::Queen(std::string c) : Piece(c) {
  type = "queen";
}


// Implementation for King Class
// Constructor
King::King(std::string c) : Piece(c) {
  type = "king";
}