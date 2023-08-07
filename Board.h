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
};