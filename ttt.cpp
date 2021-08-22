#include <iostream>
#include <vector>

#include "ttt_functions.hpp"


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
