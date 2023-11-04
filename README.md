# Command Line Chess Application

## Introduction
This project simulates a chess application through the command line. The players can type in commands as described below to move the pieces and play the game. These commands are also available in the game text.

## Repository Structure
The repository contains the following sets of files. All the files are present in the root folder, and there are no sub-folders.
- *CMakeLists.txt:* This is the CMake configuration file used to build the application and create the executable file.
- *game.cpp:* This is the file containing the source code of the main function. This file contains the main logic behind running the game.
- *Various header (.h) and implementation (.cpp) files:* The .h files contain the templates of the different classes, and the .cpp files contain the implementation of those templates. The contents of the different classes are described below:
  - **Board:** It contains information and methods related to the chess board.
  - **Cell:** It contains information and methods related to a single cell of the chess board.
  - **Move:** It contains information and methods related to a single move performed by a player.
  - **Piece:** It contains information and methods related to a single piece present on the chess board.
  - **Player:** It contains information and methods related to a single player playing the game.

## Commands
The structure of various commands that can be used in the game are as follows:
- ***Moving a piece***
  - To move a piece, enter the commands in the format: piece from to.
  - Use the following codes for piece:
    - **Pawn:** P
    - **Rook:** R
    - **Knight:** N
    - **Bishop:** B
    - **Queen:** Q
    - **King:** K
  - Use the standard chessboard notation for references to the different cells. The notation must be in lowercase. The white king starts the game on e1 and the black king on e8.
  - Example: To move the pawn in front of the white king forward by two steps, the command would be: P e2 e4
- ***Castling:***
  Use 0-0 for kingside castling and use 0-0-0 for queenside castling.
- ***Requesting a draw:***
  Use the command draw to request a draw. The opponent can accept the draw request by typing draw and reject the request by typing anything else.
- ***Forfeiting the game:***
  Use the command forfeit to forfeit the game.
- ***Printing the contents of the board:***
  Since this is a command-line application, there can be a need to view the contents of the board from time to time. Use the command print to print the contents of the board.
