#pragma once

#include <windows.h>
#include <string>

#define BOARD_SIZE 10

enum class WORLD_CODES
{
	worldOne,
	worldTwo,
	worldThree,
};

enum class LEVEL_CODES
{
	levelOne,
	levelTwo,
	levelThree,
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
std::string getWord(LEVEL_CODES word);
COORD getRandomCOORD();
void fillCOORD(COORD* cords, short filler);
bool checkMathching(COORD* cords, COORD temp);
void resetBoard();
void generateWorldOneBoard(LEVEL_CODES level);
void generateBoard(WORLD_CODES world, LEVEL_CODES level);
void makeMove(WORLD_CODES world, MOVES direction);
void makeMoveWoldOne(MOVES direction);
bool isLetter(char letter);
void swap(COORD first, COORD second);
bool playerOnEdge(MOVES direction);
bool moveAvailableWorldOne(MOVES direction);