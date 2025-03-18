#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<char>> initMap(int row, int col);
void drawMap();
void drawSquare(int width, int posX, int posY);
void drawTriangle(int width, int posX, int posY, string direction);
void drawLine(int x1, int y1, int x2, int y2);

vector<vector<char>> map;

int main() {
	string firstCommand;
	int rowSize, colSize;
	cin >> colSize;
	cin >> rowSize;

	map = initMap(rowSize, colSize);

	while (true)
	{
		cin >> firstCommand;
		if (firstCommand == "S") {
			int width, posX, posY;
			cin >> width >> posX >> posY;

			if (width <= rowSize && width <= colSize) {
				drawSquare(width, posX, posY);
				drawMap();
			}
			else cout << "Out of range.\n";

		}
		else if (firstCommand == "T") {
			int width, posX, posY;
			string direction;
			cin >> width >> posX >> posY >> direction;
			if (width <= rowSize && width <= colSize) {
				drawTriangle(width, posX, posY, direction);
				drawMap();
			}
		}
		else if (firstCommand == "L") {
			int x1, x2, y1, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			int width = min(colSize, rowSize);
			if (width <= abs(x1 - x2) && width <= abs(y1 - y2) && width <= abs(x1 - y2) && width <= abs(y1 - x2)) {
				drawLine(x1, y1, x2, y2);
				drawMap();
			}
			else cout << "Out of range.\n";
		}
		else if (firstCommand == "EXIT") break;

	}
}

vector<vector<char>> initMap(int row, int col) {
	vector<vector<char>> newMap(row, vector<char>(col, '*'));
	return newMap;
}

void drawMap() {
	for (size_t i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

void drawSquare(int width, int posX, int posY) {
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < width; j++)
		{
			map[posX + i][posY + j] = 'X';
		}
	}
}

void drawTriangle(int width, int posX, int posY, string direction) {
	if (direction == "LU") {
		for (size_t i = 0; i < width; i++)
		{
			for (int j = 0; j <= i; j++) {
				map[posY + i - 1][posX + width - j - 2] = 'X';
			}
		}
	}
	else if (direction == "LD") {
		for (size_t i = 0; i < width; i++)
		{
			for (int j = i; j < width; j++) {
				map[posY + i][posX - width + j + 1] = 'X';
			}
		}
	}
	else if (direction == "RU") {
		for (size_t i = 0; i < width; i++)
		{
			for (int j = 0; j <= i; j++) {
				map[posY - width + i + 1][posX + j] = 'X';
			}
		}
	}
	else if (direction == "RD") {
		for (size_t i = 0; i < width; i++)
		{
			for (int j = width - i; j > 0; j--) {
				map[posY + i][posX + j - 1] = 'X';
			}
		}
	}
}
