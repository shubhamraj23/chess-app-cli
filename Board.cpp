#include "Board.h"

Board::Board() {
  // Initialize the empty cells.
  for (int i=2; i<6; i++) {
    for (int j=0; j<8; j++) {
      board[i][j] = Cell(i, j);
    }
  }
}