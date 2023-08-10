#include <string>
#include "Cell.h"

class Board {
  private:
    Cell board[8][8];

  public:
    Board();
    void printBoard();
    bool checkInput(std::string input);
    bool checkCell(char letter, char number);
    bool checkPiecePresent(char symbol, std::string cell);
    bool checkValidMove(std::string source, std::string destination);
    void movePiece(std::string source, std::string destination);
    std::string pieceMapper(char piece);
    Piece* findPiece(std::string cell);
};