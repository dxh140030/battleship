// battleship.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "board.h"

using namespace std;

int main()
{
	Board board;

	shipMethods methods;
	//methods.shipArsenal();
	Carrier carrier = Carrier();
	cout << "Carrier " << carrier.shipTiles.size() << endl;
	Battleship battleship;
	Submarine submarine;
	Cruiser cruiser;
	Destroyer destroyer;

	board.generateBoard(board.gameBoard); 

	methods.shipPlaceRandom(board.gameBoard, carrier);

	methods.shipPlaceRandom(board.gameBoard, battleship);
	methods.shipPlaceRandom(board.gameBoard, submarine);
	methods.shipPlaceRandom(board.gameBoard, cruiser);
	methods.shipPlaceRandom(board.gameBoard, destroyer);

	board.displayBoard();


    return 0;
}

