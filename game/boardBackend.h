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
void generateWorldOneBoard(LEVEL_CODES level);
void generateWorldTwoBoard(LEVEL_CODES level);
void generateWorldThreeBoard(LEVEL_CODES level);
void generateBoard(WORLD_CODES world, LEVEL_CODES level);
void makeMove(WORLD_CODES world, MOVES direction);
bool isLetter(char letter);
bool isWall(char value);
bool isAvailable(char value);
void swap(COORD first, COORD second);
bool playerOnEdge(MOVES direction);
bool moveAvailable(MOVES direction);
bool winCheck(LEVEL_CODES level);