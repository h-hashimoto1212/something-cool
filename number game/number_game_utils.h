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

void menu();

void play_game();

#endif