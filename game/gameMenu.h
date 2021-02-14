#pragma once

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

void setTextColor(int color);
void goToXY(short x, short y);
void setAllMainMenuColors(int val);
void updateMainMenuColors(int num);
void setAllWorldColors(int world[], int color);
void setSpecificWorldColor(int world[], int level, int color);
void printWorldOne(int currentlySelected);
void printWorldTwo(int currentlySelected);
void printWorldThree(int currentlySelected);
void printLevelSelect(int world);
void printHowToPlay();
void printAboutUs();
void printExit();
void printMenu(int activeOption);