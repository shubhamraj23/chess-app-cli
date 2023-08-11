#include <iostream>
#include <string>
#include "Board.h"
#include "Move.h"
#include "Player.h"

int main() {
  Board board = Board();
  Player white = Player("White");
  Player black = Player("Black");
  Player players[2] = {white, black};
  int playerIndex = 0;

  std::cout << "Welcome to the CLI chess application." << std::endl;
  std::cout << "Enter the commands in the format: piece from to" << std::endl;
  std::cout << "Use the following codes for piece:" << std::endl;
  std::cout << "Pawn: P" << std::endl << "Rook: R" << std::endl << "Knight: N" << std::endl << "Bishop: B" << std::endl << "Queen: Q" << std::endl << "King: K" << std::endl; 
  std::cout << "The white king starts the game on e1 and the black king on e8." << std::endl;
  std::cout << "To move the pawn in front of the king two steps, the command would be: P e2 e4" << std::endl;
  std::cout << "Use the command print to print the contents of the board." << std::endl;

  while(!white.getCheckmate() && !black.getCheckmate()) {
    std::string input;
    Player player = players[playerIndex];
    Player opponent = players[(playerIndex+1)%2];
    std::cout << player.getName() << "'s turn: ";
    std::getline(std::cin, input);

    // Check if the input provided is correct or not.
    if (!Move::checkInput(input)) {
      std::cout << "Invalid input format. Please try again." << std::endl;
      continue;
    }
    
    // If the input is print, print all the contents of the board.
    if (input == "print") {
      board.printBoard();
      continue;
    }

    // Check if the correct piece is present at the source cell.
    if (!board.checkPiecePresent(input[0], input.substr(2, 2))) {
      std::cout << "No " << Board::pieceMapper(input[0]) << " present at cell " << input.substr(2, 2) << ". Please try again." << std::endl;
      continue;
    }

    // If the piece exists create a move object.
    Cell source = board.findCell(input.substr(2, 2));
    Cell destination = board.findCell(input.substr(5, 2));
    Move move = Move(board.findPiece(source), source, destination);

    // Check if the move is a valid move or not.
    if (!move.checkValidMove()) {
      std::cout << "Invalid move." << std::endl;
      continue;
    }

    // Move the piece.
    move.movePiece();

    // Check and checkmate.
  }
}