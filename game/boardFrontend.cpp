#include "gameMenu.h"
#include "boardFrontend.h"
#include "boardBackend.h"
#include <iostream>
#include <conio.h>

using namespace std;

#define BOARD_SIZE 10
#define RESET_BUTTON 114
#define ESCAPE_BUTTON 27
#define ENTER_KEY 13
#define ARROW_LEFT 75
#define ARROW_RIGHT 77
#define ARROW_UP 72
#define ARROW_DOWN 80
#define PLAYER_CHARACTER 234
#define COLOR_MAIN 15
#define WALL_CHARACTER 178

LEVEL_CODES currentLevel;
WORLD_CODES currentWorld;

bool firstRowPrinted = false;
bool lastRowPrinted = false;

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



void startWorldGen(WORLD_CODES currentlySelectedWorld, LEVEL_CODES currentlySelectedLevel)
{
	currentWorld = currentlySelectedWorld;
	currentLevel = currentlySelectedLevel;

	generateBoard(currentlySelectedWorld, currentlySelectedLevel);

}

void printFirstRow()
{
	setTextColor(15);

	int topToBottomCount = 0;

	cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topLeftCorner)];

	for (int i = 0; i < 10; i++)
	{
		cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)];
		if (topToBottomCount != 9)
		{
			cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topToBottom)];
		}
		topToBottomCount++;
	}

	cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topRightCorner)];

	cout << endl;

}

void printMiddleRow(int counts[2])
{
	for (int i = 0; i < 10; i++)
	{
		cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::verticalLine)] << " ";

		if(isLetter(getValue(counts[0], counts[1])))
		{
			winLogic(currentLevel);
		}

		cout << getValue(counts[0], counts[1]);
		setTextColor(15);
		cout<< " ";
		counts[0]++;
	}

	cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::verticalLine)];

	cout << endl;
}

void printBottomRow()
{
	int crossCount = 0;

	cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::leftToRight)];

	for (int i = 0; i < 10; i++)
	{
		cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)];
		if (crossCount != 9)
		{
			cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::cross)];
		}
		crossCount++;
	}

	cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::rightToLeft)];

	cout << endl;
}

void printLastRow()
{
	int bottomToTop = 0;

	cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomLeftCorner)];

	for (int i = 0; i < 10; i++)
	{
		cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)];
		if (bottomToTop != 9)
		{
			cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomToTop)];
		}
		bottomToTop++;
	}

	cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomRightCorner)];

	cout << endl;

	if (winCheck(currentLevel))
	{
		cout << "Click ENTER to continue:";
	}
}

void printBoard()
{


	int counters[2] = { 0, 0 };

	goToXY(0, 0);

	for (int i = 0; i < BOARD_SIZE * 2; i++)
	{
		if (i == 0)
		{
			printFirstRow();
			firstRowPrinted = true;
		}

		if (firstRowPrinted)
		{
			if (i % 2 != 0)
			{
				printMiddleRow(counters);

			}
			else if (i != 0)
			{
				printBottomRow();
			}
		}

		if (i == 19)
		{
			printLastRow();
		}
	}


	getUserInput();

}

void winLogic(LEVEL_CODES currentlySelectedLevel)
{
	if (winCheck(currentlySelectedLevel) == true)
	{
		setTextColor(2);
	}


}

void getUserInput()
{

	char userInput = _getch();

	winLogic(currentLevel);

	if (userInput == 'w' || userInput == ARROW_UP)
	{
		makeMove(currentWorld, MOVES::up);
		printBoard();
	}

	else if (userInput == 'a' || userInput == ARROW_LEFT)
	{
		makeMove(currentWorld, MOVES::left);
		printBoard();
	}

	else if (userInput == 'd' || userInput == ARROW_RIGHT)
	{
		makeMove(currentWorld, MOVES::right);
		printBoard();
	}

	else if (userInput == 's' || userInput == ARROW_DOWN)
	{
		makeMove(currentWorld, MOVES::down);
		printBoard();
	}

	else if (userInput == RESET_BUTTON)
	{
		resetBoard();
		printBoard();
	}

	else if (userInput == ESCAPE_BUTTON)
	{
		printMenu(0);
	}

	else if (winCheck(currentLevel))
	{
		if (userInput == ENTER_KEY)
		{
			printWinMenu(0, currentLevel, currentWorld);
		}
	}

	
	else getUserInput();
}

