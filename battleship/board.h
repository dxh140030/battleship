#pragma once
#ifndef BOARD
#define BOARD

#include "ships.h"
#include <iostream>
#include <vector>

using namespace std;

struct Tile
{
	char xPosition;
	int yPosition;
	bool occupied = false;
	bool miss = false;
	bool hit = false;
};

class Board
{
public:
	vector<vector<Tile>> gameBoard;
	void generateBoard(vector<vector<Tile>> & board);
	void displayBoard();
	int xPositionTranslate(char xPos);
	void tileHit(char xPos, int yPos);

	Board()
	{
		generateBoard(gameBoard);
	}

	~Board();

};

class primaryBoard : public Board
{

};

class targetingBoard : public Board
{

};

#endif