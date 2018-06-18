#include "ships.h"
#include <iostream>
#include <random>

void Ship::setFacing(char inputFacing)
{
	facing = inputFacing;
}

void Ship::setRootBit(int xPos, int yPos)
{
	rootBit.xPosition = xPos;
	rootBit.yPosition = yPos;
}

void shipMethods::setShipBit(shipBit bit, int xPos, int yPos)
{
	bit.xPosition = xPos;
	bit.yPosition = yPos;
}

void Ship::buildShip(Ship & ship, vector<vector<Tile>> & gameBoard)
{
	gameBoard[ship.rootBit.xPosition][ship.rootBit.yPosition].occupied = true; 
	cout << "Ship rooted at " << ship.rootBit.xPosition << "," << ship.rootBit.yPosition <<
		" with heading " << ship.facing << endl;

	//given direction, decide which direction to build the rest of the ship
	for (int i = 1; i < ship.length; i++)
	{
		if (ship.facing == 'N')
		{
			ship.shipTiles[i].xPosition = ship.rootBit.xPosition;
			ship.shipTiles[i].yPosition = ship.rootBit.yPosition - i;
		}
		else if (ship.facing == 'E')
		{
			ship.shipTiles[i].yPosition = ship.rootBit.yPosition;
			ship.shipTiles[i].xPosition = ship.rootBit.xPosition + i;
		}
		else if (ship.facing == 'S')
		{
			ship.shipTiles[i].xPosition = ship.rootBit.xPosition;
			ship.shipTiles[i].yPosition = ship.rootBit.yPosition + i;
		}
		else if (ship.facing == 'W')
		{
			ship.shipTiles[i].yPosition = ship.rootBit.yPosition;
			ship.shipTiles[i].xPosition = ship.rootBit.xPosition - i;
		}
		cout << ship.shipTiles[i].xPosition << "," << ship.shipTiles[i].yPosition << endl;
		gameBoard[ship.shipTiles[i].xPosition][ship.shipTiles[i].yPosition].occupied = true;
	}
}

void shipMethods::shipPlaceRandom(vector<vector<Tile>> & gameBoard, Ship & ship)
{
	//TODO generate ships then place them randomly
	//given a ship, put it in a random spot on the board
	//generateShips
	random_device rd;
	int randomDirectionNum;
	char direction;
	int randomRootX, randomRootY;
	shipBit bit;

	do
	{
		randomDirectionNum = rd() % 4;
		direction = randomDirectionNum;
		randomRootX = rd() % 10;
		randomRootY = rd() % 10;
		bit.xPosition = randomRootX;
		bit.yPosition = randomRootY;
		switch (randomDirectionNum)
		{
		case 0:
			direction = 'N';
			break;
		case 1:
			direction = 'E';
			break;
		case 2:
			direction = 'S';
			break;
		case 3:
			direction = 'W';
			break;
		}
	} while (boundsCheck(ship.length, direction, bit.xPosition, bit.yPosition, gameBoard) == false);

	ship.setFacing(direction);
	ship.setRootBit(bit.xPosition, bit.yPosition);
	ship.shipTiles[0].xPosition = ship.rootBit.xPosition;
	ship.shipTiles[0].yPosition = ship.rootBit.yPosition;
	ship.buildShip(ship, gameBoard);
	cout << "Ship placed." << endl;
}


void shipMethods::shipArsenal(vector<vector<Tile>> & gameBoard)
{
	Carrier carrier;
	Battleship battleship;
	Submarine submarine;
	Cruiser cruiser;
	Destroyer destroyer;

}

//given rootBit and facing, figure out if a ship fits in the board
bool shipMethods::boundsCheck(int length, char direction, int xPosition, int yPosition, vector<vector<Tile>> & gameBoard)
{
	bool fits = true;
	int placement;

	//issue -- attempting to read "occupied" status from tiles that don't exist?
	if (direction == 'N')
	{
		placement = yPosition - length;
		if (placement < 0 || placement > 10)
			fits = false;

		if (fits == true)
		{
			for (int i = 0; i < length; i++)
			{
				//cout << xPosition << "," << yPosition - i << " " << gameBoard[xPosition][yPosition - i].occupied << endl;
				if (gameBoard[xPosition][yPosition - i].occupied == true)
				{
					cout << "Collision!" << endl;
					fits = false;
				}
			}
		}
	}
	else if (direction == 'E')
	{
		placement = xPosition + length;
		if (placement < 0 || placement > 10)
			fits = false;

		if (fits == true)
		{
			for (int i = 0; i < length; i++)
			{
				//cout << xPosition + i << "," << yPosition << " " << gameBoard[xPosition + i][yPosition].occupied << endl;
				if (gameBoard[xPosition + i][yPosition].occupied == true)
				{
					cout << "Collision!" << endl;
					fits = false;
				}
			}
		}
	}
	else if (direction == 'S')
	{
		placement = yPosition + length;
		if (placement < 0 || placement > 10)
			fits = false;

		if (fits == true)
		{
			for (int i = 0; i < length; i++)
			{
				//cout << xPosition << "," << yPosition + i << " " << gameBoard[xPosition][yPosition + i].occupied << endl;
				if (gameBoard[xPosition][yPosition + i].occupied == true)
				{
					cout << "Collision!" << endl;
					fits = false;
				}
			}
		}
	}
	else //W
	{
		placement = xPosition - length;
		if (placement < 0 || placement > 10)
			fits = false;

		if (fits == true)
		{
			for (int i = 0; i < length; i++)
			{
				//cout << xPosition - i << "," << yPosition << " " << gameBoard[xPosition - i][yPosition].occupied << endl;
				if (gameBoard[xPosition - i][yPosition].occupied == true)
				{
					cout << "Collision!" << endl;
					fits = false;
				}
			}
		}
	}


	if (fits == false)
		cout << "Bounds hit. Recalculating." << endl;
	else
		cout << "Bounds fit." << endl;
	return fits;
}

Carrier::~Carrier()
{
	cout << "Deleting carrier" << endl;
	shipTiles.clear();
}
Battleship::~Battleship()
{
	cout << "Deleting battleship" << endl;
	shipTiles.clear();
}
Cruiser::~Cruiser()
{
	cout << "Deleting cruiser" << endl;
	shipTiles.clear();
}
Submarine::~Submarine()
{
	cout << "Deleting submarine" << endl;
	shipTiles.clear();
}
Destroyer::~Destroyer()
{
	cout << "Deleting destroyer" << endl;
	shipTiles.clear();
}