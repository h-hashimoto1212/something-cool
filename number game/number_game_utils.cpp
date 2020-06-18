#include "number_game_utils.h"

void clear_screen()
{
  std::cout << "\x1B[2J\x1B[H";
}

void print_vector(std::vector<int> vector, int score)
{
  for(int i = 0; i < vector.size() - 1; i++)
  {
    std::cout << vector[i] << "/";
  }
  std::cout << vector[vector.size() - 1] << std::endl;
}

void save_score(std::vector<int> guesses, int &score)
{
  std::ifstream input("scores.txt");

  int best_score;
  input >> best_score;

  std::ofstream output("scores.txt");
  if(score > best_score)
  {
    output << score;
    std::cout << "YOU GOT A BEST SCORE!" << std::endl;
  }
  else
  {
    output << best_score;
    score =  best_score;
    std::cout << "Best score: " << score << std::endl;
  }

}

void play_game()
{
  std::vector<int> guesses;
  int score;

  srand((int) time(0));
  int random = rand() % 1001;
  int lowest = 1;
  int highest = 1000;
  while(true)
  {
    int guess;
    score = 100;
    while(score > 0)
    {
      std::cout << "Guess a Number ( " << lowest << "to " << highest << "): ";
      std::cin >> guess;
      if(!std::cin)
      {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "Input must be an integer.\n"; 
        std::cout << "Guess a Number ( " << lowest << "to " << highest << "): ";
        std::cin >> guess;
      }
      guesses.push_back(guess);
      if(guess < lowest || guess > highest)
      {
        std::cout << "Number out of range.\nTry again." << std::endl;
      } else if(guess == random)
      {
        std::cout << "You win!\n" << "Your score: " << score << std::endl;
        break;
      } else if(guess < random)
      {
        score -= 1;
        lowest = guess + 1;
        std::cout << "Too low\n" << "Your score: " << score << std::endl;
      } else
      {
        score -= 1;
        highest = guess - 1;
        std::cout << "Too high\n" << "Your score: " << score << std::endl;
      }
    }
    if(score == 0){
      std::cout << "You lost the game\n" << "Correct number: " << random << std::endl;
      break;
    }
    break;
  }
  save_score(guesses, score);
  print_vector(guesses, score);
}