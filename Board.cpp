#include <iostream>
#include <string>
#include "Board.h"

// Default Constructor for initialization.
Board::Board() {
  // Initialize the empty cells.
  for (int i=2; i<6; i++) {
    for (int j=0; j<8; j++) {
      board[i][j] = Cell(i, j);
    }
  }

  // Initialize the white pieces.
  // All the pawns.
  for (int j=0; j<8; j++) {
    Piece* p = new Pawn("white");
    board[1][j] = Cell(1, j, p);
  }

  // Both the rooks.
  Piece* p = new Rook("white");
  board[0][0] = Cell(0, 0, p);
  Piece* q = new Rook("white");
  board[0][7] = Cell(0, 7, q);

  // Both the knights.
  p = new Knight("white");
  board[0][1] = Cell(0, 1, p);
  q = new Knight("white");
  board[0][6] = Cell(0, 6, q);

  // Both the bishops.
  p = new Bishop("white");
  board[0][2] = Cell(0, 2, p);
  q = new Bishop("white");
  board[0][5] = Cell(0, 5, q);

  // Queen.
  p = new Queen("white");
  board[0][3] = Cell(0, 3, p);
  
  // King.
  p = new King("white");
  board[0][4] = Cell(0, 4, p);
  

  // Initialize the black pieces.
  // All the pawns.
  for (int j=0; j<8; j++) {
    Piece* p = new Pawn("black");
    board[6][j] = Cell(6, j, p);
  }

  // Both the rooks.
  p = new Rook("black");
  board[7][0] = Cell(7, 0, p);
  q = new Rook("black");
  board[7][7] = Cell(7, 7, q);

  // Both the knights.
  p = new Knight("black");
  board[7][1] = Cell(7, 1, p);
  q = new Knight("black");
  board[7][6] = Cell(7, 6, q);

  // Both the bishops.
  p = new Bishop("black");
  board[7][2] = Cell(7, 2, p);
  q = new Bishop("black");
  board[7][5] = Cell(7, 5, q);

  // Queen.
  p = new Queen("black");
  board[7][3] = Cell(7, 3, p);
  
  // King.
  p = new King("black");
  board[7][4] = Cell(7, 4, p);

}

// Function to print all the contents of the board.
void Board::printBoard() {
  for (int i=7; i>=0; i--) {
    for (int j=0; j<8; j++) {
      if (board[i][j].getEmpty()) {
        std::cout << std::string(12, ' ') << " ";
      }
      else {
        Piece* p = board[i][j].getPiece();
        std::string colour = p->getColour();
        std::string type = p->getType();
        int pad = 11 - colour.length() - type.length();
        int lpad = pad / 2;
        int rpad = pad - lpad;
        std::cout << std::string(lpad, ' ') << colour << " " << type << std::string(rpad, ' ') << " ";
      }
    }
    std::cout << std::endl;
  }
}

// Function to check if the input provided by the user is correct or not.
bool Board::checkInput(std::string input) {
  if (input == "print") return true;
  if (input.length() != 7) return false;
  if (input[0] != 'P' && input[0] != 'R' && input[0] != 'N' && input[0] != 'B' && input[0] != 'Q' && input[0] != 'K') return false;
  if (input[1] != ' ' || input[4] != ' ') return false;
  if (!checkCell(input[2], input[3]) || !checkCell(input[5], input[6])) return false;
  return true;
}

// Function to check if the provided cell is a valid chess cell or not.
bool Board::checkCell(char letter, char number) {
  if (int(letter) < 97 || int(letter) > 104) return false;
  if (int(number) < 49 || int(number) > 56) return false;
  return true;
}

// Function to check if the piece is present at the location or not.
bool Board::checkPiecePresent(char symbol, std::string cell) {
  Piece* p = findPiece(cell);
  if (p == NULL) return false;
  if (p->getType() != pieceMapper(symbol)) return false;
  return true;
}

// Function to check if the move is a valid move or not.
bool Board::checkValidMove(std::string source, std::string destination) {
  Piece* p = findPiece(source);
  // Other checks. King goes in check. King still in check.
  return p->isValid(source, destination);
}

// Function to move the piece from source to destination.
void Board::movePiece(std::string source, std::string destination) {
  Piece* p = findPiece(source);
  p->move(source, destination);
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

// Function to get the piece present on the cell.
Piece* Board::findPiece(std::string cell) {
  int row = int(cell[1] - 49);
  int column = int(cell[0] - 97);
  Cell c = board[row][column];
  if (c.getEmpty()) return NULL;
  return c.getPiece();
}