#include <string>
#include "Piece.h"

// Implementation for Piece Class
Piece::Piece(std::string c) {
  colour = c;
  alive = true;
}

// Implementation for Pawn Class
Pawn::Pawn(std::string c) : Piece(c) {
  type = "pawn";
}

// Implementation for Rook Class
Rook::Rook(std::string c) : Piece(c) {
  type = "rook";
}

// Implementation for Knight Class
Knight::Knight(std::string c) : Piece(c) {
  type = "knight";
}

// Implementation for Bishop Class
Bishop::Bishop(std::string c) : Piece(c) {
  type = "bishop";
}

// Implementation for Queen Class
Queen::Queen(std::string c) : Piece(c) {
  type = "queen";
}

// Implementation for King Class
King::King(std::string c) : Piece(c) {
  type = "king";
}