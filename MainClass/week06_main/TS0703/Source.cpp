/***********************************************************************
 * File: Source.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-03-29
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-03-29
 * Description: Program to print numbers in seven-segment display style based on user input.
***********************************************************************/
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> input;  // Vector to store input digits

	while (true) //continuously read input until EOF
	{
		char getInput = getc(stdin); // Read a character from standard input

		if (getInput == EOF) { // Check if end-of-file is reached
			break;
		}

		if (isdigit(getInput)) { // Check if the input character is a digit
			input.push_back(getInput - '0'); // Convert the character to integer and add to input vector
		}

		if (getInput == '\n') { // Check if newline character is encountered
			for (size_t i = 0; i < 3; i++) // Loop for each row of the seven-segment display
			{
				for (size_t j = 0; j < input.size(); j++) // Loop for each digit
				{
					switch (i)
					{
					case 0: // Top row
						switch (input[j]) //for each digit
						{
						case 1:
							cout << "   ";
							break;
						case 4:
							cout << "   ";
							break;
						default:
							cout << " _ ";
							break;
						}
						break;

					case 1: // Middle row
						switch (input[j]) //for each digit
						{
						case 1:
							cout << "  |";
							break;

						case 2:
						case 3:
							cout << " _|";
							break;

						case 7:
							cout << "  |";
							break;

						case 5:
						case 6:
							cout << "|_ ";
							break;

						case 4:
						case 8:
						case 9:
							cout << "|_|";
							break;

						case 0:
							cout << "| |";
							break;
						default:
							break;
						}
						break;

					case 2: // Bottom row
						switch (input[j]) //for each digit
						{
						case 1:
							cout << "  |";
							break;
						case 2:
							cout << "|_ ";
							break;
						case 3:
						case 5:
						case 9:
							cout << " _|";
							break;
						case 6:
						case 8:
						case 0:
							cout << "|_|";
							break;
						case 4:
						case 7:
							cout << "  |";
							break;
						}
						break;
					}
				}
				cout << "\n";
			}
			input.clear(); // Clear the input vector
		}
	}
}
