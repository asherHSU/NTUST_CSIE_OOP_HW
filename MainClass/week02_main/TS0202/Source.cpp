/***********************************************************************
 * File: Source.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-02-29
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-02-29
 * Description: Given an input file ¡§scores.txt¡¨ ,
 *				compute the names and scores of top three players.
***********************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
ifstream inputStream;

void getHighScores(vector<int> score, vector<string> name);
int main() {
	vector<int> score; //array store all player score
	vector<string> name; //array store all player name
	string inputName; //store current read plyer name
	int inputScore; //store current read plyer score
	inputStream.open("scores.txt");

	while (!inputStream.eof()) //get all player score and name in the file
	{
		inputStream >> inputName;
		inputStream >> inputScore;
		name.push_back(inputName);
		score.push_back(inputScore);
	}
	getHighScores(score, name);
	inputStream.close();
}

/* Intent: sort array by score , from max to min, and print top three player
 * Pre: an array of strings store player name, and an array of integers store player score
 * Post: none
 */
void getHighScores(vector<int> score, vector<string> name) {
	for (size_t i = 0; i < score.size(); i++) //bubble sort array by score
	{
		for (size_t j = i + 1; j < score.size(); j++)
		{
			if (score[i] < score[j]) {
				int temp = score[i];
				string temp2 = name[i];
				score[i] = score[j];
				name[i] = name[j];
				score[j] = temp;
				name[j] = temp2;
			}
		}
	}

	for (size_t i = 0; i < 3; i++) //print top three player
	{
		std::cout << name[i] << "\n" << score[i] << "\n";
	}
}