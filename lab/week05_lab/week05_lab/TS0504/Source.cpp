/***********************************************************************
 * File: Source.cpp
 * Author: ¶À®x½n (B11215054, 0978wally@gmail.com)
 * Create Date: 2024-03-21
 * Editor: ¶À®x½n (B11215054, 0978wally@gmail.com)
 * Update Date: 2024-03-21
 * Description: checks if a given Sudoku puzzle is valid or not.
***********************************************************************/
#include <iostream>
#include <algorithm> //for sort function 
#include <vector>
using namespace std;

bool checkRowCol(int map[9][9]); //checking row and column constraints
bool checkSquareZone(int map[9][9]); //checking square zone constraints

int main() {
	int map[9][9] = { 0 }; // Initialize a 9x9 Sudoku grid
	int i = 0, j = 0; // Variables to keep track of row and column indices

	while (true) // Continuous reading of characters until end-of-file is reached
	{
		char input = getchar(); // Read a character from standard input

		if (input == EOF) { // Check if end-of-file is reached
			break;
		}

		if (isdigit(input)) { // Check if the input character is a digit
			map[i][j] = input - '0'; // Convert character to integer and store it in the Sudoku grid
			j++; // Move to the next column

			if (j == 9) { // Check if all columns in the current row are filled
				i++; // Move to the next row
				j = 0; // Reset the column index to 0
			}
		}

		if (i == 9) { // Check if all rows in the Sudoku grid are filled
			i = 0; // Reset the row index to 0
			j = 0; // Reset the column index to 0

			// Check if both row/column constraints and square zone constraints are vaild
			if (checkRowCol(map) == true && checkSquareZone(map) == true) {
				cout << "True\n";
			}
			else {
				cout << "False\n";
			}
		}
	}

}

/* Intent: Check if the row and column constraints of the Sudoku puzzle are vaild.
 * Pre: Sudoku puzzle represented by the 2D array map is initialized.
 * Post: Returns true if all rows and columns contain digits from 1 to 9 without repetition, otherwise returns false.
 */
bool checkRowCol(int map[9][9]) {
	for (size_t i = 0; i < 9; i++)
	{
		vector<int> tempArrRow(9), tempArrCol(9); // temporary arrays to store row and column elements

		for (size_t j = 0; j < 9; j++)
		{
			tempArrRow[j] = map[i][j]; // Copy row elements to tempArrRow
			tempArrCol[j] = map[j][i]; // Copy column elements to tempArrCol
		}

		sort(tempArrRow.begin(), tempArrRow.end()); // Sort row elements in ascending order
		sort(tempArrCol.begin(), tempArrCol.end()); // Sort column elements in ascending order

		 // Check if elements are in the range 1-9 and without repetition
		for (size_t j = 0; j < 9; j++)
		{
			if (tempArrCol[j] != j+1 || tempArrRow[j] != j+1) {
				return false;
			}
		}
	}
	return true; // If all constraints are satisfied, return true
}

/* Intent: Check if the square zone constraints of the Sudoku puzzle are vaild.
 * Pre: The Sudoku puzzle represented by the 2D array map is initialized.
 * Post: Returns true if all 3x3 subgrids contain digits from 1 to 9 without repetition, otherwise returns false.
 */
bool checkSquareZone(int map[9][9]) {
	vector<int> tempArr(9); // temporary array to store subgrid elements
	 
	for (size_t i = 0; i < 9; i += 3) // Iterate over the rows of the Sudoku grid with a step of 3
	{
		for (int j = 0; j < 9; j += 3) { // Iterate over the columns of the Sudoku grid with a step of 3

			for (size_t k = 0; k < 3; k++) // Iterate over the rows of the subgrid
			{
				for (size_t f = 0; f < 3; f++) // Iterate over the columns of the subgrid
				{
					tempArr[k * 3 + f] = map[i + k][j + f]; // Copy subgrid elements to tempArr
				}
			}

			sort(tempArr.begin(), tempArr.end()); // Sort subgrid elements in ascending order

			// Check if elements are in the range 1-9 and without repetition
			for (size_t g = 0; g < 9; g++)
			{
				if (tempArr[g] != g+1 || tempArr[g] != g+1) {
					return false;
				}
			}
		}
	}
	return true; // If all constraints are satisfied, return true
}
