/***********************************************************************
 * File: main.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-04-15
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-04-15
 * Description: Main program file for the NumberGame application.
***********************************************************************/
#include <iostream>
#include "NumberGame.h"
using namespace std;
int main() {

	// Instantiate a NumberGame object.
	NumberGame Game;

	// Set the input value to 1234.
	Game.SetInput(1234);

	// Process the input.
	Game.ProcessInput();

	// Set the filename for loading number list.
	Game.SetFileName("number.txt");

	// Load the number list from file.
	Game.LoadNumberList();

	// Print all valid numbers.
	Game.PrintAllValid();

	// Reset the game state.
	cout << "\n";
	Game.Reset();

	// Set the input value to 100.
	Game.SetInput(100);

	// Process the input.
	Game.ProcessInput();

	// Set the filename for loading number list.
	Game.SetFileName("number.txt");

	// Load the number list from file.
	Game.LoadNumberList();

	// Print all valid numbers.
	Game.PrintAllValid();
}