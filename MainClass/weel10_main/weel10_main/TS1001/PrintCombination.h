/***********************************************************************
 * File: PrintCombination.h
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-04-26
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-04-26
 * Description: Header file for the PrintCombination function.
***********************************************************************/
#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void dealCombination(int* arrayPtr, int arrSize, int choise, int startIndex, vector<int> res);
vector<string> output; //store output combinations
int gChoise; //store the choice size

/*
 * Intent: Prints all combinations of choosing 'choise' elements from 'arrSize' elements.
 * Pre: arrayPtr points to a valid array of integers with size arrSize.
 *      choise is less than or equal to arrSize.
 * Post: Output contains all combinations of choosing 'choise' elements from 'arrSize' elements.
 */
static void PrintCombination(int* arrayPtr, int arrSize, int choise) {
	vector<int> res; // Create a vector to store the current combination.
	gChoise = choise; // Store the choice size in the global variable.

	// Call the function to generate combinations starting from each element.
	for (size_t i = 0; i < arrSize; i++)
	{
		dealCombination(arrayPtr, arrSize, choise, i, res);
	}

	//print result
	for (size_t i = 0; i < output.size(); i++)
	{
		cout << output[i];

		if(i < output.size() - 1) {
			cout << "\n";
		}
	}
}

/*
 * Intent: Recursively generates combinations of choosing 'choise' elements from 'arrSize' elements.
 * Pre: arrayPtr points to a valid array of integers with size arrSize.
 *      choise is less than or equal to arrSize.
 * Post: Output contains all combinations of choosing 'choise' elements from 'arrSize' elements.
 */
void dealCombination(int* arrayPtr, int arrSize, int choise, int startIndex, vector<int> res) {
	if (startIndex >= arrSize) {//starting index is greater than or equal to the array size, return.
		return;
	}

	res.push_back(arrayPtr[startIndex]);// Add the current element to the combination.

	if (res.size() == choise) {// If the combination size equals the choice size, generate output
		string out;//store the combination.

		for (size_t i = 0; i < res.size(); i++)
		{
			out += std::to_string(res[i]);
			
			if (i < gChoise - 1) {
				out += ' ';
			}
		}

		output.push_back(out);
		return;
	}

	for (size_t i = 0; i < arrSize-1; i++)// Recursive step: loop through each remaining element.
	{
		dealCombination(arrayPtr, arrSize, choise, startIndex + i + 1, res);
	}
}
