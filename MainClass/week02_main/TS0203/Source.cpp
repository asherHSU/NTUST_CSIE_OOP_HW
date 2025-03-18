/***********************************************************************
 * File: Source.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-02-29
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-02-29
 * Description: input messages of each line are English characters, 
 *				put the characters into a n*n square.(Ver2)
***********************************************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printLine(string data); //print a line into a n*n square

int main() {
	vector<string> data; //store each line to string element
	string input; //current line

	while (1) //read each line to data array
	{
		if (cin.eof()) break;
		cin >> input;
		data.push_back(input);
	}

	for (size_t i = 0; i < data.size() - 1; i++) //print eqach line into a n*n square
	{
		printLine(data[i]);
		cout << "\n";
	}
}

/* Intent: print a line into a n*n square
 * Pre: one line of string
 * Post: none
 */
void printLine(string data) {
	unsigned long long int strlen = data.length();
	//compute square width by find nearest integer of square root of string length
	unsigned long long int colLen = lroundf(sqrt(strlen)); 
	unsigned long long int rowLen = ceil((double)strlen / colLen); //compute square height 

	//i: begin offset of data index
	//cursor: current print index
	for (size_t i = 0; i < rowLen; i++)
	{
		for (size_t j = 0, cursor = i; j < colLen; j++)
		{
			if (cursor >= strlen) continue;
			cout << data[cursor];
			cursor += std::max((int)rowLen, (int)colLen); //offset of next element
		}

		if (i < rowLen - 1) cout << "\n";
	}
}

