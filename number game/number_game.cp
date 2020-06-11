#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

void print_vector(std::vector<int> vector)
{
  for(int i = 0; i < vector.size() - 1; i++)
  {
    std::cout << vector[i] << "/";
  }
  std::cout << vector[vector.size() - 1] << std::endl;
}

void play_game()
{
  std::vector<int> guesses;

  int random = rand() % 251;
  std::cout << "Guess a Number (1 to 250): ";
  while(true)
  {
    int guess;
    int score = 100;
    while(score > 0)
    {
      std::cin >> guess;
      guesses.push_back(guess);
      if(guess == random)
      {
        std::cout << "You win!\n" << "Your score: " << score << std::endl;
        break;
      } else if(guess < random)
      {
        score -= 10;
        std::cout << "Too low\n" << "Your score: " << score << std::endl;
      } else
      {
        score -= 10;
        std::cout << "Too high\n" << "Your score: " << score << std::endl;
      }
    }
    if(score == 0){
      std::cout << "You lost the game\n" << "Correct number: " << random << std::endl;
      break;
    }
    break;
  }
  print_vector(guesses);
}

int main()
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
        return 0;
      case 1:
        play_game();
        break;
    }
  } while (choice != 0);
}
