#include <iostream>
#include <string>
#include "Board.h"
#include "Cell.h"
#include "Move.h"
#include "Player.h"

// Function declarations.
bool playerCheckAfterMove(Board board, std::string source, std::string destination);

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

      // Check if the player's king goes to check after the move.
      int row = player->getKingCell()->getRow();
      int column = (kingSide) ? 7 : 3;
      std::string kingSource = "e" + std::string(1, char(row+48));
      std::string kingDestination = std::string(1, char(column+96)) + std::string(1, char(row+48));
      if (playerCheckAfterMove(board, kingSource, kingDestination)) {
        std::cout << "Invalid move. Please try again." << std::endl;
        continue;
      }

      // Perform the castling. Use goto to go to checkmate.
      // Move the king.
      Cell* kingSourceCell = player->getKingCell();
      Cell* kingDestinationCell = board.findCell(kingDestination);
      Move kingMove = Move(board.findPiece(kingSourceCell), kingSourceCell, kingDestinationCell);
      kingMove.movePiece(&board);

      // Move the rook.
      int rookStartColumn = (kingSide) ? 8 : 1;
      int rookEndColumn = (kingSide) ? 6 : 4;
      std::string rookSource = std::string(1, char(rookStartColumn+96)) + std::string(1, char(row+48));
      std::string rookDestination = std::string(1, char(rookEndColumn+96)) + std::string(1, char(row+48));
      Cell* rookSourceCell = board.findCell(rookSource);
      Cell* rookDestinationCell = board.findCell(rookDestination);
      Move rookMove = Move(board.findPiece(rookSourceCell), rookSourceCell, rookDestinationCell);
      rookMove.movePiece(&board);

      // Checkmate
    
      // Does the opponent have a check threat from the player.
      if (opponent->playerInCheck(&board)) {
        opponent->setCheck(true);
        std::cout << opponent->getColour() << " is in check." << std::endl;
      }

      // Next player's turn.
      playerIndex = (playerIndex+1)%2;
      continue;
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

    // Check if the player's king goes to check after the move.
    if (playerCheckAfterMove(board, input.substr(2, 2), input.substr(5, 2))) {
      std::cout << "Invalid move. Please try again." << std::endl;
      continue;
    }

    // The move is valid. Move the piece.
    move.movePiece(&board);
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

// Helper functions go here
// Check if a  player goes in check after performing a move.
bool playerCheckAfterMove(Board board, std::string source, std::string destination) {
  // Find the player.
  Player* player = (board.getFirstPlayer()->getCurrentTurn()) ? board.getFirstPlayer() : board.getSecondPlayer();
  Player* opponent = (board.getFirstPlayer()->getCurrentTurn()) ? board.getSecondPlayer() : board.getFirstPlayer();

  // Move the piece.
  Cell* sourceCell = board.findCell(source);
  Cell* destinationCell = board.findCell(destination);
  Move move = Move(board.findPiece(sourceCell), sourceCell, destinationCell);
  move.movePiece(&board);

  // Check if the player goes in check.
  if (player->playerInCheck(&board)) return true;
  return false;
}