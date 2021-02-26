#pragma once

#include "boardBackend.h"

enum class BOARD_CHARACTERS
{
	topLeftCorner,
	topRightCorner,
	bottomLeftCorner,
	bottomRightCorner,
	topToBottom,
	bottomToTop,
	leftToRight,
	rightToLeft,
	cross,
	horizontalLine,
	verticalLine,
};

char boardCharacters[];

void checkHandle();
void errorDisplay();
void setTextColor(int color);
void goToXY(short x, short y);
void setAllMainMenuColors(int val);
void setAllWinMenuColors(int val);
void updateMainMenuColors(int num);
void updateWinMenuColors(int num);
void setAllWorldColors(int world[], int color);
void setSpecificWorldColor(int world[], int level, int color);
void printWorldOne(int currentlySelected);
void printWorldTwo(int currentlySelected);
void printWorldThree(int currentlySelected);
void printLevelSelect(int world);
void resetHowToPlay();
void printHowToPlay(int page);
void printAboutUs();
void Exit();
void printMenu(int activeOption);
WORLD_CODES incrementWorld(WORLD_CODES world);
LEVEL_CODES incrementLevel(LEVEL_CODES level);
void printWinMenu(int activeOption, LEVEL_CODES previousLevel, WORLD_CODES curentWorld);