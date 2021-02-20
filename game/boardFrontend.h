#pragma once

#include "boardBackend.h"

void startWorldGen(WORLD_CODES currentlySelectedWorld, LEVEL_CODES currentlySelectedLevel);
void printFirstRow();
void printMiddleRow(int counts[2]);
void printBottomRow();
void printLastRow();
void printBoard();
void winLogic(LEVEL_CODES currentlySelectedLevel);
void getUserInput();


