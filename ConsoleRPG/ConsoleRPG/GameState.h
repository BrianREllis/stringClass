#pragma once

enum STATE {INIT, MAIN, PLAY, GAME, EXIT};

//STATE mainMenu();

void splash();

void endProgram();

int getNumValid(int min, int max);

STATE currentLevel = INIT;

class GameState
{
	
public:
	void play();
	STATE update();
};