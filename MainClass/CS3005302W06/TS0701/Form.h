#include<string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class Form
{
private:
	string word;
	ifstream inputStream;
	vector<string> vaildWord;

public:
	// set input
	void SetInputWord(string inputWord) {
		this->word = inputWord;
	}

	// process input
	void ProcessInputWord() {
		for (size_t i = 0; i < word.length(); i++)
		{
			word[i] = tolower(word[i]);
		}
	}

	// set file name
	void SetFileName(string fileName) {
		inputStream.open(fileName);
	}

	// read-in data and compare
	void Load_CompareWord() {
		while (true)
		{
			bool isSame = true;
			string compareWord, tempWord;
			inputStream >> compareWord;
			tempWord = compareWord;

			if (inputStream.eof()) {
				break;
			}

			for (size_t i = 0; i < word.length(); i++)
			{
				for (size_t j = 0; j < tempWord.length(); j++)
				{
					if (word[i] == tempWord[j]) {
						tempWord[j] = -1;
						break;
					}
				}
			}

			for (size_t i = 0; i < tempWord.length(); i++)
			{
				if (tempWord[i] != -1) {
					isSame = false;
				}
			}

			if (isSame == true) {
				vaildWord.push_back(compareWord);
			}
		}
	}

	// print answers
	void PrintFoundWords() {
		for (size_t i = 0; i < vaildWord.size(); i++)
		{
			cout << vaildWord[i] << "\n";
		}
	}
};
