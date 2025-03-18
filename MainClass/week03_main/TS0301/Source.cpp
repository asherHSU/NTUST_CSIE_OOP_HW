/***********************************************************************
 * File: Source.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-03-06
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-03-06
 * Description: reads a list of numbers with an integer type 
 *				and counts how many times each number appears.
***********************************************************************/
#include <iostream>
#include <vector>
#include <algorithm> // For sorting
using namespace std;

int main() {
	vector<int> data; // Vector to store input numbers
	int input; // Variable to store each input number

	while (true) // Get input until end of file is reached
	{
		cin >> input;
		if (cin.eof()) break;
		data.push_back(input); // Store input number in vector
	}

	sort(data.begin(), data.end()); // Sort the input numbers in ascending order
	reverse(data.begin(), data.end()); // Reverse the sorted numbers to get descending order
	cout << "N\tcount\n"; // Print header for the table

	int appearTimes = 0, lastElement = data[0]; // Variables to keep track of appearance count and last element

	for (size_t i = 0; i < data.size(); i++)
	{
		if (data[i] == lastElement) appearTimes++; // Increment appearance count if number is the same as last one
		else { // If number is different
			cout << lastElement << "\t" << appearTimes << "\n";
			appearTimes = 1; // Reset appearance count for new number
		}
		lastElement = data[i]; // Update last element
	}

	cout << lastElement << "\t" << appearTimes << "\n";
}
