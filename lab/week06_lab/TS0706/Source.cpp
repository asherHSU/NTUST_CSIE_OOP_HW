#include <iostream>
using namespace std;

struct Position
{
	int x, y;
};

enum Direction
{
	UP,
	RIGHT,
	DOWN,
	LEFT,
	NONE
};

int getTurns(int map[8][8], Position pos1, Position pos2, Position nowPos, int turns, Direction lastDirection);

int main() {
	int map[8][8] = { 0 };

	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			map[i][j] = -1;
		}
	}

	for (size_t i = 1; i < 7; i++)
	{
		for (size_t j = 1; j < 7; j++)
		{
			int mapInput;
			cin >> mapInput;
			map[i][j] = mapInput;
		}
	}

	while (true)
	{
		Position pos1, pos2;
		int turns = 0;
		cin >> pos1.x >> pos1.y >> pos2.x >> pos2.y;
		pos1.x++;
		pos1.y++;
		pos2.x++;
		pos2.y++;

		if (cin.eof()) {
			break;
		}

		turns = getTurns(map, pos1, pos2, pos1, 0, NONE);

		if (turns != -1 && turns < 3 
			&& map[pos1.y][pos1.x] == map[pos2.y][pos2.x] 
			&& !(pos1.x == pos2.x && pos1.y == pos2.y) 
			&& map[pos1.y][pos1.x] != -1) {
			cout << "pair matched\n";
			map[pos1.y][pos1.x] = -1;
			map[pos2.y][pos2.x] = -1;
		}
		else {
			cout << "bad pair\n";
		}
	}
}

int getTurns(int map[8][8], Position pos1, Position pos2, Position nowPos, int turns, Direction defaultDirect) {
	if (nowPos.x == pos2.x && pos2.y == nowPos.y) {
		return turns;
	}

	if (nowPos.x >= 8 || nowPos.y >= 8 || nowPos.x < 0 || nowPos.y < 0 || turns > 2) {
		return -1;
	}

	if (map[nowPos.y][nowPos.x] != -1 && defaultDirect != NONE) {
		return -1;
	}

	int minTurns = 1000000000;
	int directTurns[4] = { -1,-1,-1,-1 };

	Position upPos = nowPos, leftPos = nowPos, rightPos = nowPos, downPos = nowPos;
	upPos.y++;
	leftPos.x--;
	rightPos.x++;
	downPos.y--;

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

	bool canFindPath = false;

	for (size_t i = 0; i < 4; i++)
	{
		if (directTurns[i] != -1 && directTurns[i] < minTurns) {
			minTurns = directTurns[i];
			canFindPath = true;
		}
	}

	if (canFindPath == true) {
		return minTurns;
	}

	return -1;
}
