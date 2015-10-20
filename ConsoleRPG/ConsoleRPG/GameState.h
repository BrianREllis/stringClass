#pragma once
#include "GameState.h"
#include <iostream>
#include <random>
#include <string>

enum STATE {INIT, MAIN, PLAY, GAME, EXIT};
enum WEAPON { FISTS, STICK, DAGGER, SHORTSWORD, GREATAXE };

STATE currentLevel = INIT;

bool firstLaunch = true;

#pragma region Declarations
std::string displayWeapon();
bool checkExp();
void displayStats();
void levelUp();
int getNumValid();
int RNG();

//GameState Declarations
void splash();
void play();
void Adventure();

STATE mainMenu();
#pragma endregion Function declarations

#pragma region Stats
class playerStats
{
	public:
		std::string pName;

		int hp = 100;
		int minHp = 0;
		int maxHp = 100;

		int level = 1;

		int currentExp = 0;
		int maxExp = level * 100;

		int def = 1;
		int atk = 1;
		
		WEAPON pWeapon = STICK;
};

class mStats
{
	public:
		int hp = 20;
		int maxhp = 20;
		int atk = 5;

		int exp = 5;
};
#pragma endregion Player and Monster Stats

#pragma region Level Up
bool checkExp(int exp, int maxexp)
{
	if (exp >= maxexp)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void levelUp()
{
	playerStats pStats;

	char cChoice;
	bool validInput = false;

	pStats.level++;
	pStats.currentExp = 0;
	pStats.maxExp = pStats.level * 100;

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
	while (validInput == false)
	{
		switch (cChoice)
		{
		case 'a':
		case 'A':
			pStats.atk += 2;
			validInput = true;
			pStats.hp = pStats.maxHp;
			break;
		case 'd':
		case 'D':
			pStats.def += 2;
			validInput = true;
			pStats.hp = pStats.maxHp;
			break;
		case 'h':
		case 'H':
			pStats.maxHp += 10;
			validInput = true;
			pStats.hp = pStats.maxHp;
			break;
		default:
			validInput = false;
			break;
		}
	}

}
#pragma endregion Where the leveling info is kept

#pragma region Numerical Functions
int RNG(int min, int max)
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(min, max);
	int dice_roll = distribution(generator);

	return dice_roll;
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
#pragma endregion Functions that return number values

#pragma region Display Functions
void displayStats()
{
	playerStats pStats;
	std::cout << "+-----------------------+"                            << std::endl;
	std::cout << "|\tHP: " << pStats.hp << "/" << pStats.maxHp << "\t|" << std::endl;
	std::cout << "|\tATK: " << pStats.atk << "\t\t|"                    << std::endl;
	std::cout << "|\tWeapon: " << displayWeapon() << "\t|"              << std::endl;
	std::cout << "+-----------------------+"                            << std::endl;
}

std::string displayWeapon()
{
	playerStats pStats;
	std::string wString;

	switch (pStats.pWeapon)
	{
	case 0:
		wString = "Fists";
		return wString;
		break;
	case 1:
		wString = "Stick";
		return wString;
		break;
	case 2:
		wString = "Dagger";
		return wString;
		break;
	case 3:
		wString = "Shortsword";
		return wString;
		break;
	case 4:
		wString = "Greataxe";
		return wString;
		break;
	default:
		break;
	}
}
#pragma endregion They make shit show up on screen

#pragma region Game States

/*
#===================+
|					|
|		PLAY		|
|					|
#===================+
*/
void play()
{
	char cInput;
	bool invalidEntry = true;
	playerStats pStats;

	system("cls");
	if (firstLaunch)
	{
		std::cout << "Welcome to the realm, what do you wish to be called?" << std::endl;
		std::cin >> pStats.pName;
		std::cout << "So your name is " << pStats.pName << "? Interesting... But enough of that,"
			<< std::endl << "what would you like to do?\n\n" << std::endl;
		firstLaunch = false;
	}
	else
	{
		std::cout << "You return to town and though it seems longer," << std::endl <<
			"it appears that you were only in the forest for but a few minutes\n\n" << std::endl;
	}
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
			mainMenu();
			break;
		default:
			invalidEntry = true;
			break;
		}
	}
}
/*
#===================+
|					|
|		SPLASH		|
|					|
#===================+
*/
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
/*
#===================+
|					|
|	  ADVENTURE  	|
|					|
#===================+
*/
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
		std::cout << "You come to a split in the path, do you go [R]ight, [L]eft, or [T]urn back?" << std::endl;
		std::cin >> cInput;
		switch (cInput)
		{
			case 'l':
			case 'L':
				system("cls");
				std::cout << "You turn left and plunge deeper into the forest" << std::endl;
				break;
			case 'r':
			case 'R':
				system("cls");
				std::cout << "You turn to your right and continue to trudge deeper, unafraid" << std::endl;
				break;
			case 't':
			case 'T':
				//system("cls");
				isExploring = false;
				break;
			default:
				break;
		}
	}
}
/*
#===================+
|					|
|	  MAIN MENU 	|
|					|
#===================+
*/
STATE mainMenu()
{
	int iChoice = 0;


	system("cls");
	std::cout << "Main Menu Is working!" << std::endl;
	std::cout << "1:start game" << std::endl;
	std::cout << "2:Return to splash screen" << std::endl;
	std::cout << "3:Exit Game" << std::endl;

	switch (getNumValid(1, 3))
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
#pragma endregion Gameplay functions