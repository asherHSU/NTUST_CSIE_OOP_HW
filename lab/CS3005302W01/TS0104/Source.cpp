/***********************************************************************
 * File: Source.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-02-22
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-02-22
 * Description: Given an arbitrary integer INPUT, If the number of characters in INPUT
 * (including the negative sign) is less than 10 digits, fill in the space at the beginning. (Ver2)
***********************************************************************/

#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;

int main() {
	string input;

	while (true)
	{
		cin >> input;

		if (cin.eof()) break;

		// if digits<10, set output align right and max width = 10, 
		// else go back to origin output state
		if (input.length() < 10) { 
			cout.setf(ios::right);
			cout.width(10);
		}else {
			cout.setf(ios::left);
			cout.width(input.length());
		}

		cout << input << "\n";
		input.clear();
	}
}