#include "gameMenu.h"
#include "boardBackend.h"
#include "boardFrontend.h"
#include <conio.h>
#include <iostream>
#include <string>
#include <windows.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13
#define COLOR_MAIN 15
#define COLOR_HIGHLIGHT 8

using namespace std;

const string mainMenuItems[4] = {
	"World select",
	"How to play",
	"About us",
	"Exit"
};

const string winMenuItems[2] = {
	"Next Level",
	"Exit"
};

int mainMenuColors[4] = { COLOR_HIGHLIGHT, COLOR_MAIN, COLOR_MAIN, COLOR_MAIN };

int menuCounter = 0;

int winMenuColors[2] = { COLOR_HIGHLIGHT, COLOR_MAIN };

struct level_select_colors {
	int world1[3] = { COLOR_MAIN, COLOR_MAIN, COLOR_MAIN };
	int world2[3] = { COLOR_MAIN, COLOR_MAIN, COLOR_MAIN };
	int world3[3] = { COLOR_MAIN, COLOR_MAIN, COLOR_MAIN };
} levelSelectColors;

/*CHARACTERS FOR CELLS*/


char boardCharacters[11] = { 218, 191, 192, 217, 194, 193, 195, 180, 197, 196, 179 };

/*
boardCharacters[static_cast<int>(BOARD_CHARACTERS::topLeftCorner)]
boardCharacters[static_cast<int>(BOARD_CHARACTERS::topRightCorner)]
boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomLeftCorner)]
boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomRightCorner)]
boardCharacters[static_cast<int>(BOARD_CHARACTERS::topToBottom)]
boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomToTop)]
boardCharacters[static_cast<int>(BOARD_CHARACTERS::leftToRight)]
boardCharacters[static_cast<int>(BOARD_CHARACTERS::rightToLeft)]
boardCharacters[static_cast<int>(BOARD_CHARACTERS::cross)]
boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)]
boardCharacters[static_cast<int>(BOARD_CHARACTERS::verticalLine)]
*/

void setTextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void goToXY(short x, short y)
{
	COORD cords;
	cords.X = x;
	cords.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cords);
}

void setAllMainMenuColors(int val)
{
	for (int i = 0; i < 4; i++)
	{
		mainMenuColors[i] = val;
	}
}

void setAllWinMenuColors(int val)
{
	for (int i = 0; i < 2; i++)
	{
		winMenuColors[i] = val;
	}
}

void updateMainMenuColors(int num)
{
	setAllMainMenuColors(COLOR_MAIN);

	mainMenuColors[num] = COLOR_HIGHLIGHT;
}

void updateWinMenuColors(int num)
{
	setAllWinMenuColors(COLOR_MAIN);

	winMenuColors[num] = COLOR_HIGHLIGHT;
}


void setAllWorldColors(int world[], int color)
{
	for (int i = 0; i < 3; i++)
	{
		world[i] = color;
	}
}

void setSpecificWorldColor(int world[], int level, int color)
{
	world[level] = color;
}

void printWorldOne(int currentlySelected)
{
	system("cls");

	setAllWorldColors(levelSelectColors.world1, COLOR_MAIN);

	setSpecificWorldColor(levelSelectColors.world1, currentlySelected, COLOR_HIGHLIGHT);

	setTextColor(COLOR_MAIN);

	cout << "World 1" << endl;
	cout << endl;

	cout << "   " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topRightCorner)] << "  " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topRightCorner)] << "  " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topRightCorner)] << endl;
	
	cout << "   " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::verticalLine)];
	setTextColor(levelSelectColors.world1[0]);
	cout << " 1 ";
	setTextColor(COLOR_MAIN);
	cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::leftToRight)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)];
	cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::rightToLeft)];
	setTextColor(levelSelectColors.world1[1]);
	cout << " 2 ";
	setTextColor(COLOR_MAIN);
	cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::leftToRight)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)];
	cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::rightToLeft)];
	setTextColor(levelSelectColors.world1[2]);
	cout << " 3 ";
	setTextColor(COLOR_MAIN);
	cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::verticalLine)] <<" > "<< endl;

	cout << "   " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomRightCorner)] << "  " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomRightCorner)] << "  " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)]<< boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomRightCorner)] << endl;
	
	char typedChar = _getch();

	if (typedChar == 'a' || typedChar == 'A')
	{
		currentlySelected = (currentlySelected > 0) ? currentlySelected - 1 : currentlySelected;

		printWorldOne(currentlySelected);
	}

	if (typedChar == 'd' || typedChar == 'D')
	{
		if (currentlySelected < 2)
		{
			currentlySelected++;

			printWorldOne(currentlySelected);
		}
		else
		{
			currentlySelected = 0;

			printWorldTwo(currentlySelected);
		}
	}

	if (typedChar == KEY_ENTER)
	{

		system("cls");

		startWorldGen(WORLD_CODES::worldOne, static_cast<LEVEL_CODES>(currentlySelected));

		printBoard();

	}

	printWorldOne(currentlySelected);
}

void printWorldTwo(int currentlySelected)
{
	system("cls");

	setAllWorldColors(levelSelectColors.world2, COLOR_MAIN);

	setSpecificWorldColor(levelSelectColors.world2, currentlySelected, COLOR_HIGHLIGHT);

	setTextColor(COLOR_MAIN);

	cout << "World 2" << endl;
	cout << endl;

	cout << "   " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topRightCorner)] << "  " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topRightCorner)] << "  " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topRightCorner)] << endl;

	cout << " < " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::verticalLine)];
	setTextColor(levelSelectColors.world2[0]);
	cout << " 1 ";
	setTextColor(COLOR_MAIN);
	cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::leftToRight)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)];
	cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::rightToLeft)];
	setTextColor(levelSelectColors.world2[1]);
	cout << " 2 ";
	setTextColor(COLOR_MAIN);
	cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::leftToRight)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)];
	cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::rightToLeft)];
	setTextColor(levelSelectColors.world2[2]);
	cout << " 3 ";
	setTextColor(COLOR_MAIN);
	cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::verticalLine)] <<" > "<< endl;

	cout << "   " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomRightCorner)] << "  " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomRightCorner)] << "  " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomRightCorner)] << endl;

	char typedChar = _getch();

	if (typedChar == 'a' || typedChar == 'A')
	{
		if (currentlySelected > 0)
		{
			currentlySelected--;

			printWorldTwo(currentlySelected);
		}
		else
		{
			printWorldOne(2);
		}
	}

	if (typedChar == 'd' || typedChar == 'D')
	{
		if (currentlySelected < 2)
		{
			currentlySelected++;

			printWorldTwo(currentlySelected);
		}
		else
		{
			printWorldThree(0);
		}
	}

	if (typedChar == KEY_ENTER)
	{

		system("cls");

		startWorldGen(WORLD_CODES::worldTwo, static_cast<LEVEL_CODES>(currentlySelected));

		printBoard();

	}

	printWorldTwo(currentlySelected);
}

void printWorldThree(int currentlySelected)
{
	system("cls");

	setAllWorldColors(levelSelectColors.world3, COLOR_MAIN);

	setSpecificWorldColor(levelSelectColors.world3, currentlySelected, COLOR_HIGHLIGHT);

	setTextColor(COLOR_MAIN);

	cout << "World 3" << endl;
	cout << endl;

	cout << "   " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topRightCorner)] << "  " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topRightCorner)] << "  " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topRightCorner)] << endl;

	cout << " < " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::verticalLine)];
	setTextColor(levelSelectColors.world3[0]);
	cout << " 1 ";
	setTextColor(COLOR_MAIN);
	cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::leftToRight)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)];
	cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::rightToLeft)];
	setTextColor(levelSelectColors.world3[1]);
	cout << " 2 ";
	setTextColor(COLOR_MAIN);
	cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::leftToRight)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)];
	cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::rightToLeft)];
	setTextColor(levelSelectColors.world3[2]);
	cout << " 3 ";
	setTextColor(COLOR_MAIN);
	cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::verticalLine)] << endl;

	cout << "   " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomRightCorner)] << "  " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomRightCorner)] << "  " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomRightCorner)] << endl;

	char typedChar = _getch();

	if (typedChar == 'a' || typedChar == 'A')
	{
		if (currentlySelected > 0)
		{
			currentlySelected--;

			printWorldThree(currentlySelected);
		}
		else
		{
			printWorldTwo(2);
		}
	}

	if (typedChar == 'd' || typedChar == 'D')
	{
		if (currentlySelected < 2)
		{
			currentlySelected++;

			printWorldThree(currentlySelected);
		}
		else
		{
			printWorldThree(currentlySelected);
		}
	}

	if (typedChar == KEY_ENTER)
	{

		system("cls");

		startWorldGen(WORLD_CODES::worldThree, static_cast<LEVEL_CODES>(currentlySelected));

		printBoard();

		winLogic(static_cast<LEVEL_CODES>(currentlySelected));

	}

	printWorldThree(currentlySelected);
}

void printLevelSelect(int world)
{
	system("cls");

	switch (world)
	{
		case 1:
			printWorldOne(0);
			break;
		case 2:
			printWorldTwo(0);
			break;
		case 3:
			printWorldThree(0);
			break;
	}
}

void printHowToPlay()
{

}

void printAboutUs()
{

}

void printExit()
{

}

void printMenu(int activeOption)
{
	setTextColor(COLOR_MAIN);

	system("cls");

	cout << endl;
	
	cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topLeftCorner)];

	for (int i = 0; i < 13; i++)
	{
		cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)];
	}

	cout << " Main Menu " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topRightCorner)] << endl;

	for (int i = 0; i < 22; i++)
	{
		if (i == 2)
		{
			setTextColor(mainMenuColors[menuCounter]);
			cout << "       " << mainMenuItems[menuCounter];
			setTextColor(COLOR_MAIN);
			cout<<"       " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::verticalLine)] << endl;
			menuCounter++;
		}

		if (i == 4)
		{
			setTextColor(mainMenuColors[menuCounter]);
			cout << "       " << mainMenuItems[menuCounter];
			setTextColor(COLOR_MAIN);
			cout<< "        " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::verticalLine)] << endl;
			menuCounter++;
		}

		if (i == 6)
		{
			setTextColor(mainMenuColors[menuCounter]);
			cout << "        " << mainMenuItems[menuCounter];
			setTextColor(COLOR_MAIN);
			cout<< "          " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::verticalLine)] << endl;
			menuCounter++;
		}

		if (i == 8)
		{
			setTextColor(mainMenuColors[menuCounter]);
			cout << "         " << mainMenuItems[menuCounter];
			setTextColor(COLOR_MAIN);
			cout<< "             " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::verticalLine)] << endl;
			menuCounter++;
		}

		cout << "                          " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::verticalLine)] << endl;

	}

	cout << "                          " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomRightCorner)] << endl;

	menuCounter = 0;

	char latestKeyPress = _getch();

	if (latestKeyPress == 's' || latestKeyPress == 'S' || latestKeyPress == KEY_DOWN)
	{
		activeOption = (activeOption < 3) ? activeOption + 1 : 0;
		
		updateMainMenuColors(activeOption);

		printMenu(activeOption);
	}
	
	if (latestKeyPress == 'w' || latestKeyPress == 'W' || latestKeyPress == KEY_UP)
	{
		activeOption = (activeOption > 0) ? activeOption - 1 : 3;

		updateMainMenuColors(activeOption);

		printMenu(activeOption);
	}

	if (latestKeyPress == KEY_ENTER)
	{
		switch (activeOption)
		{
			case 0:
				printLevelSelect(1);
				break;
			case 1:
				printHowToPlay();
				break;
			case 2:
				printAboutUs();
				break;
			case 3:
				printExit();
				break;
		}
	}


	printMenu(activeOption);
	
}

WORLD_CODES incrementWorld(WORLD_CODES world)
{
	int temp = static_cast<int>(world);
	temp++;
	world = static_cast<WORLD_CODES>(temp);

	return world;
}

LEVEL_CODES incrementLevel(LEVEL_CODES level)
{
	int temp = static_cast<int>(level);
	temp++;
	level = static_cast<LEVEL_CODES>(temp);

	return level;
}

void printWinMenu(int activeOption, LEVEL_CODES previousLevel, WORLD_CODES currentWorld)
{
	system("cls");

	setTextColor(7);

	cout << endl;

	cout << "Win Menu yes" << endl;

	cout << endl;
	
	for (int i = 0; i < 2; i++)
	{
		setTextColor(winMenuColors[i]);
		cout << winMenuItems[i] << endl;
	}


	char latestKeyPress = _getch();

	if (latestKeyPress == 's' || latestKeyPress == 'S' || latestKeyPress == KEY_DOWN)
	{
		
		if (activeOption == 1)
		{
			activeOption = 0;
		}
		else {
			activeOption++;
		}

		updateWinMenuColors(activeOption);

		printWinMenu(activeOption, previousLevel, currentWorld);
	}

	if (latestKeyPress == 'w' || latestKeyPress == 'W' || latestKeyPress == KEY_UP)
	{
		if (activeOption == 0)
		{
			activeOption = 1;
		}
		else {
			activeOption--;
		}


		updateWinMenuColors(activeOption);

		printWinMenu(activeOption, previousLevel, currentWorld);
	}

	if (latestKeyPress == KEY_ENTER)
	{

		

		switch (activeOption)
		{
		case 0:
			previousLevel = incrementLevel(previousLevel);

			if (static_cast<int>(previousLevel) == 3)
			{
				currentWorld = incrementWorld(currentWorld);
				previousLevel = LEVEL_CODES::levelOne;
			}

			//Add case if world is 3 and level is 3

			startWorldGen(currentWorld, previousLevel);
			printBoard();
		break;

		case 1:
			printMenu(0);
			break;

		}
	}

	printWinMenu(activeOption, previousLevel, currentWorld);

}