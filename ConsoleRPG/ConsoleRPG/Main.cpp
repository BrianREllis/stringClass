#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "GameState.h"

STATE mainMenu();
/*
#===================+
|					|
|	MAIN FUNCTION	|
|					|
#===================+
*/
int main()
{
	system("pause");
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
			play();
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
		
		currentLevel = PLAY;
		return currentLevel;
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

void Adventure()
{
	srand(std::time(0));

	playerStats pStats;
	mStats mstats;

	int RNG = std::rand();
	bool isExploring = true;
	char cInput;

	system("cls");
	std::cout << "You take the trail out of town and into the forest..." << std::endl;
	while (isExploring)
	{
		std::cout << "You are attacked by a bandit!" << std::endl;
		displayStats();
		std::cout << "What will you do?\n\t[F]ight\n\t[R]eturn to town\n\t[H]eal" << std::endl;
		std::cin >> cInput;
		switch (cInput)
		{
		case 'F':
		case 'f':
			pStats.hp -= mstats.atk;
			displayStats();
			break;
		case 'R':
		case 'r':
			isExploring = false;
			break;
		case 'H':
		case 'h':
			break;
		default:
			break;
		}
	}
}

void splash()
{

	system("cls");
	std::cout << "\n\n\t#####  #   #  #####       ###    #    #  #####   ###   #####" << std::endl;
	std::cout << "\t  #    #   #  #          #   #   #    #  #      #        #  " << std::endl;
	std::cout << "\t  #    #####  ###       #   # #  #    #  ###     ###     #  " << std::endl;
	std::cout << "\t  #    #   #  #          #   #    #  #   #          #    #  " << std::endl;
	std::cout << "\t  #    #   #  #####       ### #    ##    #####   ###     #  " << std::endl;
	std::cout << "\n\n\n\n\t\t\t";
	system("pause");
	currentLevel = MAIN;
	system("cls");
	mainMenu();
}

void play()
{
	char cInput;
	bool invalidEntry = true;
	system("cls");
	std::cout << "Entered play gamestate!" << std::endl;
	std::cout << "Would you like to..." << std::endl;
	std::cout << "\t[A]dventure" << std::endl;
	std::cout << "\t[S]hop" << std::endl;
	std::cout << "\t[E]xit" << std::endl;
	std::cin >> cInput;
	while (invalidEntry)
	{
		switch (cInput)
		{
		case 'a':
		case 'A':
			invalidEntry = false;
			Adventure();
			break;
		case 's':
		case 'S':
			invalidEntry = false;
			break;
		case 'e':
		case 'E':
			invalidEntry = false;
			break;
		default:
			invalidEntry = true;
			break;
		}
	}
}