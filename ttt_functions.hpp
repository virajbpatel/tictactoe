#include <iostream>
#include <vector>

void draw_board(std::vector<char> board);
std::vector<char> take_input(char turn, std::vector<char> board);
char change_turn(char turn);
bool check_game(std::vector<char> board);