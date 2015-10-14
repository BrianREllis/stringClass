#include <iostream>
#include <fstream>
#include "GameState.h"

class playerStats
{
	public:
		int hp = 100;
		int minHp = 0;
		int maxHp = 100;
		int level = 1;
		int atk = 1;
		int def = 1;
};

STATE mainMenu();

void levelUp()
{
	std::cout << "Health = " << pStats.hp << std::endl;
	std::cout << "Attack = " << pStats.atk << std::endl;
	std::cout << "Deffense = " << pStats.def << std::endl;
	system("pause");
	system("cls");
	std::cout << "YOU HAVE LEVELED UP!" << std::endl;
	std::cout << "Would you like to:" << std::endl;
	std::cout << "\tIncrease [A]ttack" << std::endl;
	std::cout << "\tIncrease [H]ealth" << std::endl;
	std::cout << "\tIncrease [D]efense" << std::endl;
	std::cin >> cChoice;

	switch (cChoice)
	{
	case 'a':
	case 'A':
		pStats.atk += 2;
		pStats.hp = pStats.maxHp;
		break;
	case 'd':
	case 'D':
		pStats.def += 2;
		pStats.hp = pStats.maxHp;
		break;
	case 'h':
	case 'H':
		pStats.maxHp += 10;
		pStats.hp = pStats.maxHp;
		break;
	case 'e':
	case 'E':
		isTesting = false;
	default:
		break;
	}
	
}

int main()
{
	levelUp();
	/*currentLevel = INIT;*/
	bool bPlaying = true;
	while (bPlaying)
	{
		switch (currentLevel)
		{
		case INIT:
			splash();
			break;
		case MAIN:
			mainMenu();
			break;
		case PLAY:
			&GameState::play;
			break;
		default:
			bPlaying = false;
			break;
		}
	}
	system("pause");
	return 0;
}

STATE mainMenu()
{
	int iChoice = 0;


	system("cls");
	std::cout << "Main Menu Is working!" << std::endl;
	std::cout << "1:start game" << std::endl;
	std::cout << "2:Return to splash screen" << std::endl;
	std::cout << "3:Exit Game" << std::endl;

	switch (getNumValid(1,3))
	{
	case 1:
		
		/*currentLevel = PLAY;
		return currentLevel;*/
	case 2: 
		currentLevel = INIT;
		return currentLevel;
	case 3: 
		currentLevel = EXIT;
		return currentLevel;
	default:
		break;
	}
}

void splash()
{

	system("cls");
	std::cout << "entered the splash screen!" << std::endl;
	std::cout << "Please press enter to begin" << std::endl;
	system("pause");
	currentLevel = MAIN;
	system("cls");
	mainMenu();
}

void GameState::play()
{
	std::cout << "Entered Play Gamestate!";
}

STATE GameState::update()
{
	static STATE currentLevel;
	return currentLevel;
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
}