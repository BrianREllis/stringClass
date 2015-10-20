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