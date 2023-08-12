#include <string>

class Piece {
  protected:
    std::string colour;
    std::string type;
    bool alive;

  public:
    Piece(std::string colour);
    std::string getColour();
    std::string getType();
    bool getAlive();
    void setAlive(bool a);
    void move(Cell source, Cell destination);
    virtual bool isValid(Cell source, Cell destination, Board board) = 0;
};

class Pawn : public Piece {
  public:
    Pawn(std::string colour);
    bool isValid(Cell source, Cell destination, Board board) override;
};

class Rook : public Piece {
  public:
    Rook(std::string colour);
    bool isValid(Cell source, Cell destination, Board board) override;
};

class Knight : public Piece {
  public:
    Knight(std::string colour);
    bool isValid(Cell source, Cell destination, Board board) override;
};

class Bishop : public Piece {
  public:
    Bishop(std::string colour);
    bool isValid(Cell source, Cell destination, Board board) override;
};

class Queen : public Piece {
  public:
    Queen(std::string colour);
    bool isValid(Cell source, Cell destination, Board board) override;
};

class King : public Piece {
  public:
    King(std::string colour);
    bool isValid(Cell source, Cell destination, Board board) override;
};