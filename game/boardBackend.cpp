#include "GRand.h"
#include "boardBackend.h"
#include <string>
#include <windows.h>

using namespace std;

#define PLAYER_STARTING_POS_X 5
#define PLAYER_STARTING_POS_Y 5
#define PLAYER_CHARACTER 234

char board[BOARD_SIZE][BOARD_SIZE];
char initialBoard[BOARD_SIZE][BOARD_SIZE];



struct Words
{
	string threeLetter[10];
	string fourLetter[10];
	string fiveLetter[10];

} words
{
	{"day", "buy", "gem", "guy", "ham", "kit", "key", "sky", "win", "six"},
	{"acid", "blue", "luck", "main", "work", "year", "tone", "late", "fish", "exit"},
	{"habit", "peach", "world", "music", "admin", "light", "heart", "water", "house", "royal"}
};



void assignValue(short x, short y, char character)
{
	board[y][x] = character;
}

char getValue(short x, short y)
{
	return board[y][x];
}

void duplicateBoard(char copy[BOARD_SIZE][BOARD_SIZE], char paste[BOARD_SIZE][BOARD_SIZE])
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			paste[i][j] = copy[i][j];
		}
	}
}

void fillBoard(int boardSize, char filler)
{
	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			board[i][j] = filler;
		}
	}
}

string getWord(LEVEL_CODES word)
{
	GRand random;
	int index = random.i(11);
	switch (static_cast<int>(word))
	{
	case 0:
		return words.threeLetter[index];
	case 1:
		return words.fourLetter[index];
	case 2:
		return words.fiveLetter[index];
	default:
		return "";
	}
}

COORD getRandomCOORD()
{
	GRand random;
	GRand random1;
	return { static_cast<short>(random.i(9) + 1), static_cast<short>(random.i(9) + 1) };
}

void fillCOORD(COORD* cords, short filler)
{
	for (int i = 0; i < 5; i++)
	{
		cords[i] = { filler, filler };
	}
}

bool checkMathching(COORD* cords, COORD temp)
{
	bool flag = false;

	for (int i = 0; i < 5; i++)
	{
		if ( (cords[i].X == temp.X && cords[i].Y == temp.Y) || (cords[i].X == PLAYER_STARTING_POS_X && cords[i].Y == PLAYER_STARTING_POS_Y))
		{
			flag = true;
		}
	}

	return flag;
}

void resetBoard()
{
	duplicateBoard(initialBoard, board);
}

void generateWorldOneBoard(LEVEL_CODES level)
{
	string word = getWord(level);

	COORD cords[5];

	// Generate random cordinates for the letters
	fillCOORD(cords, 0);

	assignValue(PLAYER_STARTING_POS_X, PLAYER_STARTING_POS_Y, PLAYER_CHARACTER);

	for (int i = 0; i < 5; i++)
	{
		COORD temp = getRandomCOORD();
		
		if (!checkMathching(cords, temp))
		{
			cords[i] = temp;
		}
		else
		{
			i--;
		}
	}

	// Assign each letter to the correct cordinate
	for (int i = 0; i < int(word.size()); i++)
	{
		assignValue(cords[i].X, cords[i].Y, word[i]);
	}

	// Save a copy of the board for when we want to reset the level and still have the same word
	duplicateBoard(board, initialBoard);
}

void generateBoard(WORLD_CODES world, LEVEL_CODES level)
{
	fillBoard(BOARD_SIZE, ' ');

	switch (static_cast<int>(world))
	{
	case 0:
		generateWorldOneBoard(level);
		break;
	case 1:
		//generateWorldTwoBoard(level);
		break;
	case 2:
		//generateWorldThreeBoard(level);
		break;

	}
}