#include "gameMenu.h"
#include "boardBackend.h"
#include <iostream>
#include <conio.h>

using namespace std;

#define BOARD_SIZE 10


bool characterTurn = 0;
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


void printHorizontalLine() {
	cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)] << boardCharacters[static_cast<int>(BOARD_CHARACTERS::horizontalLine)];
}

void printHorizontalSpaces(int x, int y) {
	cout << " " << getValue(x, y) << " ";
}

void printFirstRow(int i, int j)
{
	if (j == 0)
	{
		cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topLeftCorner)];
		characterTurn = 1;
	}

	if (characterTurn)
	{
		printHorizontalLine();
		characterTurn = 0;
	}

	if (j % 4 == 0)
	{
		cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topToBottom)];
		characterTurn = 1;
	}

	if (j == 35)
	{
		cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::topRightCorner)];
		firstRowPrinted = true;
	}
}

void printMiddleRow(int i, int j)
{
	if (j == 0)
	{
		cout << endl;
		cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::verticalLine)];
		characterTurn = 1;
	}

	if (characterTurn)
	{
		printHorizontalSpaces(i, j);
		characterTurn = 0;
	}

	if (j % 4 == 0)
	{
		cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::verticalLine)];
		characterTurn = 1;
	}

	if (j == 35)
	{
		cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::verticalLine)];
	}
}

void printBottomRow(int i, int j)
{
	if (j == 0)
	{
		cout << endl;
		cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::leftToRight)];
		characterTurn = 1;
	}

	if (characterTurn)
	{
		printHorizontalLine();
		characterTurn = 0;
	}

	if (j % 4 == 0)
	{
		cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::cross)];
		characterTurn = 1;
	}

	if (j == 35 && i > 0)
	{
		cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::rightToLeft)];
	}
}

void printLastRow(int i, int j)
{

	if (j == 0)
	{
		cout << endl;
		cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomLeftCorner)];
		characterTurn = 1;
	}

	if (characterTurn)
	{
		printHorizontalLine();
		characterTurn = 0;
	}

	if (j % 4 == 0)
	{
		cout << boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomToTop)];
		characterTurn = 1;
	}

	if (j == 35)
	{
		boardCharacters[static_cast<int>(BOARD_CHARACTERS::bottomRightCorner)];
		lastRowPrinted = true;
	}
}


void printBoard()
{

	system("cls");

	for (int i = 0; i <= BOARD_SIZE + 10; i++)
	{
		for (int j = 0; j < 36; j++)
		{
			if (i == 0)
			{
				printFirstRow(i, j);
			}

			if (firstRowPrinted)
			{

				if (i == 20)
				{
					lastRowPrinted = true;
					printLastRow(i, j);
				}

				if (lastRowPrinted == false && i != 20 && i % 2 != 0)
				{
					printMiddleRow(i, j);
				}
				else if (lastRowPrinted == false) {
					printBottomRow(i, j);
				}

			}

		}
	}
}

void getUserInput()
{
	char userInput = _getch();

	if (userInput == 27)
	{
		printMenu(0);
	}
}
