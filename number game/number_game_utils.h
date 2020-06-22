#include <vector>
#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>

#ifndef NUMBER_GAME_UTILS
#define NUMBER_GAME_UTILS

void clear_screen();

void print_vector(std::vector<int> vector, int score);

void save_score(std::vector<int> guesses, int &score);

int guess_john(int lowest, int highest);

void play_with_john(int player);

void menu();

void play_game();

#endif