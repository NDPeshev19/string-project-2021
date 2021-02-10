#include "gameMenu.h"
#include <conio.h>
#include <iostream>
#include <string>
#include <windows.h>

#define KEY_UP 72
#define KEY_DOWN 80

using namespace std;

const string mainMenuItems[4] = {
	"World select",
	"How to play",
	"About us",
	"Exit"
};

int mainMenuColors[4] = { 8, 15, 15, 15 };

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
	setAllMainMenuColors(15);

	mainMenuColors[num] = 8;
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
	else if (latestKeyPress == 'w' || latestKeyPress == 'W' || latestKeyPress == KEY_UP)
	{
		activeOption = (activeOption > 0) ? activeOption - 1 : 3;

		updateMainMenuColors(activeOption);

		printMenu(activeOption);
	}


	printMenu(activeOption);
}