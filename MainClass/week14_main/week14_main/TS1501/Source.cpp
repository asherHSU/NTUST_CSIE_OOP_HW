/***********************************************************************
 * File: Source.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-05-23
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-05-23
 * Description: reads names from a file called "name.txt" and stores 
 *   them in a set to ensure all names are unique
***********************************************************************/
#include <iostream>
#include <set>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream inputSream("name.txt"); // Open the input file stream to read from "name.txt"
	set<string> name; // Set to store unique names

	while (true)// Read names from the file line by line
	{
		string tempName;
		getline(inputSream, tempName);

		if (inputSream.eof()) {
			break;
		}

		auto findName = name.find(tempName);

		if (findName == name.end()) { // Check if the name is already in the set
			name.insert(tempName);
		}
	}

	for (auto i:name)// Output all unique names
	{
		cout << i << "\n";
	}

	inputSream.close();
}
