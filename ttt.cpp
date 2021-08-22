#include <iostream>
#include <vector>

#include "ttt_functions.hpp"

void draw_board(std::vector<char> board) {
    std::cout << "     |     |      \n";
    std::cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
    std::cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
    std::cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
    std::cout << "     |     |      \n";
    std::cout << "\n";
}

std::vector<char> take_input(char turn, std::vector<char> board) {
  int box;
  std::cout << turn << "'s turn.\nEnter box number: ";
  std::cin >> box;
  while (!(1 <= box <= 9) || board[box - 1] != ' '){
  std::cout << turn << "'s turn.\nEnter box number: ";
  std::cin >> box;
  }
  board[box - 1] = turn;
  return board;
}

char change_turn(char turn) {
  if (turn == 'X') {
    return 'O';
  } else {
    return 'X';
  }
}

bool check_game(std::vector<char> board) {
  char winner;
  if (board[0] == board[1] && board[1] == board[2] && board[2] != ' ') {
    winner = board[0];
    std::cout << winner << " wins\n";
    return true;
  } else if (board[3] == board[4] && board[4] == board[5] && board[5] != ' ') {
    winner = board[3];
    std::cout << winner << " wins\n";
    return true;
  } else if (board[6] == board[7] && board[7] == board[8] && board[8] != ' ') {
    winner = board[6];
    std::cout << winner << " wins\n";
    return true;
  } else if (board[0] == board[3] && board[3] == board[6] && board[6] != ' ') {
    winner = board[0];
    std::cout << winner << " wins\n";
    return true;
  } else if (board[1] == board[4] && board[4] == board[7] && board[7] != ' ') {
    winner = board[1];
    std::cout << winner << " wins\n";
    return true;
  } else if (board[2] == board[5] && board[5] == board[8] && board[8] != ' ') {
    winner = board[2];
    std::cout << winner << " wins\n";
    return true;
  } else if (board[0] == board[4] && board[4] == board[8] && board[8] != ' ') {
    winner = board[0];
    std::cout << winner << " wins\n";
    return true;
  } else if (board[2] == board[4] && board[4] == board[6] && board[6] != ' ') {
    winner = board[2];
    std::cout << winner << " wins\n";
    return true;
  } else {
    for (int i; i < board.size(); i++) {
      if (board[i] == ' ') {
        return false;
      }
    }
    std::cout << "Tie\n";
    return true;
  }  
}

int main() {
  std::vector<char> board = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
  draw_board(board);
  char turn = 'X';
  while (!check_game(board)) {
    board = take_input(turn, board);
    turn = change_turn(turn);
    draw_board(board);
  }
}