#include "gameMenu.h"
#include "boardBackend.h"
#include "boardFrontend.h"
#include <conio.h>
#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>

#define ESCAPE_BUTTON 27
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13
#define ARROW_LEFT 75
#define ARROW_RIGHT 77
#define COLOR_MAIN 15
#define COLOR_SELECT 8
#define PLAYER_CHARACTER 234

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

int mainMenuColors[4] = { COLOR_SELECT, COLOR_MAIN, COLOR_MAIN, COLOR_MAIN };

int winMenuColors[2] = { COLOR_SELECT, COLOR_MAIN };

struct level_select_colors {
	int world1[3] = { COLOR_MAIN, COLOR_MAIN, COLOR_MAIN };
	int world2[3] = { COLOR_MAIN, COLOR_MAIN, COLOR_MAIN };
	int world3[3] = { COLOR_MAIN, COLOR_MAIN, COLOR_MAIN };
} levelSelectColors;

/*CHARACTERS FOR CELLS*/


char boardCharacters[11] = { char(218), char(191), char(192), char(217), char(194), char(193), char(195), char(180), char(197), char(196), char(179) };

HANDLE getOutputHandle()
{
	HANDLE H_OUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);


	if (H_OUTPUT == INVALID_HANDLE_VALUE)
	{
		string error = "Failed getting STD_OUTPUT_HANDLE!";
		displayError(error);
	}

	return H_OUTPUT;
}

void displayError(string error)
{
	system("cls");
	cerr << error;
	exit(0);
}

void setTextColor(int color)
{
	HANDLE STD_OUTPUT = getOutputHandle();
	SetConsoleTextAttribute(STD_OUTPUT, color);
}

void goToXY(short x, short y)
{
	HANDLE STD_OUTPUT = getOutputHandle();
	COORD cords;
	cords.X = x;
	cords.Y = y;
	SetConsoleCursorPosition(STD_OUTPUT, cords);
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

	mainMenuColors[num] = COLOR_SELECT;
}

void updateWinMenuColors(int num)
{
	setAllWinMenuColors(COLOR_MAIN);

	winMenuColors[num] = COLOR_SELECT;
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

	setSpecificWorldColor(levelSelectColors.world1, currentlySelected, COLOR_SELECT);

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
	cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::verticalLine)] << " > " << endl;

	cout << "   " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomRightCorner)] << "  " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomRightCorner)] << "  " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomRightCorner)] << endl;

	char typedChar = _getch();

	if (typedChar == 'a' || typedChar == 'A')
	{
		currentlySelected = (currentlySelected > 0) ? currentlySelected - 1 : currentlySelected;

		printWorldOne(currentlySelected);
	}

	else if (typedChar == 'd' || typedChar == 'D')
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

	else if (typedChar == KEY_ENTER)
	{

		system("cls");

		startWorldGen(WORLD_CODES::worldOne, static_cast<LEVEL_CODES>(currentlySelected));

		printBoard();

	}

	else printWorldOne(currentlySelected);
}

void printWorldTwo(int currentlySelected)
{
	system("cls");

	setAllWorldColors(levelSelectColors.world2, COLOR_MAIN);

	setSpecificWorldColor(levelSelectColors.world2, currentlySelected, COLOR_SELECT);

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
	cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::verticalLine)] << " > " << endl;

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

	else if (typedChar == 'd' || typedChar == 'D')
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

	else if (typedChar == KEY_ENTER)
	{

		system("cls");

		startWorldGen(WORLD_CODES::worldTwo, static_cast<LEVEL_CODES>(currentlySelected));

		printBoard();

	}

	else printWorldTwo(currentlySelected);
}

void printWorldThree(int currentlySelected)
{
	system("cls");

	setAllWorldColors(levelSelectColors.world3, COLOR_MAIN);

	setSpecificWorldColor(levelSelectColors.world3, currentlySelected, COLOR_SELECT);

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

	else if (typedChar == 'd' || typedChar == 'D')
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

	else if (typedChar == KEY_ENTER)
	{

		system("cls");

		startWorldGen(WORLD_CODES::worldThree, static_cast<LEVEL_CODES>(currentlySelected));

		printBoard();

		winLogic(static_cast<LEVEL_CODES>(currentlySelected));

	}

	else printWorldThree(currentlySelected);
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

void resetHowToPlay()
{
	goToXY(30, 7);
	cout << "	                                                                                    ";
	goToXY(30, 8);
	cout << "	                                                                                    ";
	goToXY(30, 9);
	cout << "	                                                                                    ";
	goToXY(30, 10);
	cout << "	                                                                                    ";
}

void printHowToPlay(int page)
{
	int forwardIndent = 38;

	string sentences[4] = {
	"	By progressing through the different levels and worlds you will experience",
	"more and more challenging words. At one point you will face walls, which ",
	"will prevent you from moving and letter traps that will change the position",
	"of anything that steps on them.",
	};

	resetHowToPlay();

	switch (page)
	{
	case 0:
		goToXY(forwardIndent, 10);
		cout << "This is your player - " << char(PLAYER_CHARACTER) << ". You move with W-A-S-D or using the arrow keys.";
		goToXY(65, 12);
		cout << "<Page 1/4>";
		break;

	case 1:
		goToXY(forwardIndent, 9);
		cout << "Your goal is to create a meaningful word, by pushing the letters together,";
		goToXY(forwardIndent, 10);
		cout << "around the map.";
		goToXY(65, 12);
		cout << "<Page 2/4>";
		break;

	case 2:

		for (int i = 7; i <= 10; i++)
		{
			goToXY(forwardIndent, i);
			cout << sentences[i - 7];
		}
		goToXY(65, 12);
		cout << "<Page 3/4>";
		break;

	case 3:
		goToXY(58, 10);
		cout << "Good luck and have fun :)";
		goToXY(65, 12);
		cout << "<Page 4/4>";
		break;

	default:
		break;
	}



	char input = _getch();

	if (input == 'A' || input == 'a' || input == ARROW_LEFT)
	{
		if (page != 0)
		{
			page--;
		}
	}

	if (input == 'D' || input == 'd' || input == ARROW_RIGHT)
	{
		if (page != 3)
		{
			page++;
		}
	}

	if (input == ESCAPE_BUTTON)
	{
		printMenu(1);
	}

	else printHowToPlay(page);
}

void printAboutUs()
{

}

void Exit()
{
	system("cls");
	cout << "Thanks for playing :)";
	for (int i = 0; i < 2; i++)
	{
		cout << endl;
	}
	exit(0);
}

void printMenu(int activeOption)
{
	int menuCounter = 0;

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
			cout << "       " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::verticalLine)] << endl;
			menuCounter++;
		}

		if (i == 4)
		{
			setTextColor(mainMenuColors[menuCounter]);
			cout << "       " << mainMenuItems[menuCounter];
			setTextColor(COLOR_MAIN);
			cout << "        " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::verticalLine)] << endl;
			menuCounter++;
		}

		if (i == 6)
		{
			setTextColor(mainMenuColors[menuCounter]);
			cout << "        " << mainMenuItems[menuCounter];
			setTextColor(COLOR_MAIN);
			cout << "          " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::verticalLine)] << endl;
			menuCounter++;
		}

		if (i == 8)
		{
			setTextColor(mainMenuColors[menuCounter]);
			cout << "         " << mainMenuItems[menuCounter];
			setTextColor(COLOR_MAIN);
			cout << "             " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::verticalLine)] << endl;
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
			printHowToPlay(0);
			break;
		case 2:
			printAboutUs();
			break;
		case 3:
			Exit();
			break;
		}
	}


	else printMenu(activeOption);

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

	cout << "Win Menu" << endl;

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

	else printWinMenu(activeOption, previousLevel, currentWorld);

}