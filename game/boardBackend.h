#pragma once

#include <windows.h>
#include <string>

#define BOARD_SIZE 10

enum class WORLD_CODES
{
	worldOne,
	worldTwo,
	worldThree,
	worldFour,
};

enum class LEVEL_CODES
{
	levelOne,
	levelTwo,
	levelThree,
	levelFour,
};

enum class MOVES
{
	up,
	down,
	left,
	right,
};

void assignValue(short x, short y, char character);
char getValue(short x, short y);
void duplicateBoard(char copy[BOARD_SIZE][BOARD_SIZE], char paste[BOARD_SIZE][BOARD_SIZE]);
void fillBoard(int boardSize, char filler);
COORD findCOORD(char letter);
std::string getWord(LEVEL_CODES word);
COORD getRandomCOORD();
void fillCOORD(COORD* cords, short filler);
bool checkMathching(COORD* cords, COORD temp);
void resetBoard();
void generateBoard(WORLD_CODES world, LEVEL_CODES level);
void makeMove(WORLD_CODES world, MOVES direction);
bool isLetter(char letter);
bool isWall(char value);
bool isAvailable(char value);
void swapValues(COORD first, COORD second);
void moveToRandomCOORD(COORD toMove);
bool isPlayerOnEdgeUp();
bool isPlayerOnEdgeDown();
bool isPlayerOnEdgeLeft();
bool isPlayerOnEdgeRight();
bool isPlayerOnEdge(MOVES direction);
bool isMoveAvailableUp();
bool isMoveAvailableDown();
bool isMoveAvailableLeft();
bool isMoveAvailableRight();
bool isMoveAvailable(MOVES direction);
bool winCheck(LEVEL_CODES level);