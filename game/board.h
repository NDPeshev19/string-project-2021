#pragma once

#include <windows.h>
#include <string>

enum class WORLD_CODES;
enum class LEVEL_CODES;

void assignValue(short x, short y, char character);
char getValue(short x, short y);
void fillBoard(int boardSize, char filler);
std::string getWord(LEVEL_CODES word);
COORD getRandomCOORD();
void fillCOORD(COORD* cords, short filler);
bool checkMathching(COORD* cords, COORD temp);
void generateWorldOneBoard(LEVEL_CODES level);
void generateBoard(WORLD_CODES world, LEVEL_CODES level);