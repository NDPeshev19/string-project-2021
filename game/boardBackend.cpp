#include "GRand.h"
#include "boardBackend.h"
#include <string>
#include <windows.h>

using namespace std;

#define PLAYER_STARTING_POS_X 5
#define PLAYER_STARTING_POS_Y 5
#define PLAYER_CHARACTER 234
#define WALL_CHARACTER 219
#define LETTER_TRAP_CHARACTER 178

char board[BOARD_SIZE][BOARD_SIZE];
char initialBoard[BOARD_SIZE][BOARD_SIZE];

COORD playerCoords = { PLAYER_STARTING_POS_X, PLAYER_STARTING_POS_Y };

string currentWord;

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

COORD findCOORD(char letter)
{
	for (short i = 0; i < 10; i++)
	{
		for (short j = 0; j < 10; j++)
		{
			if (getValue(j, i) == letter)
			{
				return { j, i };
			}
		}
	}

	return { 0, 0 };
}

string getWord(LEVEL_CODES word)
{
	GRand random;
	int index = random.i(10);

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
	return "";
}

COORD getRandomCOORD()
{
	GRand random;
	GRand random1;
	return { static_cast<short>(random.i(8) + 1), static_cast<short>(random.i(8) + 1) };
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

void generateBoard(WORLD_CODES world, LEVEL_CODES level)
{
	fillBoard(BOARD_SIZE, ' ');

	string word = getWord(level);

	currentWord = word;

	COORD letters[5];

	fillCOORD(letters, 0);

	assignValue(PLAYER_STARTING_POS_X, PLAYER_STARTING_POS_Y, static_cast<char>(PLAYER_CHARACTER));

	for (int i = 0; i < 5; i++)
	{
		COORD temp = getRandomCOORD();

		if (!checkMathching(letters, temp))
		{
			letters[i] = temp;
		}
		else
		{
			i--;
		}
	}

	for (int i = 0; i < int(word.size()); i++)
	{
		assignValue(letters[i].X, letters[i].Y, word[i]);
	}

	if (world != WORLD_CODES::worldOne)
	{
		for (int i = 0; i < int(word.size()); i++)
		{
			COORD temp = getRandomCOORD();

			char value = getValue(temp.X, temp.Y);

			if (isAvailable(value))
			{
				if (world == WORLD_CODES::worldTwo)
				{
					assignValue(temp.X, temp.Y, static_cast<char>(WALL_CHARACTER));
				}
				else
				{
					assignValue(temp.X, temp.Y, static_cast<char>(LETTER_TRAP_CHARACTER));
				}
			}
			else
			{
				i--;
			}
		}
	}

	duplicateBoard(board, initialBoard);

	resetBoard();
}

void makeMove(WORLD_CODES world, MOVES direction)
{
	if (isMoveAvailable(direction))
	{
		if (isPlayerOnEdge(direction))
		{
			switch (direction)
			{
			case MOVES::up:
				swapValues(playerCoords, { playerCoords.X, static_cast<short>(playerCoords.Y - 1) });
				playerCoords.Y--;
				break;
			case MOVES::down:
				swapValues(playerCoords, { playerCoords.X, static_cast<short>(playerCoords.Y + 1) });
				playerCoords.Y++;
				break;
			case MOVES::left:
				swapValues(playerCoords, { static_cast<short>(playerCoords.X - 1), playerCoords.Y });
				playerCoords.X--;
				break;
			case MOVES::right:
				swapValues(playerCoords, { static_cast<short>(playerCoords.X + 1), playerCoords.Y });
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
				swapValues({ playerCoords.X, static_cast<short>(playerCoords.Y - 1) }, { playerCoords.X, static_cast<short>(playerCoords.Y - 2) });
				swapValues(playerCoords, { playerCoords.X, static_cast<short>(playerCoords.Y - 1) });
				playerCoords.Y--;
				break;
			case MOVES::down:
				swapValues({ playerCoords.X, static_cast<short>(playerCoords.Y + 1) }, { playerCoords.X, static_cast<short>(playerCoords.Y + 2) });
				swapValues(playerCoords, { playerCoords.X, static_cast<short>(playerCoords.Y + 1) });
				playerCoords.Y++;
				break;
			case MOVES::left:
				swapValues({ static_cast<short>(playerCoords.X - 1), playerCoords.Y }, { static_cast<short>(playerCoords.X - 2), playerCoords.Y });
				swapValues(playerCoords, { static_cast<short>(playerCoords.X - 1), playerCoords.Y });
				playerCoords.X--;
				break;
			case MOVES::right:
				swapValues({ static_cast<short>(playerCoords.X + 1), playerCoords.Y }, { static_cast<short>(playerCoords.X + 2), playerCoords.Y });
				swapValues(playerCoords, { static_cast<short>(playerCoords.X + 1), playerCoords.Y });
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

bool isWall(char value)
{
	return value == static_cast<char>(WALL_CHARACTER);
}

bool isAvailable(char value)
{
	return value == ' ';
}

void swapValues(COORD first, COORD second)
{
	char tempChar = getValue(second.X, second.Y);

	assignValue(second.X, second.Y, getValue(first.X, first.Y));
	assignValue(first.X, first.Y, tempChar);
}

void moveToRandomCOORD(COORD toMove)
{
	GRand random;
	bool swapped = false;
	while (!swapped)
	{
		COORD moveTo = { static_cast<short>(random.i(7) + 1), static_cast<short>(random.i(7) + 1) };
		if (isAvailable(getValue(moveTo.X, moveTo.Y)))
		{
			if (getValue(toMove.X, toMove.Y) == static_cast<char>(PLAYER_CHARACTER))
			{
				playerCoords = moveTo;
			}
			swapValues(toMove, moveTo);
			swapped = true;
		}
	}
}

bool isPlayerOnEdgeUp()
{
	if (playerCoords.Y != 0)
	{
		if (playerCoords.Y == 1)
		{
			return true;
		}

		if (playerCoords.Y > 1)
		{
			if (!isLetter(getValue(playerCoords.X, playerCoords.Y - 1)) && !isAvailable(getValue(playerCoords.X, playerCoords.Y - 2)))
			{
				return true;
			}

			if (getValue(playerCoords.X, playerCoords.Y - 1) == ' ')
			{
				if (getValue(playerCoords.X, playerCoords.Y - 2) == static_cast<char>(WALL_CHARACTER))
				{
					return true;
				}
			}
		}

		return false;
	}

	return false;
}

bool isPlayerOnEdgeDown()
{
	if (playerCoords.Y != 9)
	{
		if (playerCoords.Y == 8)
		{
			return true;
		}

		if (playerCoords.Y < 8)
		{
			if (!isLetter(getValue(playerCoords.X, playerCoords.Y + 1)) && !isAvailable(getValue(playerCoords.X, playerCoords.Y + 2)))
			{
				return true;
			}

			if (getValue(playerCoords.X, playerCoords.Y + 1) == ' ')
			{
				if (getValue(playerCoords.X, playerCoords.Y + 2) == static_cast<char>(WALL_CHARACTER))
				{
					return true;
				}
			}
		}

		return false;
	}

	return false;
}

bool isPlayerOnEdgeLeft()
{
	if (playerCoords.X != 0)
	{
		if (playerCoords.X == 1)
		{
			return true;
		}

		if (playerCoords.X > 1)
		{
			if (!isLetter(getValue(playerCoords.X - 1, playerCoords.Y)) && !isAvailable(getValue(playerCoords.X - 2, playerCoords.Y)))
			{
				return true;
			}
		}

		if (getValue(playerCoords.X - 1, playerCoords.Y) == ' ')
		{
			if (getValue(playerCoords.X - 2, playerCoords.Y) == static_cast<char>(WALL_CHARACTER))
			{
				return true;
			}
		}

		return false;
	}

	return false;
}

bool isPlayerOnEdgeRight()
{
	if (playerCoords.X != 9)
	{
		if (playerCoords.X == 8)
		{
			return true;
		}

		if (playerCoords.X < 8)
		{
			if (!isLetter(getValue(playerCoords.X + 1, playerCoords.Y)) && !isAvailable(getValue(playerCoords.X + 2, playerCoords.Y)))
			{
				return true;
			}
		}

		if (getValue(playerCoords.X + 1, playerCoords.Y) == ' ')
		{
			if (getValue(playerCoords.X + 2, playerCoords.Y) == static_cast<char>(WALL_CHARACTER))
			{
				return true;
			}
		}

		return false;
	}

	return false;
}

bool isPlayerOnEdge(MOVES direction)
{
	switch (direction)
	{
	case MOVES::up:
		return isPlayerOnEdgeUp();
	case MOVES::down:
		return isPlayerOnEdgeDown();
	case MOVES::left:
		return isPlayerOnEdgeLeft();
	case MOVES::right:
		return isPlayerOnEdgeRight();
	default:
		return false;
	}

	return false;
}

bool isMoveAvailableUp()
{
	if (playerCoords.Y != 0)
	{
		if (getValue(playerCoords.X, playerCoords.Y - 1) == static_cast<char>(LETTER_TRAP_CHARACTER))
		{
			moveToRandomCOORD(playerCoords);
			return false;
		}

		if (getValue(playerCoords.X, playerCoords.Y - 1) == static_cast<char>(WALL_CHARACTER))
		{
			return false;
		}
	}

	if (playerCoords.Y > 1)
	{
		if (isLetter(getValue(playerCoords.X, playerCoords.Y - 1)))
		{
			if (getValue(playerCoords.X, playerCoords.Y - 2) == static_cast<char>(LETTER_TRAP_CHARACTER))
			{
				moveToRandomCOORD({ playerCoords.X, static_cast<short>(playerCoords.Y - 1) });
				return true;
			}

			if (getValue(playerCoords.X, playerCoords.Y - 2) == static_cast<char>(WALL_CHARACTER))
			{
				return false;
			}
		}
	}

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
}

bool isMoveAvailableDown()
{
	if (playerCoords.Y != 9)
	{
		if (getValue(playerCoords.X, playerCoords.Y + 1) == static_cast<char>(LETTER_TRAP_CHARACTER))
		{
			moveToRandomCOORD(playerCoords);
			return false;
		}

		if (getValue(playerCoords.X, playerCoords.Y + 1) == static_cast<char>(WALL_CHARACTER))
		{
			return false;
		}
	}

	if (playerCoords.Y < 8)
	{
		if (isLetter(getValue(playerCoords.X, playerCoords.Y + 1)))
		{
			if (getValue(playerCoords.X, playerCoords.Y + 2) == static_cast<char>(LETTER_TRAP_CHARACTER))
			{
				moveToRandomCOORD({ playerCoords.X, static_cast<short>(playerCoords.Y + 1) });
				return true;
			}

			if (getValue(playerCoords.X, playerCoords.Y + 2) == static_cast<char>(WALL_CHARACTER))
			{
				return false;
			}
		}
	}

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
}

bool isMoveAvailableLeft()
{
	if (playerCoords.X != 0)
	{
		if (getValue(playerCoords.X - 1, playerCoords.Y) == static_cast<char>(LETTER_TRAP_CHARACTER))
		{
			moveToRandomCOORD(playerCoords);
			return false;
		}

		if (getValue(playerCoords.X - 1, playerCoords.Y) == static_cast<char>(WALL_CHARACTER))
		{
			return false;
		}
	}

	if (playerCoords.X > 1)
	{
		if (isLetter(getValue(playerCoords.X - 1, playerCoords.Y)))
		{
			if (getValue(playerCoords.X - 2, playerCoords.Y) == static_cast<char>(LETTER_TRAP_CHARACTER))
			{
				moveToRandomCOORD({ static_cast<short>(playerCoords.X - 1), playerCoords.Y });
				return true;
			}

			if (getValue(playerCoords.X - 2, playerCoords.Y) == static_cast<char>(WALL_CHARACTER))
			{
				return false;
			}
		}
	}

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
}

bool isMoveAvailableRight()
{
	if (playerCoords.X != 9)
	{
		if (getValue(playerCoords.X + 1, playerCoords.Y) == static_cast<char>(LETTER_TRAP_CHARACTER))
		{
			moveToRandomCOORD(playerCoords);
			return false;
		}

		if (getValue(playerCoords.X + 1, playerCoords.Y) == static_cast<char>(WALL_CHARACTER))
		{
			return false;
		}
	}

	if (playerCoords.X < 8)
	{
		if (getValue(playerCoords.X + 2, playerCoords.Y) == static_cast<char>(LETTER_TRAP_CHARACTER))
		{
			moveToRandomCOORD({ static_cast<short>(playerCoords.X + 1), playerCoords.Y });
			return true;
		}

		if (isLetter(getValue(playerCoords.X + 1, playerCoords.Y)))
		{
			if (getValue(playerCoords.X + 2, playerCoords.Y) == static_cast<char>(WALL_CHARACTER))
			{
				return false;
			}
		}
	}

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
}

bool isMoveAvailable(MOVES direction)
{
	switch (direction)
	{
	case MOVES::up:
		return isMoveAvailableUp();

	case MOVES::down:
		return isMoveAvailableDown();

	case MOVES::left:
		return isMoveAvailableLeft();

	case MOVES::right:
		return isMoveAvailableRight();

	default:
		return false;
	}
}

bool winCheck(LEVEL_CODES level)
{
	int length = static_cast<int>(currentWord.length());

	COORD firstLetterPos = findCOORD(currentWord[0]);

	if (firstLetterPos.X <= 10 - length)
	{
		switch (length)
		{
		case 3:
			return getValue(firstLetterPos.X, firstLetterPos.Y) == currentWord[0] &&
				getValue(firstLetterPos.X + 1, firstLetterPos.Y) == currentWord[1] &&
				getValue(firstLetterPos.X + 2, firstLetterPos.Y) == currentWord[2];
		case 4:
			return getValue(firstLetterPos.X, firstLetterPos.Y) == currentWord[0] &&
				getValue(firstLetterPos.X + 1, firstLetterPos.Y) == currentWord[1] &&
				getValue(firstLetterPos.X + 2, firstLetterPos.Y) == currentWord[2] &&
				getValue(firstLetterPos.X + 3, firstLetterPos.Y) == currentWord[3];
		case 5:
			return getValue(firstLetterPos.X, firstLetterPos.Y) == currentWord[0] &&
				getValue(firstLetterPos.X + 1, firstLetterPos.Y) == currentWord[1] &&
				getValue(firstLetterPos.X + 2, firstLetterPos.Y) == currentWord[2] &&
				getValue(firstLetterPos.X + 3, firstLetterPos.Y) == currentWord[3] &&
				getValue(firstLetterPos.X + 4, firstLetterPos.Y) == currentWord[4];
		default:
			break;
		}
	}
	else
	{
		return false;
	}
	
	return false;
}