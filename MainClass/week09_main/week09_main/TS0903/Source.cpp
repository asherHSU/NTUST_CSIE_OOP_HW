/***********************************************************************
 * File: Source.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-04-19
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-04-19
 * Description: checks whether one string can be transformed into another string based on a set of rules defined by pairs of characters.
***********************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//check if a character can be changed to another character
bool canChange(vector<pair<char, char>> pairs, char from, char to, vector<char> history);

int main() {
	while (true)
	{
		int m, n;
		vector<pair<char, char>> pairs;
		cin >> m >> n;

		if (m == 0 || n == 0) { //input size
			break;
		}

		// Input pairs of characters
		for (size_t i = 0; i < m; i++)
		{
			char left, right;
			cin >> left >> right;
			pairs.push_back(pair<char, char>(left, right));
		}

		//check word pair
		for (size_t i = 0; i < n; i++)
		{
			bool isMatch = true;
			string compareA, compareB;
			cin >> compareA >> compareB;

			// If the lengths of the strings are different
			if (compareA.length() != compareB.length()) {
				cout << "no\n";
				continue;
			}

			int j = 0;

			while (j < compareA.length())// Iterate through each character of the strings
			{
				vector<char> history;

				if (compareA[j] == compareB[j]) {// If the characters are the same, move to the next character
					j++;
				}
				else if (canChange(pairs, compareA[j], compareB[j], history)) {// If the characters can be transformed, move to the next character
					j++;
				}
				else {// If characters cannot be transformed, output "no"
					cout << "no\n";
					isMatch = false;
					break;
				}
			}

			if (isMatch) {// If all characters can be transformed, output "yes"
				cout << "yes\n";
			}
		}
	}
}

/*
 * Intent: To check if a character can be changed to another character based on the provided pairs
 * Pre: Pairs of characters and their transformations are provided
 * Post: Returns true if the character can be changed to another character, false otherwise
 */
bool canChange(vector<pair<char, char>> pairs, char from, char to, vector<char> history) {
	if (from == to) {// If characters are the same, they can be changed
		return true;
	}

	bool res = false;

	for (size_t i = 0; i < pairs.size(); i++)
	{
		// Check if the current pair matches the character and the character to be transformed is not in history
		if (pairs[i].first == from && find(history.begin(), history.end(), pairs[i].second) == history.end()) {
			history.push_back(from);
			res = canChange(pairs, pairs[i].second, to, history);// Recursively call canChange function to check for transformation
		}

		if (res == true) {// If transformation is possible, exit loop
			break;
		}
	}

	return res;
}
