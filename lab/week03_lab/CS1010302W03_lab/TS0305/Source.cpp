/***********************************************************************
 * File: Source.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-03-08
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-03-08
 * Description: Simple drawing program allowing users to draw squares, isosceles right triangles, and lines on the console. 
 *				Background is filled with '*'. Figures represented by 'X'. 
***********************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std; 

vector<vector<char>> initMap(int row, int col); // Initialize the drawing board with '*' as background
void drawMap(); // Draw the current state of the drawing board
void drawSquare(int width, int posX, int posY); // Draw a square on the drawing board
void drawTriangle(int width, int posX, int posY, string direction); // Draw an isosceles right triangle on the drawing board
void drawLine(int x1, int y1, int x2, int y2); // Draw a line segment on the drawing board

vector<vector<char>> map; // 2D vector to represent the drawing board

int main() {
	string firstCommand;
	int rowSize, colSize;
	cin >> colSize;
	cin >> rowSize;

	map = initMap(rowSize, colSize); // Initialize the drawing board

	while (true)
	{
		cin >> firstCommand; // Input the first command

		// Process different types of commands
		if (firstCommand == "S") {
			int width, posX, posY;
			cin >> width >> posX >> posY;
			
			// Check if the square is within the drawing board boundaries
			if (width + posY <= rowSize && width + posX <= colSize && posX >= 0 && posY >= 0) {
				drawSquare(width, posX, posY);
				drawMap();
			}
			else cout << "Out of range.\n\n"; // Print error message if out of range

		}
		else if (firstCommand == "T") {
			int width, posX, posY;
			string direction;
			cin >> width >> posX >> posY >> direction;
			
			// Check if the triangle is within the drawing board boundaries
			if (direction == "LU" && posX - width + 1 >= 0 && posX < colSize && posY - width + 1 >= 0 && posY < rowSize) {
				drawTriangle(width, posX, posY, direction);
				drawMap();
			}
			else if (direction == "RU" && posX >= 0 && posX + width - 1 < colSize && posY - width + 1 >= 0 && posY < rowSize) {
				drawTriangle(width, posX, posY, direction);
				drawMap();
			}
			else if (direction == "LD" && posX - width + 1 >= 0 && posX < colSize && posY >= 0 && posY + width - 1 < rowSize) {
				drawTriangle(width, posX, posY, direction);
				drawMap();
			}
			else if (direction == "RD" && posX >= 0 && posX + width - 1 < colSize && posY >= 0 && posY + width - 1 < rowSize) {
				drawTriangle(width, posX, posY, direction);
				drawMap();
			}
			else {
				cout << "Out of range.\n\n"; // Print error message if out of range
			}
		}
		else if (firstCommand == "L") {
			int x1, x2, y1, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			
			// Check if the line segment is within the drawing board boundaries
			if (x1 >= 0 && x2 >= 0 && y1 >= 0 && y2 >= 0 && x1 < colSize && x2 < colSize && y1 < rowSize && y2 < rowSize) {
				drawLine(x1, y1, x2, y2);
				drawMap();
			}
			else cout << "Out of range.\n\n"; // Print error message if out of range
		}
		else if (firstCommand == "EXIT") break; // Exit the program if the command is 'EXIT'

	}
}

/*
 * Intent: Initialize the drawing board with '*' as background.
 * Pre: row and col are positive integers.
 * Post: Returns a 2D vector representing the drawing board.
 */
vector<vector<char>> initMap(int row, int col) {
	vector<vector<char>> newMap(row, vector<char>(col, '*')); // Initialize a 2D vector with '*' as background
	return newMap;
}

/*
 * Intent: Draw the current state of the drawing board.
 * Pre: None.
 * Post: Prints the drawing board to the console.
 */
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

/*
 * Intent: Draw a square on the drawing board.
 * Pre: width, posX, and posY are positive integers, within row and column size 
 * Post: Draws a square with specified parameters on the drawing board.
 */
void drawSquare(int width, int posX, int posY) {
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < width; j++)
		{
			map[posY + i][posX + j] = 'X';
		}
	}
}

/*
 * Intent: Draw an isosceles right triangle on the drawing board.
 * Pre: width, posX, and posY are positive integers, within row and column size. direction is either "LU", "LD", "RU", or "RD".
 * Post: Draws an isosceles right triangle with specified parameters and direction on the drawing board.
 */
void drawTriangle(int width, int posX, int posY, string direction) {
	if (direction == "LU") { // Draw triangle facing left up
		for (size_t i = 0; i < width; i++)
		{
			for (int j = 0; j <= i; j++) {
				map[posY + i - 1][posX + width - j - 2] = 'X';
			}
		}
	}
	else if (direction == "LD") { // Draw triangle facing left down
		for (size_t i = 0; i < width; i++)
		{
			for (int j = i; j < width; j++) {
				map[posY + i][posX - width + j + 1] = 'X';
			}
		}
	}
	else if (direction == "RU") { // Draw triangle facing right up
		for (size_t i = 0; i < width; i++)
		{
			for (int j = 0; j <= i; j++) {
				map[posY - width + i + 1][posX + j] = 'X';
			}
		}
	}
	else if (direction == "RD") { // Draw triangle facing right down
		for (size_t i = 0; i < width; i++)
		{
			for (int j = width - i; j > 0; j--) {
				map[posY + i][posX + j - 1] = 'X';
			}
		}
	}
}

/*
 * Intent: Draw a line segment on the drawing board.
 * Pre: x1, y1, x2, and y2 are positive integers, within row and column size.
 * Post: Draws a line segment with specified endpoints on the drawing board.
 */
void drawLine(int x1, int y1, int x2, int y2) {
	if (x1 == x2 && y1 != y2) { //draw vertial line
		for (size_t i = y1; i <= y2; i++)
		{
			map[i][x1] = 'X';
		}
	}
	else if (x1 != x2 && y1 == y2) { // Draw horizontal line
		for (size_t i = x1; i <= x2; i++)
		{
			map[y1][i] = 'X';
		}
	}
	else if(y1 < y2){ // Draw line from top-left to bottom-right
		for (size_t i = x1; i <= x2; i++)
		{
			map[i][i] = 'X';
		}
	}
	else{ // Draw line from bottom-left to top-right
		for (size_t i = x1; i <= x2; i++)
		{
			map[y1 - i][i] = 'X';
		}
	}
}
