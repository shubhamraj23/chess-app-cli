#ifndef BOARD_H
#define BOARD_H

#include <string>
#include "Cell.h"
#include "Piece.h"
#include "Player.h"

class Cell;
class Piece;
class Player;

class Board {
  private:
    Cell board[8][8];
    Player p1;
    Player p2;

  public:
    Board(Player p1, Player p2);
    Board(const Board& board);
    Player* getFirstPlayer();
    Player* getSecondPlayer();
    void printBoard();
    Cell* findCell(std::string cell);
    Piece* findPiece(Cell* cell);
    bool checkPiecePresent(char symbol, std::string cell);
    bool checkPieceBelongsToPlayer(Piece* p, Player* player);
    bool checkCellPieceColour(Cell* cell, std::string colour);
    bool checkCellEmpty(int i, int j);
    static std::string pieceMapper(char piece);
    static bool checkValidCell(char letter, char number);
};

#endif