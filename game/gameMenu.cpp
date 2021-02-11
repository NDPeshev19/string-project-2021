#include "gameMenu.h"
#include <conio.h>
#include <iostream>
#include <string>
#include <windows.h>
#include <map>

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

int mainMenuColors[4] = { COLOR_HIGHLIGHT, COLOR_MAIN, COLOR_MAIN, COLOR_MAIN };

struct level_select_colors {
	int world1[3] = { COLOR_MAIN, COLOR_MAIN, COLOR_MAIN };
	int world2[3] = { COLOR_MAIN, COLOR_MAIN, COLOR_MAIN };
	int world3[3] = { COLOR_MAIN, COLOR_MAIN, COLOR_MAIN };
} levelSelectColors;

/*CHARACTERS OR CELLS*/

map<string, char> boardCharacters;

void initBoardCharacters()
{
	boardCharacters.insert(pair<string, char>("topLeftCorner", 218));
	boardCharacters.insert(pair<string, char>("topRightCorner", 191));
	boardCharacters.insert(pair<string, char>("bottomLeftCorner", 192));
	boardCharacters.insert(pair<string, char>("bottomRightCorner", 217));
	boardCharacters.insert(pair<string, char>("topToBottom", 194));
	boardCharacters.insert(pair<string, char>("bottomToTop", 193));
	boardCharacters.insert(pair<string, char>("leftToRight", 195));
	boardCharacters.insert(pair<string, char>("rightToLeft", 180));
	boardCharacters.insert(pair<string, char>("cross", 197));
	boardCharacters.insert(pair<string, char>("horizontalLine", 196));
	boardCharacters.insert(pair<string, char>("verticalLine", 179));
}

/*characters for cells*/

void initFrontEnd()
{
	initBoardCharacters();

	
}

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

void updateMainMenuColors(int num)
{
	setAllMainMenuColors(COLOR_MAIN);

	mainMenuColors[num] = COLOR_HIGHLIGHT;
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

	cout << "   " << boardCharacters["topLeftCorner"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"] << boardCharacters["topRightCorner"] << "  " << boardCharacters["topLeftCorner"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"] << boardCharacters["topRightCorner"] << "  " << boardCharacters["topLeftCorner"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"] << boardCharacters["topRightCorner"] << endl;
	
	cout << "   " << boardCharacters["verticalLine"];
	setTextColor(levelSelectColors.world1[0]);
	cout << " 1 ";
	setTextColor(COLOR_MAIN);
	cout << boardCharacters["leftToRight"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"];
	cout << boardCharacters["rightToLeft"];
	setTextColor(levelSelectColors.world1[1]);
	cout << " 2 ";
	setTextColor(COLOR_MAIN);
	cout << boardCharacters["leftToRight"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"];
	cout << boardCharacters["rightToLeft"];
	setTextColor(levelSelectColors.world1[2]);
	cout << " 3 ";
	setTextColor(COLOR_MAIN);
	cout << boardCharacters["verticalLine"] <<" > "<< endl;

	cout << "   " << boardCharacters["bottomLeftCorner"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"] << boardCharacters["bottomRightCorner"] << "  " << boardCharacters["bottomLeftCorner"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"] << boardCharacters["bottomRightCorner"] << "  " << boardCharacters["bottomLeftCorner"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"]<< boardCharacters["horizontalLine"] << boardCharacters["bottomRightCorner"] << endl;
	
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
}

void printWorldTwo(int currentlySelected)
{
	system("cls");

	setAllWorldColors(levelSelectColors.world2, COLOR_MAIN);

	setSpecificWorldColor(levelSelectColors.world2, currentlySelected, COLOR_HIGHLIGHT);

	setTextColor(COLOR_MAIN);

	cout << "World 2" << endl;
	cout << endl;

	cout << "   " << boardCharacters["topLeftCorner"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"] << boardCharacters["topRightCorner"] << "  " << boardCharacters["topLeftCorner"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"] << boardCharacters["topRightCorner"] << "  " << boardCharacters["topLeftCorner"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"] << boardCharacters["topRightCorner"] << endl;

	cout << " < " << boardCharacters["verticalLine"];
	setTextColor(levelSelectColors.world2[0]);
	cout << " 1 ";
	setTextColor(COLOR_MAIN);
	cout << boardCharacters["leftToRight"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"];
	cout << boardCharacters["rightToLeft"];
	setTextColor(levelSelectColors.world2[1]);
	cout << " 2 ";
	setTextColor(COLOR_MAIN);
	cout << boardCharacters["leftToRight"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"];
	cout << boardCharacters["rightToLeft"];
	setTextColor(levelSelectColors.world2[2]);
	cout << " 3 ";
	setTextColor(COLOR_MAIN);
	cout << boardCharacters["verticalLine"] <<" > "<< endl;

	cout << "   " << boardCharacters["bottomLeftCorner"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"] << boardCharacters["bottomRightCorner"] << "  " << boardCharacters["bottomLeftCorner"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"] << boardCharacters["bottomRightCorner"] << "  " << boardCharacters["bottomLeftCorner"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"] << boardCharacters["bottomRightCorner"] << endl;

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
}

void printWorldThree(int currentlySelected)
{
	system("cls");

	setAllWorldColors(levelSelectColors.world3, COLOR_MAIN);

	setSpecificWorldColor(levelSelectColors.world3, currentlySelected, COLOR_HIGHLIGHT);

	setTextColor(COLOR_MAIN);

	cout << "World 3" << endl;
	cout << endl;

	cout << "   " << boardCharacters["topLeftCorner"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"] << boardCharacters["topRightCorner"] << "  " << boardCharacters["topLeftCorner"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"] << boardCharacters["topRightCorner"] << "  " << boardCharacters["topLeftCorner"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"] << boardCharacters["topRightCorner"] << endl;

	cout << " < " << boardCharacters["verticalLine"];
	setTextColor(levelSelectColors.world3[0]);
	cout << " 1 ";
	setTextColor(COLOR_MAIN);
	cout << boardCharacters["leftToRight"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"];
	cout << boardCharacters["rightToLeft"];
	setTextColor(levelSelectColors.world3[1]);
	cout << " 2 ";
	setTextColor(COLOR_MAIN);
	cout << boardCharacters["leftToRight"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"];
	cout << boardCharacters["rightToLeft"];
	setTextColor(levelSelectColors.world3[2]);
	cout << " 3 ";
	setTextColor(COLOR_MAIN);
	cout << boardCharacters["verticalLine"] << endl;

	cout << "   " << boardCharacters["bottomLeftCorner"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"] << boardCharacters["bottomRightCorner"] << "  " << boardCharacters["bottomLeftCorner"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"] << boardCharacters["bottomRightCorner"] << "  " << boardCharacters["bottomLeftCorner"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"] << boardCharacters["horizontalLine"] << boardCharacters["bottomRightCorner"] << endl;

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
	system("cls");

	for (int i = 0; i < 4; i++)
	{
		setTextColor(mainMenuColors[i]);
		cout << mainMenuItems[i] << endl;
	}

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