#include <string>
#include "Cell.h"
#include "Piece.h"

class Move {
  private:
    Piece* piece;
    Cell source;
    Cell destination;

  public:
    Move(Piece* piece, Cell source, Cell destination);
    Piece* getPiece();
    Cell getSource();
    Cell getDestination();
    bool checkValidMove();
    void movePiece();
    static bool checkInput(std::string input);
};