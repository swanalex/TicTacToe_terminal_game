#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "func_decl.hpp"
#include "func_defs.cpp"

int main() {
  // do stuff here
  int player1, player2;
  std::vector<char> board = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
  int empty_spaces = 9;
  bool player_1_turn = true;
  bool game_over = false;
  bool player1_wins, player2_wins = false;
  
  std::cout << "=============\n";
  std::cout << "Welcome to Tic-Tac-Toe!!\n";
  std::cout << "=============\n";

  start_game(board, empty_spaces, player_1_turn, game_over, player1, player2);
  


  std::cout << "=============\n";
  std::cout << "Thank you for playing Tic-Tac-Toe!!\n";
  std::cout << "=============\n";


  
}
