/***********************************************************************
 * File: Source.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-04-01
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-04-01
 * Description: A Shisensho game solver.
***********************************************************************/
#include <iostream>
using namespace std;

struct Position //represent a position on the board
{
	int x, y;
};

enum Direction //indicate directions
{
	UP,
	RIGHT,
	DOWN,
	LEFT,
	NONE
};

//find the number of turns required to connect two tiles
int getTurns(int map[8][8], Position pos1, Position pos2, Position nowPos, int turns, Direction lastDirection);

int main() {
	int map[8][8] = { 0 }; // Initialize the game board (map border is empty) 

	for (size_t i = 0; i < 8; i++) // Loop to initialize the game board
	{
		for (size_t j = 0; j < 8; j++)
		{
			map[i][j] = -1; //-1 to represent empty tile
		}
	}

	for (size_t i = 1; i < 7; i++) // Loop to input the initial game board
	{
		for (size_t j = 1; j < 7; j++)
		{
			int mapInput;
			cin >> mapInput;
			map[i][j] = mapInput;
		}
	}

	while (true) // Loop to process each pair of positions
	{
		Position pos1, pos2; // Positions of the pair of tiles
		int turns = 0; // Initialize turns counter
		cin >> pos1.x >> pos1.y >> pos2.x >> pos2.y; // Input positions of the pair
		pos1.x++; //shift x, y 1 block (map border is empty) 
		pos1.y++;
		pos2.x++;
		pos2.y++;

		if (cin.eof()) { // Check for end of input
			break;
		}

		turns = getTurns(map, pos1, pos2, pos1, 0, NONE); // Get the number of turns

		// Check if the pair is legal and can be eliminated
		if (turns != -1 && turns < 3 
			&& map[pos1.y][pos1.x] == map[pos2.y][pos2.x] 
			&& !(pos1.x == pos2.x && pos1.y == pos2.y) 
			&& map[pos1.y][pos1.x] != -1) {
			cout << "pair matched\n";
			map[pos1.y][pos1.x] = -1; //eliminated pair
			map[pos2.y][pos2.x] = -1;
		}
		else {
			cout << "bad pair\n";
		}
	}
}

/*
 *  Intent: Recursively find the number of turns required to connect two tiles on the game board
 *  Pre: Game board, positions of the two tiles, current position, number of turns, last direction
 *  Post: Returns the number of turns required to connect the two tiles, or -1 if no connection is possible
 */
int getTurns(int map[8][8], Position pos1, Position pos2, Position nowPos, int turns, Direction defaultDirect) {
	if (nowPos.x == pos2.x && pos2.y == nowPos.y) { // Check if the current position is the destination
		return turns;
	}

	// Check if out of bounds or too many turns
	if (nowPos.x >= 8 || nowPos.y >= 8 || nowPos.x < 0 || nowPos.y < 0 || turns > 2) {
		return -1;
	}

	// Check if the tile is occupied and not the starting position
	if (map[nowPos.y][nowPos.x] != -1 && defaultDirect != NONE) {
		return -1;
	}

	int minTurns = 1000000000; // Initialize minimum turns
	int directTurns[4] = { -1,-1,-1,-1 }; // Array to store the number of turns in each direction

	// Initialize next positions for each directions
	Position upPos = nowPos, leftPos = nowPos, rightPos = nowPos, downPos = nowPos;
	upPos.y++;
	leftPos.x--;
	rightPos.x++;
	downPos.y--;

	// Determine the possible directions based on the last direction
	// get each direction turn times
	if (defaultDirect == UP) {
		directTurns[0] = getTurns(map, pos1, pos2, upPos, turns, UP);
		directTurns[3] = getTurns(map, pos1, pos2, leftPos, turns + 1, LEFT);
		directTurns[1] = getTurns(map, pos1, pos2, rightPos, turns + 1, RIGHT);
	}
	else if (defaultDirect == RIGHT) {
		directTurns[0] = getTurns(map, pos1, pos2, upPos, turns + 1, UP);
		directTurns[2] = getTurns(map, pos1, pos2, downPos, turns + 1, DOWN);
		directTurns[1] = getTurns(map, pos1, pos2, rightPos, turns, RIGHT);
	}
	else if (defaultDirect == DOWN) {
		directTurns[2] = getTurns(map, pos1, pos2, downPos, turns, DOWN);
		directTurns[3] = getTurns(map, pos1, pos2, leftPos, turns + 1, LEFT);
		directTurns[1] = getTurns(map, pos1, pos2, rightPos, turns + 1, RIGHT);
	}else if (defaultDirect == LEFT) {
		directTurns[0] = getTurns(map, pos1, pos2, upPos, turns + 1, UP);
		directTurns[3] = getTurns(map, pos1, pos2, leftPos, turns, LEFT);
		directTurns[2] = getTurns(map, pos1, pos2, downPos, turns + 1, DOWN);
	}
	else if (defaultDirect == NONE) {
		directTurns[0] = getTurns(map, pos1, pos2, upPos, turns , UP);
		directTurns[3] = getTurns(map, pos1, pos2, leftPos, turns, LEFT);
		directTurns[2] = getTurns(map, pos1, pos2, downPos, turns , DOWN);
		directTurns[1] = getTurns(map, pos1, pos2, rightPos, turns , RIGHT);
	}

	bool canFindPath = false; // Variable to check if a valid path is found

	for (size_t i = 0; i < 4; i++) // Loop through all directions
	{
		if (directTurns[i] != -1 && directTurns[i] < minTurns) { // Check if a valid path is found in this direction, and less than minTurn
			minTurns = directTurns[i];
			canFindPath = true;
		}
	}

	if (canFindPath == true) {// Check if a valid path is found
		return minTurns;
	}

	return -1;
}
