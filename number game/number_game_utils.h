#include <vector>

#ifndef NUMBER_GAME_UTILS
#define NUMBER_GAME_UTILS

void print_vector(std::vector<int> vector, int score);

void save_score(std::vector<int> guesses, int &score);

void play_game();

#endif