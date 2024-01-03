#include <iostream>
#include <string>
#include <vector>

void print_board(std::vector<char> board);
bool check_winner(std::vector<char> board);
void start_game(std::vector<char> board, int empty_spaces, bool player_1_turn, bool game_over, int player1, int player2);
