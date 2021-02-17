#include "gameMenu.h"
#include "boardFrontend.h"
#include "boardBackend.h"
#include <iostream>
#include <conio.h>

using namespace std;

#define BOARD_SIZE 10
#define RESET_BUTTON 114
#define ESCAPE_BUTTON 27


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



void startWorldGen(int currentlySelectedLevel)
{
	switch (currentlySelectedLevel)
	{
	case 0:
		generateBoard(WORLD_CODES::worldOne, LEVEL_CODES::levelOne);
		break;

	case 1:
		generateBoard(WORLD_CODES::worldOne, LEVEL_CODES::levelTwo);
		break;

	case 2:
		generateBoard(WORLD_CODES::worldOne, LEVEL_CODES::levelThree);
		break;

	default:
		break;

	}
}

void printFirstRow()
{

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
		cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::verticalLine)] << " " << getValue(counts[0], counts[1]) << " ";
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
}


void printBoard()
{


	int counters[2] = { 0, 0 };

	system("cls");

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

void getUserInput()
{
	char userInput = _getch();

	if (userInput == 'w')
	{
		makeMove(WORLD_CODES::worldOne, MOVES::up);
		printBoard();
	}

	if (userInput == RESET_BUTTON)
	{
		resetBoard();
		printBoard();
	}

	if (userInput == ESCAPE_BUTTON)
	{
		printMenu(0);
	}

	getUserInput();
}