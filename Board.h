#include <string>
#include "Cell.h"

class Board {
  private:
    Cell board[8][8];

  public:
    Board();
    void printBoard();
    Cell findCell(std::string cell);
    Piece* findPiece(Cell cell);
    bool checkPiecePresent(char symbol, std::string cell);
    static std::string pieceMapper(char piece);
};