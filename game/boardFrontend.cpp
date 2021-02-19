#include "gameMenu.h"
#include "boardFrontend.h"
#include "boardBackend.h"
#include <iostream>
#include <conio.h>

using namespace std;

#define BOARD_SIZE 10
#define RESET_BUTTON 114
#define ESCAPE_BUTTON 27
#define ARROW_LEFT 75
#define ARROW_RIGHT 77
#define ARROW_UP 72
#define ARROW_DOWN 80

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

	switch (currentlySelectedWorld)
	{
	case WORLD_CODES::worldOne:
		switch (currentlySelectedLevel)
		{
		case LEVEL_CODES::levelOne:
			generateWorldOneBoard(currentlySelectedLevel);
			break;

		case LEVEL_CODES::levelTwo:
			generateWorldOneBoard(currentlySelectedLevel);
			break;

		case LEVEL_CODES::levelThree:
			generateWorldOneBoard(currentlySelectedLevel);
			break;

		default:
			break;
		}
		break;

	case WORLD_CODES::worldTwo:
		switch (currentlySelectedLevel)
		{
		case LEVEL_CODES::levelOne:
			generateWorldTwoBoard(currentlySelectedLevel);
			break;

		case LEVEL_CODES::levelTwo:
			generateWorldTwoBoard(currentlySelectedLevel);
			break;

		case LEVEL_CODES::levelThree:
			generateWorldTwoBoard(currentlySelectedLevel);
			break;

		default:
			break;
		}
		break;

	case WORLD_CODES::worldThree:
		switch (currentlySelectedLevel)
		{
		case LEVEL_CODES::levelOne:
			//generateWorldThreeBoard(currentlySelectedLevel);
			break;

		case LEVEL_CODES::levelTwo:
			//generateWorldThreeBoard(currentlySelectedLevel);
			break;

		case LEVEL_CODES::levelThree:
			//generateWorldThreeBoard(currentlySelectedLevel);
			break;

		default:
			break;
		}
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

void getUserInput()
{
	char userInput = _getch();

	if (userInput == 'w' || userInput == ARROW_UP)
	{
		makeMove(WORLD_CODES::worldOne, MOVES::up);
		printBoard();
	}

	if (userInput == 'a' || userInput == ARROW_LEFT)
	{
		makeMove(WORLD_CODES::worldOne, MOVES::left);
		printBoard();
	}

	if (userInput == 'd' || userInput == ARROW_RIGHT)
	{
		makeMove(WORLD_CODES::worldOne, MOVES::right);
		printBoard();
	}

	if (userInput == 's' || userInput == ARROW_DOWN)
	{
		makeMove(WORLD_CODES::worldOne, MOVES::down);
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