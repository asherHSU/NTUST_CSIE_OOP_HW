/***********************************************************************
 * File: Source.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-04-19
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-04-19
 * Description: reads a list of strings, finds the longest string that appears as a reverse substring in other strings
***********************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main() {
	vector<string> inputs;//store inputs and lengths of longest substrings
	vector<int> longest;
	string res;
	int resLongest = 0;

	while (true)// Read inputs until end of file
	{
		string input;
		cin >> input;

		if (cin.eof() || input == "") {
			break;
		}

		inputs.push_back(input);// Store input string
	}

	// Iterate through each input string
	for (size_t i = 0; i < inputs.size(); i++)
	{
		int tempLongest = 0;//store length of longest substring
		string tempReverse = inputs[i];
		reverse(tempReverse.begin(), tempReverse.end()); // Reverse the current input string

		for (size_t j = 0; j < inputs.size(); j++)// Iterate through each input string to find the longest substring
		{
			size_t found = tempReverse.find(inputs[j], 0);// Search for input[j] in the reversed string

			// If input[j] is found and its length is greater than the current longest substring length
			if (found != string::npos && inputs[j].length() > tempLongest) {
				tempLongest = inputs[j].length();// Update the longest substring length
			}
		}

		longest.push_back(tempLongest);// Store the length of the longest substring for the current input string
	}

	// Find the input string with the longest substring length
	for (size_t i = 0; i < inputs.size(); i++)
	{
		if (longest[i] > resLongest) {
			res = inputs[i];
			resLongest = longest[i];
		}
	}

	cout << res << "\n";
}
