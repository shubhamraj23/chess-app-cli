#include <string>

class Piece {
  protected:
    std::string colour;
    std::string type;
    bool alive;

  public:
    Piece(std::string colour);
    virtual bool isValid(std::string start, std::string end) = 0;
    virtual void move(std::string start, std::string end) = 0;
};

class Pawn : public Piece {
  public:
    Pawn(std::string colour);
    bool isValid(std::string start, std::string end) override;
    void move(std::string start, std::string end) override;
};

class Rook : public Piece {
  public:
    Rook(std::string colour);
    bool isValid(std::string start, std::string end) override;
    void move(std::string start, std::string end) override;
};

class Knight : public Piece {
  public:
    Knight(std::string colour);
    bool isValid(std::string start, std::string end) override;
    void move(std::string start, std::string end) override;
};

class Bishop : public Piece {
  public:
    Bishop(std::string colour);
    bool isValid(std::string start, std::string end) override;
    void move(std::string start, std::string end) override;
};

class Queen : public Piece {
  public:
    Queen(std::string colour);
    bool isValid(std::string start, std::string end) override;
    void move(std::string start, std::string end) override;
};

class King : public Piece {
  public:
    King(std::string colour);
    bool isValid(std::string start, std::string end) override;
    void move(std::string start, std::string end) override;
};