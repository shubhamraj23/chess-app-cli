# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.12)

# Set the project name
project(chess-app-cli)

# Add the executable and list your source files
add_executable(
  game
  game.cpp
  Board.cpp
  Cell.cpp
  Piece.cpp
)