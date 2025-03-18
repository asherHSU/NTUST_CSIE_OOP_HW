/***********************************************************************
 * File: main.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-04-15
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-04-15
 * Description:
***********************************************************************/
#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

class NumberGame
{
public:
	/*
	 * Intent: Constructor to initialize NumberGame object.
	 * Pre: None
	 * Post: Sets input to 0.
	 */
	NumberGame()
	{
		input = 0;
	}

	/*
	 * Intent: Set the input value for the game.
	 * Pre: integer repersent input value
	 * Post: Sets the input value.
	 */
	void SetInput(int input) {
		this->input = input;
	}

	/*
	 * Intent: Process the input value by splitting it into individual digits and calculating the maximum product of digits.
	 * Pre: None
	 * Post: Sets the inputIndex and maxProduct.
	 */
	void ProcessInput() {
		int temp = input;
		maxProduct = 1; //store max individual digits product

		while (temp > 0)// Split the input into individual digits
		{
			int element = temp % 10;

			if (element != 0) {
				inputIndex.push_back(element);
			}

			temp /= 10;
		}

		for (size_t i = 0; i < inputIndex.size(); i++)// Calculate the maximum product of digits
		{
			maxProduct *= inputIndex[i];
		}

		sort(inputIndex.begin(), inputIndex.end());// Sort the inputIndex vector in ascending order
		reverse(inputIndex.begin(), inputIndex.end());// Reverse the inputIndex vector to get digits in descending order
	}

	/*
	 * Intent: Set the filename from which to load the number list.
	 * Pre: file name
	 * Post: Sets the filename.
	 */
	void SetFileName(string fileName) {
		this->fileName = fileName;
	}

	/*
	 * Intent: Load the number list from the specified file and find valid numbers.
	 * Pre: None
	 * Post: Populates the valid numbers vector.
	 */
	void LoadNumberList() {
		ifstream inputStream;
		inputStream.open(fileName);

		while (true)
		{
			int tempInput;
			inputStream >> tempInput;

			if (inputStream.eof()) {// Check for end of file
				break;
			}

			if (tempInput > maxProduct) {// Break the loop if current number exceeds the maximum product of digits
				break;
			}

			// Skip if the number is 1 and the highest digit is not 1
			if (tempInput == 1 && inputIndex[inputIndex.size() - 1] != 1) {
				continue;
			}

			// Check if the number is valid based on the digits of input
			for (size_t i = 0; i < inputIndex.size(); i++)
			{
				int devideInput = tempInput;
				bool isVaild = false;

				for (size_t j = i; j < inputIndex.size(); j++)
				{
					if (devideInput % inputIndex[j] == 0) {
						devideInput /= inputIndex[j];
					}

					// If divideInput becomes 1, it means all digits of tempInput can be formed by input digits
					if (devideInput == 1) {
						vaildNumber.push_back(tempInput);
						isVaild = true;
						break;
					}
				}

				if (isVaild) {
					break;
				}
			}
		}
	}

	/*
	 * Intent: Print all the valid numbers found in the list.
	 * Pre: None
	 * Post: Prints all the valid numbers in ascending order.
	 */
	void PrintAllValid() {
		for (size_t i = 0; i < vaildNumber.size(); i++)
		{
			cout << vaildNumber[i] << "\n";
		}
	}

	/*
	 * Intent: Reset all the member variables of the class.
	 * Pre: None
	 * Post: Resets all member variables.
	 */
	void Reset() {
		fileName = "";
		inputIndex.clear();
		vaildNumber.clear();
		input = 0;
		maxProduct = 0;
	}

private:
	string fileName; // Filename for number list file
	vector<int> inputIndex; // Vector to store digits of input
	vector<int> vaildNumber; // Vector to store valid numbers
	int input; // Input value
	int maxProduct; // Maximum product of digits
};
