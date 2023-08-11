#include <string>

class Player {
  private:
    std::string name;
    bool check;
    bool checkmate;

  public:
    Player(std::string name);
    std::string getName();
    bool getCheck();
    void setCheck(bool c);
    bool getCheckmate();
    void setCheckmate(bool c);
};