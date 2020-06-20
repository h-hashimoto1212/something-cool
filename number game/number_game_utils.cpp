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

void menu()
{
  int choice;
  do
  {
    std::cout << "0: Quit" << std::endl << "1: Play" << std::endl;
    std::cin >> choice;

    switch(choice)
    {
      case 0:
        std::cout << "Good Bye\n";
        std::exit(0);
      case 1:
        clear_screen();
        play_game();
        break;
    }
  } while (choice != 0);
}

void play_game()
{
  std::vector<int> guesses;
  int score;

  srand((int) time(0));
  int lowest = 1;
  int highest = 1000;
  int random = rand() % highest + 1;
  while(true)
  {
    int guess;
    score = 100;
    while(score > 0)
    {
      std::cout << "Your score: " << score << std::endl;
      std::cout << "Guess a Number ( " << lowest << "to " << highest << "):\n";
      std::cin >> guess;
      if(guess < lowest || guess > highest || !std::cin)
      {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "Input must be an integer wthin range.\n" << "Try again" << std::endl;
      } else if(guess == random)
      {
        guesses.push_back(guess);
        clear_screen();
        std::cout << guess << "\nYou win!\n" << "Your score: " << score << std::endl;
        break;
      } else if(guess < random)
      {
        guesses.push_back(guess);
        score -= 1;
        lowest = guess + 1;
        clear_screen();
        std::cout << guess << " is too low" << std::endl;
      } else
      {
        guesses.push_back(guess);
        score -= 1;
        highest = guess - 1;
        clear_screen();
        std::cout << guess << " is too high" << std::endl;
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