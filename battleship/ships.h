#pragma once
#ifndef SHIPS
#define SHIPS

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

#include "board.h"

using namespace std;

struct Tile;
struct shipBit
{
	int xPosition;
	int yPosition;
	bool hit = false;
};

class Ship
{
public:
	int length; //# of shipbits in ship
	char facing; //N,E,S,W
	shipBit rootBit; //shipbit from which the rest of the ship is built
	vector<shipBit> shipTiles;
	bool sunk = false;

	void setFacing(char inputFacing);
	void setRootBit(int xPos, int yPos);
	void buildShip(Ship & ship, vector<vector<Tile>> & gameBoard);


};

class Carrier : public Ship
{
public:
	Carrier()
	{
		length = 5;
		shipTiles.resize(5);

	}
	Carrier(char direction, shipBit root)
	{
		shipTiles.resize(5);
		length = 5;
		facing = direction;
		rootBit = root;	
	}
	~Carrier();

};

class Battleship : public Ship
{
public:
	Battleship()
	{
		length = 4;
		shipTiles.resize(4);

	}
	Battleship(char direction, shipBit root)
	{
		shipTiles.resize(4);
		length = 4;
		facing = direction;
		rootBit = root;	}
	~Battleship();

};

class Cruiser : public Ship
{
public:
	Cruiser()
	{
		length = 3;
		shipTiles.resize(3);


	}
	Cruiser(char direction, shipBit root)
	{
		shipTiles.resize(3);
		length = 3;
		facing = direction;
		rootBit = root;
	}
	~Cruiser();
};

class Submarine : public Ship
{
public:
	Submarine()
	{
		length = 3;
		shipTiles.resize(3);


	}
	Submarine(char direction, shipBit root)
	{
		shipTiles.resize(3);
		length = 3;
		facing = direction;
		rootBit = root;	
	}
	~Submarine();
};

class Destroyer : public Ship
{
public:

	Destroyer()
	{
		length = 2;
		shipTiles.resize(2);


	}
	Destroyer(char direction, shipBit root)
	{
		shipTiles.resize(2);
		length = 2;
		facing = direction;
		rootBit = root;
	}
	~Destroyer();
};
#endif

class shipArsenal
{

};

class shipMethods
{
public:
	void setShipBit(shipBit bit, int xPos, int yPos);
	bool boundsCheck(int length, char direction, int xPos, int yPos, vector<vector<Tile>> & gameBoard);
	void shipArsenal(vector<vector<Tile>> & gameBoard);
	void shipPlaceRandom(vector<vector<Tile>> & gameBoard, Ship & ship);





};