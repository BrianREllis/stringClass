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

//PUT BACK IN FOR COMBAT!


//std::cout << "You are attacked by a bandit!" << std::endl;
//displayStats();
//std::cout << "What will you do?\n\t[F]ight\n\t[R]eturn to town\n\t[H]eal" << std::endl;
//std::cin >> cInput;
//switch (cInput)
//{
//case 'F':
//case 'f':
//	pStats.hp -= mstats.atk;
//	displayStats();
//	break;
//case 'R':
//case 'r':
//	isExploring = false;
//	break;
//case 'H':
//case 'h':
//	break;
//default:
//	break;
//}