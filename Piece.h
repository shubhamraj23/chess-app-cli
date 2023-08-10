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
    virtual bool isValid(std::string source, std::string destination) = 0;
    virtual void move(std::string source, std::string destination) = 0;
};

class Pawn : public Piece {
  public:
    Pawn(std::string colour);
    bool isValid(std::string source, std::string destination) override;
    void move(std::string source, std::string destination) override;
};

class Rook : public Piece {
  public:
    Rook(std::string colour);
    bool isValid(std::string source, std::string destination) override;
    void move(std::string source, std::string destination) override;
};

class Knight : public Piece {
  public:
    Knight(std::string colour);
    bool isValid(std::string source, std::string destination) override;
    void move(std::string source, std::string destination) override;
};

class Bishop : public Piece {
  public:
    Bishop(std::string colour);
    bool isValid(std::string source, std::string destination) override;
    void move(std::string source, std::string destination) override;
};

class Queen : public Piece {
  public:
    Queen(std::string colour);
    bool isValid(std::string source, std::string destination) override;
    void move(std::string source, std::string destination) override;
};

class King : public Piece {
  public:
    King(std::string colour);
    bool isValid(std::string source, std::string destination) override;
    void move(std::string source, std::string destination) override;
};