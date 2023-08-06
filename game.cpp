#include <iostream>
#include <string>
#include "Board.h"

int main() {
  Board board = Board();
  std::string turn = "White";
  bool checkmate = false;

  std::cout << "Welcome to the CLI chess application." << std::endl;
  std::cout << "Enter the commands in the format: piece from to" << std::endl;
  std::cout << "Use the following codes for piece:" << std::endl;
  std::cout << "Pawn: P" << std::endl << "Rook: R" << std::endl << "Knight: N" << std::endl << "Bishop: B" << std::endl << "Queen: Q" << std::endl << "King: K" << std::endl; 
  std::cout << "The white king starts the game on e1 and the black king on e8." << std::endl;
  std::cout << "To move the pawn in front of the king two steps, the command would be: P e2 e4" << std::endl;
  std::cout << "Use the command print to print the contents of the board." << std::endl;

  while(!checkmate) {
    std::string input;
    std::cout << turn << "'s turn: ";
    std::cin >> input;
    
    if (input == "print") {
      board.printBoard();
      continue;
    }
  }  
}