#include "gameMenu.h"
#include "boardBackend.h"
#include "boardFrontend.h"
#include <conio.h>
#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>

#define COLOR_SELECT 8

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

// Displays the given string as an error message
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

// Sets the cursor position and the given coordinates
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

	cout << "         World 1" << endl;
	cout << endl;

	// Prints the first row
	cout << "   " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topRightCorner)] << "  " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topRightCorner)] << "  " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topRightCorner)] << endl;

	// Prints the second row
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

	// Prints the last row
	cout << "   " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomRightCorner)] << "  " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomRightCorner)] << "  " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomRightCorner)] << endl;

	char typedChar = _getch();

	if (typedChar == 'a' || typedChar == 'A' || typedChar == ARROW_LEFT)
	{
		currentlySelected = (currentlySelected > 0) ? currentlySelected - 1 : currentlySelected;

		printWorldOne(currentlySelected);
	}

	else if (typedChar == 'd' || typedChar == 'D' || typedChar == ARROW_RIGHT)
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

	else if (typedChar == ESCAPE_BUTTON)
	{
		printMenu(0);
	}

	else printWorldOne(currentlySelected);
}

void printWorldTwo(int currentlySelected)
{
	system("cls");

	setAllWorldColors(levelSelectColors.world2, COLOR_MAIN);

	setSpecificWorldColor(levelSelectColors.world2, currentlySelected, COLOR_SELECT);

	setTextColor(COLOR_MAIN);

	cout << "         World 2" << endl;
	cout << endl;

	// Prints the first row
	cout << "   " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topRightCorner)] << "  " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topRightCorner)] << "  " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topRightCorner)] << endl;

	// Prints the second row
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

	// Prints the last row
	cout << "   " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomRightCorner)] << "  " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomRightCorner)] << "  " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomRightCorner)] << endl;

	char typedChar = _getch();

	if (typedChar == 'a' || typedChar == 'A' || typedChar == ARROW_LEFT)
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

	else if (typedChar == 'd' || typedChar == 'D' || typedChar == ARROW_RIGHT)
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

	else if (typedChar == ESCAPE_BUTTON)
	{
		printMenu(0);
	}

	else printWorldTwo(currentlySelected);
}

void printWorldThree(int currentlySelected)
{
	system("cls");

	setAllWorldColors(levelSelectColors.world3, COLOR_MAIN);

	setSpecificWorldColor(levelSelectColors.world3, currentlySelected, COLOR_SELECT);

	setTextColor(COLOR_MAIN);

	cout << "         World 3" << endl;
	cout << endl;

	// Prints the first row
	cout << "   " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topRightCorner)] << "  " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topRightCorner)] << "  " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topRightCorner)] << endl;

	// Prints the second row
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

	// Prints the last row
	cout << "   " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomRightCorner)] << "  " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomRightCorner)] << "  " << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomLeftCorner)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomRightCorner)] << endl;

	char typedChar = _getch();

	if (typedChar == 'a' || typedChar == 'A' || typedChar == ARROW_LEFT)
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

	else if (typedChar == 'd' || typedChar == 'D' || typedChar == ARROW_RIGHT)
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

	else if (typedChar == ESCAPE_BUTTON)
	{
		printMenu(0);
	}

	else printWorldThree(currentlySelected);
}

void printLevelSelect(int world)
{
	system("cls");

	system("title Level Select");

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
	system("title How to play");

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
	system("title About us");

	goToXY(37, 10);
	cout << "We're a team of 4 students, making a simple, but interesting word solving game.";
	goToXY(32, 11);
	cout << "If you want to learn more about our project, please reffer to our github page at :";
	goToXY(32, 12);
	cout<< "https://github.com/NDPeshev19/string-project-2021";

	char userInput = _getch();

	if (userInput == ESCAPE_BUTTON)
	{
		printMenu(2);
	}
	else
	{
		printAboutUs();
	}

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

	system("title Main Menu");

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

	if (latestKeyPress == 's' || latestKeyPress == 'S' || latestKeyPress == ARROW_DOWN)
	{
		activeOption = (activeOption < 3) ? activeOption + 1 : 0;

		updateMainMenuColors(activeOption);

		printMenu(activeOption);
	}

	if (latestKeyPress == 'w' || latestKeyPress == 'W' || latestKeyPress == ARROW_UP)
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

void gameEnd()
{
	setTextColor(COLOR_MAIN);

	system("cls");

	cout << "Thank you so much for sticking with us to the end and experiencing our adventure. Come back soon :)" << endl << endl;

	cout << "Press ENTER to return to main menu: ";

	char latestKeyPress = _getch();

	if (latestKeyPress == KEY_ENTER)
	{
		printMenu(0);
	}
	else
	{
		gameEnd();
	}
}

WORLD_CODES incrementWorld(WORLD_CODES world)
{
	// Creates a temporary variable to store the casted to int WORLD_CODES variable
	int temp = static_cast<int>(world);
	temp++;

	// Casts the incremented varialble back to WORLD_CODES
	world = static_cast<WORLD_CODES>(temp);

	return world;
}

LEVEL_CODES incrementLevel(LEVEL_CODES level)
{
	// Creates a temporary variable to store the casted to int WORLD_CODES variable
	int temp = static_cast<int>(level);
	temp++;

	// Casts the incremented varialble back to WORLD_CODES
	level = static_cast<LEVEL_CODES>(temp);

	return level;
}

void printWinMenu(int activeOption, LEVEL_CODES previousLevel, WORLD_CODES currentWorld)
{

	if (previousLevel == LEVEL_CODES::levelThree && currentWorld == WORLD_CODES::worldThree)
	{
		gameEnd();
	}

	system("cls");

	setTextColor(COLOR_MAIN);

	cout << endl;

	cout << "Win Menu" << endl;

	cout << endl;

	for (int i = 0; i < 2; i++)
	{
		setTextColor(winMenuColors[i]);
		cout << winMenuItems[i] << endl;
	}


	char latestKeyPress = _getch();

	if (latestKeyPress == 's' || latestKeyPress == 'S' || latestKeyPress == ARROW_DOWN)
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

	if (latestKeyPress == 'w' || latestKeyPress == 'W' || latestKeyPress == ARROW_UP)
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

			//Switches to the next world if the played level was level 3
			if (static_cast<int>(previousLevel) == 3)
			{
				currentWorld = incrementWorld(currentWorld);
				previousLevel = LEVEL_CODES::levelOne;
			}


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