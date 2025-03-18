/***********************************************************************
 * File: Source.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-03-06
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-03-06
 * Description: generate a text-based histogram of student grades read from a file.
***********************************************************************/
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
	ifstream inputStream("grade.txt"); // Input stream for reading grades from file
	ofstream outputStream("grades.Output"); // Output stream for writing histogram
	vector<int> data; // Vector to store student grades
	char input; // Variable to store each grade read from file

	if (inputStream.is_open() == false) cout << "false"; // Check if file is open

	while (true) // Read grades from file until end of file is reached
	{
		input = inputStream.get(); // Read grade from file
		if (inputStream.eof()) break;
		if (input >= '0' && input <= '5') data.push_back(input - '0'); // Store valid grades in vector
	}

	// Iterate through each possible score (0 to 5) to count occurrences
	for (size_t i = 0; i <= 5; i++)
	{
		// Write count of grades for current score along with score itself to output file
		outputStream << count(data.begin(), data.end(), i) << " grade(s) of " << i << "\n";
	}

	inputStream.close();
}
