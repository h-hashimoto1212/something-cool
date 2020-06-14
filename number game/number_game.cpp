#include <iostream>

#include "number_game_utils.h"

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
