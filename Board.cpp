#include "Board.h"

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