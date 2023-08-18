#include <iostream>
#include <string>
#include "Board.h"
#include "Cell.h"
#include "Move.h"
#include "Player.h"

int main() {
  Board board = Board(Player("White"), Player("Black"));
  Player* players[2] = {board.getFirstPlayer(), board.getSecondPlayer()};
  int playerIndex = 0;

  std::cout << "Welcome to the CLI chess application." << std::endl;
  std::cout << "Enter the commands in the format: piece from to" << std::endl;
  std::cout << "Use the following codes for piece:" << std::endl;
  std::cout << "Pawn: P" << std::endl << "Rook: R" << std::endl << "Knight: N" << std::endl << "Bishop: B" << std::endl << "Queen: Q" << std::endl << "King: K" << std::endl; 
  std::cout << "The white king starts the game on e1 and the black king on e8." << std::endl;
  std::cout << "To move the pawn in front of the king two steps, the command would be: P e2 e4" << std::endl;
  std::cout << "Use 0-0 for kingside castling and use 0-0-0 for queenside castling." << std::endl;
  std::cout << "Use the command print to print the contents of the board." << std::endl;

  while(!board.getFirstPlayer()->getCheckmate() && !board.getSecondPlayer()->getCheckmate()) {
    std::string input;
    Player* player = players[playerIndex];
    Player* opponent = players[(playerIndex+1)%2];
    player->setCurrentTurn(true);
    opponent->setCurrentTurn(false);
    std::cout << player->getColour() << "'s turn: ";
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

    // Castling
    if (input == "0-0" || input == "0-0-0") {
      bool kingSide = (input == "0-0") ? true : false;
      
      // Check if player can castle or not.
      if (!player->canCastle(kingSide, &board)) {
        std::cout << "Invalid move. Please try again." << std::endl;
        continue;
      }

      // Perform the castling.
    }

    // Check if the correct piece is present at the source cell.
    if (!board.checkPiecePresent(input[0], input.substr(2, 2))) {
      std::cout << "No " << Board::pieceMapper(input[0]) << " present at cell " << input.substr(2, 2) << ". Please try again." << std::endl;
      continue;
    }

    // Check if the piece present belongs to the player or not.
    if (!board.checkPieceBelongsToPlayer(board.findPiece(board.findCell(input.substr(2, 2))), player)) {
      std::cout << "The specified piece doesn't belong to the " << player->getColour() << " player. Please try again. " << std::endl;
      continue;
    }

    // If the piece exists create a move object.
    Cell* source = board.findCell(input.substr(2, 2));
    Cell* destination = board.findCell(input.substr(5, 2));
    Move move = Move(board.findPiece(source), source, destination);

    // Check if the move is a valid move or not.
    if (!move.checkValidMove(&board)) {
      std::cout << "Invalid move. Please try again." << std::endl;
      continue;
    }

    // Move the piece.
    move.movePiece(&board);

    // If the player's king is in check after the move, it is an invalid move.
    if (player->playerInCheck(&board)) {
      // Rollback the performed move.
      move.rollback(&board);
      std::cout << "Invalid move. Please try again." << std::endl;
      continue;
    }
    player->setCheck(false);

    // Pawn Promotion
    if (move.getPiece()->getType() == "pawn" && (destination->getRow() == 1 || destination->getRow() == 8)) {
      std::cout << "Your pawn has been promoted." << std::endl;
      std::cout << "Enter the code of the piece you wish it to be promoted to: ";
      std::string piece;

      // Get the input of what the piece will be promoted to.
      while (true) {
        std::getline(std::cin, piece);
        if (piece != "R" && piece != "N" && piece != "B" && piece != "Q") {
          std::cout << "Invalid code. Please enter again: ";
          continue;
        }
        break;
      }

      // Create the new piece.
      Piece* promoted;
      if (piece == "R") promoted = new Rook(player->getColour());
      if (piece == "N") promoted = new Knight(player->getColour());
      if (piece == "B") promoted = new Bishop(player->getColour());
      if (piece == "Q") promoted = new Queen(player->getColour());

      // Replace the pawn with the new piece.
      destination->setPiece(promoted);
    }

    // Checkmate
    
    // Does the opponent have a check threat from the player.
    if (opponent->playerInCheck(&board)) {
      opponent->setCheck(true);
      std::cout << opponent->getColour() << " is in check." << std::endl;
    }

    // Next player's turn.
    playerIndex = (playerIndex+1)%2;
  }
}
// Checkmate
// Castling
// En pass
// Draws