/***********************************************************************
 * File: Source.cpp
 * Author: 黃庭緯 (0978wally@gmail.com)
 * Create Date: 2024-04-26
 * Editor: 黃庭緯 (0978wally@gmail.com)
 * Update Date: 2024-04-26
 * Description: Main source file for a word search game.
***********************************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

bool findVaildWord(vector<string> wordMap, string word, int x, int y, int index);

int main() {
	ifstream inputStream("words.txt");// Open the input file 
	vector<string> wordMap(4); //store the word map grid.
	vector<string> words, res; //store words and valid results.

	while (true) //read file input
	{
		string input;
		inputStream >> input;

		if (inputStream.eof()) {
			break;
		}

		words.push_back(input);
	}

	while (true) //processing word maps
	{
		for (size_t i = 0; i < 4; i++) //get input map
		{
			string input;
			cin >> input;
			wordMap[i] = input;
		}

		if (cin.eof()) {
			break;
		}

		for (size_t i = 0; i < words.size(); i++)// Loop through each word to search for in the word map
		{
			bool isVaild = false; //store is word vaild

			for (size_t j = 0; j < 4; j++) //find start position
			{
				for (size_t k = 0; k < 4; k++)
				{
					if (wordMap[j][k] == words[i][0] && find(res.begin(), res.end(), words[i]) == res.end()) {// Check if the first character of the word matches the current cell.
						isVaild = findVaildWord(wordMap, words[i], k, j, 0);

						if (isVaild) {//if vaild in map, Add the valid word to the results
							res.push_back(words[i]);
						}
					}
				}

				if (isVaild) {
					break;
				}
			}
		}

		for (size_t j = 0; j < res.size(); j++) //output
		{
			cout << res[j] << "\n";
		}

		cout << "\n";
	}

	inputStream.close();
}

/*
 *  Intent: Recursive function to find a valid occurrence of the word in the word map.
 *  Pre: wordMap is a valid 4x4 grid of characters.
 *      word is a valid word to search for.
 *      x and y are within the bounds of the word map.
 *      index is a valid index for the current character in the word.
 *  Post: Returns true if a valid occurrence of the word is found, false otherwise.
 */
bool findVaildWord(vector<string> wordMap, string word, int x, int y, int index) {
	if (index >= word.length()) { // index exceeds the length of the word, return true.
		return true;
	}

	if (x < 0 || x >= 4 || y < 0 || y >= 4) {//coordinates are out of bounds, return false.
		return false;
	}

	if (word[index] != wordMap[y][x] || wordMap[y][x] == -1) { //current character doesn't match or has already been used, return false.
		return false;
	}

	wordMap[y][x] = -1;// Mark the current cell as visited.

	// Recursive calls to search for the next character in all possible directions
	if (findVaildWord(wordMap, word, x + 1, y, index + 1) ||
		findVaildWord(wordMap, word, x, y + 1, index + 1) ||
		findVaildWord(wordMap, word, x - 1, y, index + 1) ||
		findVaildWord(wordMap, word, x, y - 1, index + 1) ||
		findVaildWord(wordMap, word, x + 1, y + 1, index + 1) ||
		findVaildWord(wordMap, word, x - 1, y - 1, index + 1) ||
		findVaildWord(wordMap, word, x + 1, y - 1, index + 1) ||
		findVaildWord(wordMap, word, x - 1, y + 1, index + 1)) {
		return true;// If any of the recursive calls return true
	}

	return false;
}
