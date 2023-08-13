#include <iostream>
#include "Board.h"

// Default Constructor for initialization.
Board::Board(Player p1, Player p2) {
  // Initialize the empty cells.
  for (int i=2; i<6; i++) {
    for (int j=0; j<8; j++) {
      board[i][j] = Cell(i, j);
    }
  }

  // Initialize the white pieces.
  // All the pawns.
  for (int j=0; j<8; j++) {
    Piece* p = new Pawn(p1.getColour());
    board[1][j] = Cell(1, j, p);
  }

  // Both the rooks.
  Piece* p = new Rook(p1.getColour());
  board[0][0] = Cell(0, 0, p);
  Piece* q = new Rook(p1.getColour());
  board[0][7] = Cell(0, 7, q);

  // Both the knights.
  p = new Knight(p1.getColour());
  board[0][1] = Cell(0, 1, p);
  q = new Knight(p1.getColour());
  board[0][6] = Cell(0, 6, q);

  // Both the bishops.
  p = new Bishop(p1.getColour());
  board[0][2] = Cell(0, 2, p);
  q = new Bishop(p1.getColour());
  board[0][5] = Cell(0, 5, q);

  // Queen.
  p = new Queen(p1.getColour());
  board[0][3] = Cell(0, 3, p);
  
  // King.
  p = new King(p1.getColour());
  board[0][4] = Cell(0, 4, p);
  

  // Initialize the black pieces.
  // All the pawns.
  for (int j=0; j<8; j++) {
    Piece* p = new Pawn(p2.getColour());
    board[6][j] = Cell(6, j, p);
  }

  // Both the rooks.
  p = new Rook(p2.getColour());
  board[7][0] = Cell(7, 0, p);
  q = new Rook(p2.getColour());
  board[7][7] = Cell(7, 7, q);

  // Both the knights.
  p = new Knight(p2.getColour());
  board[7][1] = Cell(7, 1, p);
  q = new Knight(p2.getColour());
  board[7][6] = Cell(7, 6, q);

  // Both the bishops.
  p = new Bishop(p2.getColour());
  board[7][2] = Cell(7, 2, p);
  q = new Bishop(p2.getColour());
  board[7][5] = Cell(7, 5, q);

  // Queen.
  p = new Queen(p2.getColour());
  board[7][3] = Cell(7, 3, p);
  
  // King.
  p = new King(p2.getColour());
  board[7][4] = Cell(7, 4, p);

}

// Function to print all the contents of the board.
void Board::printBoard() {
  for (int i=7; i>=0; i--) {
    for (int j=0; j<8; j++) {
      if (board[i][j].getEmpty()) {
        std::cout << std::string(14, ' ') << " ";
      }
      else {
        Piece* p = board[i][j].getPiece();
        std::string colour = p->getColour();
        std::string type = p->getType();
        int pad = 13 - colour.length() - type.length();
        int lpad = pad / 2;
        int rpad = pad - lpad;
        std::cout << std::string(lpad, ' ') << colour << " " << type << std::string(rpad, ' ') << " ";
      }
    }
    std::cout << std::endl;
  }
}

// Function to find a chess cell associated with the given cellname.
Cell* Board::findCell(std::string cell) {
  int row = int(cell[1] - 49);
  int column = int(cell[0] - 97);
  return &board[row][column];
}

// Function to get the piece present on the cell.
Piece* Board::findPiece(Cell* c) {
  if (c->getEmpty()) return NULL;
  return c->getPiece();
}

// Function to check if the piece is present at the location or not.
bool Board::checkPiecePresent(char symbol, std::string cell) {
  Cell* c = findCell(cell);
  Piece* p = findPiece(c);
  if (p == NULL) return false;
  if (p->getType() != pieceMapper(symbol)) return false;
  return true;
}

// Function to check if the piece belongs to the player or not.
bool Board::checkPieceBelongsToPlayer(Piece* p, Player player) {
  if (p->getColour() == player.getColour()) return true;
  return false;
}

// Function to map the character of a piece to its type.
std::string Board::pieceMapper(char piece) {
  switch(piece) {
    case 'R':
      return "rook";
    case 'N':
      return "knight";
    case 'B':
      return "bishop";
    case 'Q':
      return "queen";
    case 'K':
      return "king";
    default:
      return "pawn";
  }
}

// Function to check if the provided cell is a valid chess cell or not.
bool Board::checkCell(char letter, char number) {
  if (int(letter) < 97 || int(letter) > 104) return false;
  if (int(number) < 49 || int(number) > 56) return false;
  return true;
}