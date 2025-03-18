/***********************************************************************
 * File: Source.cpp
 * Author: ¶À®x½n(0978wally@gmail.com)
 * Create Date: 2024-03-14
 * Editor: ¶À®x½n(0978wally@gmail.com)
 * Update Date: 2024-03-14
 * Description: find the greatest common divisor (GCD) of two positive integers using a loop.
 * ***********************************************************************/
#include <iostream>
using namespace std;

int main() {
	int a, b;

	while (true)
	{
		cin >> a >> b; // Input two positive integers

		if (cin.eof()) { // Break loop if end of file is reached
			break;
		}

		// Loop to find the greatest common divisor
		for (size_t i = min(a, b); i >= 1; i--)
		{
			if (a % i == 0 && b % i == 0) { // If both numbers are divisible by the current iteration
				cout << i << "\n"; // Output the greatest common divisor
				break; // Break the loop after finding the greatest common divisor
			}
		}
	}
}
