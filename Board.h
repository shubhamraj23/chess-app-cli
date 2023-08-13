#ifndef BOARD_H
#define BOARD_H

#include <string>
#include "Cell.h"
#include "Piece.h"
#include "Player.h"

class Cell;
class Piece;

class Board {
  private:
    Cell board[8][8];

  public:
    Board(Player p1, Player p2);
    void printBoard();
    Cell* findCell(std::string cell);
    Piece* findPiece(Cell* cell);
    bool checkPiecePresent(char symbol, std::string cell);
    bool checkPieceBelongsToPlayer(Piece* p, Player player);
    static std::string pieceMapper(char piece);
    static bool checkCell(char letter, char number);
};

#endif