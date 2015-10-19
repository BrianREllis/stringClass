#include <iostream>
#include <random>
#include "GameState.h"


/*STATE mainMenu()
{
	system("cls");
	std::cout << "Main Menu Is working!" << std::endl;
	std::cout << "1:start game" << std::endl;
	std::cout << "2:Return to splash screen" << std::endl;
	std::cout << "3:Exit Game" << std::endl;

	switch (getNumValid(1, 3))
	{
		case 1: return PLAY;
		case 2: return INIT;
		case 3: return EXIT;
	}
}

void splash()
{
	system("cls");
	std::cout << "entered the splash screen!" << std::endl;
	system("pause");
	system("cls");
}

void GameState::play()
{
	std::cout << "Entered Play Gamestate!";
}

STATE GameState::update()
{
	int selection;
	return STATE::MAIN;
}

int getNumValid(int min, int max)
{
	int select;

	do
	{
		std::cout << "Enter a valid Number (" << min << "-" << max << ")" << std::endl;
		std::cin >> select;

		if (std::cin.fail() || select < min || select > max)
		{
			std::cin.clear();
			std::cin.ignore(80, '\n');
			std::cout << "Invalid entry." << std::endl;
		}
		else break;
	} while (true);

	return select;
}*/
