#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
  private:
    std::string colour;
    bool check;
    bool checkmate;

  public:
    Player(std::string colour);
    std::string getColour();
    bool getCheck();
    void setCheck(bool c);
    bool getCheckmate();
    void setCheckmate(bool c);
};

#endif