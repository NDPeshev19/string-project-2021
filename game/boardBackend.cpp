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

COORD playerCoords = { PLAYER_STARTING_POS_X, PLAYER_STARTING_POS_Y };

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

	switch (word)
	{
	case LEVEL_CODES::levelOne:
		return words.threeLetter[index];
		break;
	case LEVEL_CODES::levelTwo:
		return words.fourLetter[index];
		break;
	case LEVEL_CODES::levelThree:
		return words.fiveLetter[index];
		break;
	default:
		break;
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
		if ((cords[i].X == temp.X && cords[i].Y == temp.Y) || (cords[i].X == PLAYER_STARTING_POS_X && cords[i].Y == PLAYER_STARTING_POS_Y))
		{
			flag = true;
		}
	}

	return flag;
}

void resetBoard()
{
	duplicateBoard(initialBoard, board);
	playerCoords = { PLAYER_STARTING_POS_X, PLAYER_STARTING_POS_Y };
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

	switch (world)
	{
	case WORLD_CODES::worldOne:
		generateWorldOneBoard(level);
		break;
	case WORLD_CODES::worldTwo:
		//generateWorldTwoBoard(level);
		break;
	case WORLD_CODES::worldThree:
		//generateWorldThreeBoard(level);
		break;
	default:
		break;
	}

	resetBoard();
	resetBoard();
}

void makeMove(WORLD_CODES world, MOVES direction)
{
	switch (world)
	{
	case WORLD_CODES::worldOne:
		makeMoveWoldOne(direction);
		break;
	case WORLD_CODES::worldTwo:
		break;
	case WORLD_CODES::worldThree:
		break;
	default:
		break;
	}
}

void makeMoveWoldOne(MOVES direction)
{
	if (moveAvailableWorldOne(direction))
	{
		if (playerOnEdge(direction))
		{
			switch (direction)
			{
			case MOVES::up:
				swap(playerCoords, { playerCoords.X, playerCoords.Y - 1 });
				playerCoords.Y--;
				break;
			case MOVES::down:
				swap(playerCoords, { playerCoords.X, playerCoords.Y + 1 });
				playerCoords.Y++;
				break;
			case MOVES::left:
				swap(playerCoords, { playerCoords.X - 1, playerCoords.Y });
				playerCoords.X--;
				break;
			case MOVES::right:
				swap(playerCoords, { playerCoords.X + 1, playerCoords.Y });
				playerCoords.X++;
				break;
			default:
				break;
			}
		}
		else
		{
			switch (direction)
			{
			case MOVES::up:
				swap({ playerCoords.X, playerCoords.Y - 1 }, { playerCoords.X, playerCoords.Y - 2 });
				swap(playerCoords, { playerCoords.X, playerCoords.Y - 1 });
				playerCoords.Y--;
				break;
			case MOVES::down:
				swap({ playerCoords.X, playerCoords.Y + 1 }, { playerCoords.X, playerCoords.Y + 2 });
				swap(playerCoords, { playerCoords.X, playerCoords.Y + 1 });
				playerCoords.Y++;
				break;
			case MOVES::left:
				swap({ playerCoords.X - 1, playerCoords.Y }, { playerCoords.X - 2, playerCoords.Y });
				swap(playerCoords, { playerCoords.X - 1, playerCoords.Y });
				playerCoords.X--;
				break;
			case MOVES::right:
				swap({ playerCoords.X + 1, playerCoords.Y }, { playerCoords.X + 2, playerCoords.Y });
				swap(playerCoords, { playerCoords.X + 1, playerCoords.Y });
				playerCoords.X++;
				break;
			default:
				break;
			}
		}
	}
}

bool isLetter(char letter)
{
	letter = tolower(letter);
	return (letter >= 97 && letter <= 122);
}

void swap(COORD first, COORD second)
{
	COORD tempCoord = second;
	char tempChar = getValue(second.X, second.Y);

	assignValue(second.X, second.Y, getValue(first.X, first.Y));
	assignValue(first.X, first.Y, tempChar);
}

bool playerOnEdge(MOVES direction)
{
	switch (direction)
	{
	case MOVES::up:
		if (playerCoords.X != 0)
		{
			if (playerCoords.X == 1)
			{
				return true;
			}

			if (playerCoords.X > 1)
			{
				if (!isLetter(getValue(playerCoords.X, playerCoords.Y - 1)) && isLetter(getValue(playerCoords.X, playerCoords.Y - 2)))
				{
					return true;
				}
			}

			return false;
		}

		return true;
	case MOVES::down:
		if (playerCoords.X != 9)
		{
			if (playerCoords.X == 8)
			{
				return true;
			}

			if (playerCoords.X < 8)
			{
				if (!isLetter(getValue(playerCoords.X, playerCoords.Y + 1)) && isLetter(getValue(playerCoords.X, playerCoords.Y + 2)))
				{
					return true;
				}
			}

			return false;
		}

		return true;
	case MOVES::left:
		if (playerCoords.Y != 0)
		{
			if (playerCoords.Y == 1)
			{
				return true;
			}

			if (playerCoords.Y > 1)
			{
				if (!isLetter(getValue(playerCoords.X - 1, playerCoords.Y)) && isLetter(getValue(playerCoords.X - 2, playerCoords.Y)))
				{
					return true;
				}
			}

			return false;
		}

		return true;
	case MOVES::right:
		if (playerCoords.Y != 9)
		{
			if (playerCoords.Y == 8)
			{
				return true;
			}

			if (playerCoords.Y < 8)
			{
				if (!isLetter(getValue(playerCoords.X + 1, playerCoords.Y)) && isLetter(getValue(playerCoords.X + 2, playerCoords.Y)))
				{
					return true;
				}
			}

			return false;
		}

		return true;
	default:
		break;
	}
}

bool moveAvailableWorldOne(MOVES direction)
{
	switch (direction)
	{
	case MOVES::up:
		if (playerCoords.Y == 0)
		{
			return false;
		}

		if (playerCoords.Y == 1 && isLetter(getValue(playerCoords.X, playerCoords.Y - 1)))
		{
			return false;
		}

		if (playerCoords.Y == 1 && !isLetter(getValue(playerCoords.X, playerCoords.Y - 1)))
		{
			return true;
		}
		
		if (playerCoords.Y > 1)
		{
			if (isLetter(getValue(playerCoords.X, playerCoords.Y - 1)))
			{
				return (!isLetter(getValue(playerCoords.X, playerCoords.Y - 2)));
			}
			
		}

		return true;

		break;
	
	case MOVES::down:
		if (playerCoords.Y == 9)
		{
			return false;
		}

		if (playerCoords.Y == 8 && isLetter(getValue(playerCoords.X, playerCoords.Y + 1)))
		{
			return false;
		}

		if (playerCoords.Y == 8 && !isLetter(getValue(playerCoords.X, playerCoords.Y + 1)))
		{
			return true;
		}

		if (playerCoords.Y < 8)
		{
			if (isLetter(getValue(playerCoords.X, playerCoords.Y + 1)))
			{
				return (!isLetter(getValue(playerCoords.X, playerCoords.Y + 2)));
			}
		}

		return true;

		break;

	case MOVES::left:
		if (playerCoords.X == 0)
		{
			return false;
		}

		if (playerCoords.X == 1 && isLetter(getValue(playerCoords.X - 1, playerCoords.Y)))
		{
			return false;
		}

		if (playerCoords.X == 1 && !isLetter(getValue(playerCoords.X - 1, playerCoords.Y)))
		{
			return true;
		}

		if (playerCoords.X > 1)
		{
			if (isLetter(getValue(playerCoords.X - 1, playerCoords.Y)))
			{
				return (!isLetter(getValue(playerCoords.X - 2, playerCoords.Y)));
			}
		}

		return true;

		break;

	case MOVES::right:
		if (playerCoords.X == 9)
		{
			return false;
		}

		if (playerCoords.X == 8 && isLetter(getValue(playerCoords.X + 1, playerCoords.Y)))
		{
			return false;
		}

		if (playerCoords.X == 8 && !isLetter(getValue(playerCoords.X + 1, playerCoords.Y)))
		{
			return true;
		}

		if (playerCoords.X < 8)
		{
			if (isLetter(getValue(playerCoords.X + 1, playerCoords.Y)))
			{
				return (!isLetter(getValue(playerCoords.X + 2, playerCoords.Y)));
			}
		}

		return true;

		break;
	default:
		return false;
	}
}