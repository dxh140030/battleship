#include "board.h"

void Board::generateBoard(vector<vector<Tile>> & gameBoard)
{
	gameBoard.resize(10, vector<Tile>(10));

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			//fill out y values
			switch (i) 
			{
			case 0:
				gameBoard[i][j].xPosition = 'A';
				break;
			case 1:
				gameBoard[i][j].xPosition = 'B';
				break;
			case 2:
				gameBoard[i][j].xPosition = 'C';
				break;
			case 3:
				gameBoard[i][j].xPosition = 'D';
				break;
			case 4:
				gameBoard[i][j].xPosition = 'E';
				break;
			case 5:
				gameBoard[i][j].xPosition = 'F';
				break;
			case 6:
				gameBoard[i][j].xPosition = 'G';
				break;
			case 7:
				gameBoard[i][j].xPosition = 'H';
				break;
			case 8:
				gameBoard[i][j].xPosition = 'I';
				break;
			case 9:
				gameBoard[i][j].xPosition = 'J';
				break;
			}
			gameBoard[i][j].yPosition = j + 1;
		}
	}

}
//displays the current board
void Board::displayBoard()
{
	cout << "Displaying board" << endl;
	cout << "+                     +" << endl;
	for (int j = 0; j < 10; j++)
	{
		cout << "  ";
		for (int i = 0; i < 10; i++)
		{
			//cout << i << "," << j ;
			if (gameBoard[i][j].occupied == true)
			{
				cout << "x ";
			}
			else
			{
				cout << "- ";
			}
		}
		cout << endl;
	}
	cout << "+                     +" << endl;
}

//convert input char to corresponding number
int Board::xPositionTranslate(char xPos)
{
	int xPositionInArray;
	switch (xPos)
	{
	case 'A':
		xPositionInArray = 0;
		break;
	case 'B':
		xPositionInArray = 1;
		break;
	case 'C':
		xPositionInArray = 2;
		break;
	case 'D':
		xPositionInArray = 3;
		break;
	case 'E':
		xPositionInArray = 4;
		break;
	case 'F':
		xPositionInArray = 5;
		break;
	case 'G':
		xPositionInArray = 6;
		break;
	case 'H':
		xPositionInArray = 7;
		break;
	case 'I':
		xPositionInArray = 8;
		break;
	case 'J':
		xPositionInArray = 9;
		break;

	}
	return xPositionInArray;
}

//sets the "hit" boolean in a given tile at [x,y] to true
void Board::tileHit(char xPos, int yPos)
{
	int xPosInt = xPositionTranslate(xPos);
	gameBoard[xPosInt][yPos].hit = true;
}

Board::~Board()
{
	cout << "Deleting board" << endl;

}