/***********************************************************************
 * File: Form.h
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-03-29
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-03-29
 * Description: Implementation of a word game class.
***********************************************************************/
#include<string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class Form
{
private:
	string word; // Given word for the game
	ifstream inputStream; // Input file stream to read valid words
	vector<string> vaildWord; // Vector to store all valid words found

public:
	/*
	 *  Intent: Set the given word of the game.
	 *  Pre: string of input word
	 *  Post: Updates the word member variable with inputWord.
	 */
	void SetInputWord(string inputWord) {
		this->word = inputWord;
	}

	/*
	 *  Intent: Pre-process the given word (e.g., transition to lowercase).
	 *  Pre: None
	 *  Post: Modifies the word to lowercase.
	 */
	void ProcessInputWord() {
		for (size_t i = 0; i < word.length(); i++)
		{
			word[i] = tolower(word[i]);
		}
	}

	/*
	 *  Intent: Set the file name of the file that contains all the valid words.
	 *  Pre: string of filename
	 *  Post: Opens the input file stream with the specified fileName.
	 */
	void SetFileName(string fileName) {
		inputStream.open(fileName);
	}

	/*
	 *  Intent: Load the valid words from the file, 
	 *          and find out all the valid words composed by the letters in the given word.
	 *  Pre: The input file stream is open and valid.
	 *  Post: inseert found words to the validWord vector.
	 */
	void Load_CompareWord() {
		while (true)
		{
			bool isSame = true; // Flag indicating whether the word can be formed using given letters
			string compareWord, tempWord; // Strings to hold the word being compared and a temporary copy
			inputStream >> compareWord; // Read a word from the input stream
			tempWord = compareWord; // Copy the word for comparison

			if (inputStream.eof()) { // Check for end-of-file condition
				break;
			}

			// Iterate through each character of the given word
			for (size_t i = 0; i < word.length(); i++)
			{
				// Iterate through each character of the current word being compared
				for (size_t j = 0; j < tempWord.length(); j++)
				{
					if (word[i] == tempWord[j]) { // If a matching character is found, mark it to -1
						tempWord[j] = -1;
						break; // Exit the inner loop after marking
					}
				}
			}

			// Check if any characters in the temporary word were not matched (index != -1)
			for (size_t i = 0; i < tempWord.length(); i++)
			{
				if (tempWord[i] != -1) { // If an unmatched character is found, set the flag to false
					isSame = false;
				}
			}

			if (isSame == true) { // If all characters of the compared word are used, add it to the list of valid words
				vaildWord.push_back(compareWord);
			}
		}
	}

	/*
	 *  Intent: Print the words found in the function Load_CompareWord().
	 *  Pre: None
	 *  Post: Prints the valid words found.
	 */
	void PrintFoundWords() {
		for (size_t i = 0; i < vaildWord.size(); i++)
		{
			cout << vaildWord[i] << "\n";
		}
	}
};
