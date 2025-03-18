/***********************************************************************
 * File: ComputeSQRT.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-02-22
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-02-22
 * Description: Use Babylonian algorithm to compute the square root (Ver2)
***********************************************************************/

#include <iostream>
using namespace std;

int main() {
	double input, r = 0, guess = 0, beforeGuess = 0;

	while ((cin >> input) || !cin.eof()) // read until no data
	{
		guess = input / 2;
		while (abs(beforeGuess - guess) > 0.01) // check if guess subtract the previous guess smaller than 0.01
		{
			beforeGuess = guess;
			r = input / guess;
			guess = (guess + r) / 2;
		}

		cout.setf(ios::fixed);
		cout.precision(2);
		cout << guess << "\n";
	}
}