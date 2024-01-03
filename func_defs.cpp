#include <iostream>
#include <string>
#include <vector>

void print_board(std::vector<char> board) {
  std::cout << "     |     |     \n";
  std::cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  \n";
  std::cout << "_____|_____|_____\n";
  std::cout << "     |     |     \n";
  std::cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  \n";
  std::cout << "_____|_____|_____\n";
  std::cout << "     |     |     \n";
  std::cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  \n";
  std::cout << "     |     |     \n";
}



bool check_winner(std::vector<char> board) {
  if (board[0] == 'X' && board[1] == 'X' && board[2] == 'X') {
    std::cout << "Player 1 wins!\n";
    return true;
  } else if (board[0] == 'O' && board[1] == 'O' && board[2] == 'O') {
    std::cout << "Player 2 has won!\n";
    return true;
  } else if (board[3] == 'X' && board[4] == 'X' && board[5] == 'X') {
    std::cout << "Player 1 wins!\n";
    return true;
  } else if (board[3] == 'O' && board[4] == 'O' && board[5] == 'O') {
    std::cout << "Player 2 has won!\n";
    return true;
  } else if (board[6] == 'X' && board[7] == 'X' && board[8] == 'X') {
    std::cout << "Player 1 wins!\n";
    return true;
  } else if (board[6] == 'O' && board[7] == 'O' && board[8] == 'O') {
    std::cout << "Player 2 has won!\n";
    return true;
  } else if (board[0] == 'X' && board[3] == 'X' && board[6] == 'X') {
    std::cout << "Player 1 wins!\n";
    return true;
  } else if (board[0] == 'O' && board[3] == 'O' && board[6] == 'O') {
    std::cout << "Player 2 has won!\n";
    return true;
  } else if (board[1] == 'X' && board[4] == 'X' && board[7] == 'X') {
    std::cout << "Player 1 wins!\n";
    return true;
  } else if (board[1] == 'O' && board[4] == 'O' && board[7] == 'O') {
    std::cout << "Player 2 has won!\n";
    return true;
  } else if (board[2] == 'X' && board[5] == 'X' && board[8] == 'X') {
    std::cout << "Player 1 wins!\n";
    return true;
  } else if (board[2] == 'O' && board[5] == 'O' && board[8] == 'O') {
    std::cout << "Player 2 has won!\n";
    return true;
  } else if (board[0] == 'X' && board[4] == 'X' && board[8] == 'X') {
    std::cout << "Player 1 wins!\n";
    return true;
  } else if (board[0] == 'O' && board[4] == 'O' && board[8] == 'O') {
    std::cout << "Player 2 has won!\n";
    return true;
  } else if (board[6] == 'X' && board[4] == 'X' && board[2] == 'X') {
    std::cout << "Player 1 wins!\n";
    return true;
  } else if (board[6] == 'O' && board[4] == 'O' && board[2] == 'O') {
    std::cout << "Player 2 has won!\n";
    return true;
  } else {
    return false;
  }
}


void start_game(std::vector<char> board, int empty_spaces, bool player_1_turn, bool game_over, int player1, int player2) {
  while (!game_over) {
    //player 1's move
    while (player_1_turn && !game_over) {
      std::cout << "Player 1, please enter a number (0-8)..\n";
      std::cin >> player1;
      if (std::cin.fail()) {
        std::cout << "Invalid input. Please enter a number 0-8.\n";
        std::cin.clear(); // Clear the error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
      } else if (player1 > 8) {
        std::cout << "Number too large! Enter a number 0-8! Try again.\n";
      } else {
        if (board[player1] != ' ') {
          std::cout << "Cannot go there!\n";
        } else {
          board[player1] = 'X';
          player_1_turn = false;
          empty_spaces--;
          print_board(board);
          if (check_winner(board)) {
            game_over = true;
            break;
          }
        }
      }
    }
    while (!player_1_turn && !game_over) {
      if (empty_spaces == 0) {
        game_over = true;
        break;
      }
      std::cout << "Player 2, make your move..\n";
      std::cin >> player2;
      if (std::cin.fail()) {
        std::cout << "Invalid input. Please enter a number 0-8.\n";
        std::cin.clear(); // Clear the error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
      } else if (player2 > 8) {
        std::cout << "Number too large! Enter a number 0-8! Try again.\n";
      } else {
        if (board[player2] != ' ') {
          std::cout << "Cannot go there!\n";
        } else {
          board[player2] = 'O';
          player_1_turn = true;
          empty_spaces--;
          print_board(board);
          if (check_winner(board)) {
            game_over = true;
            break;
          }
        }
      }
    }
  }
  if (!check_winner(board)) {
    std::cout << "\n\nThis game is a draw..\n\n";
  }
}
