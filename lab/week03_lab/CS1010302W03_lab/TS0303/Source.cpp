/***********************************************************************
 * File: Source.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-03-08
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-03-08
 * Description: given number X(double), integer M, N, and character C
 *				- X: The target number that needs to be formatted.
 *				- M: The total length of the output (including negative sign and decimal point).
 * 				- N: Number of reserved digits for the decimal part.
 *				- C: Character to fill when the length is not enough (less than M digits).
***********************************************************************/
#include <iostream>
using namespace std;

int main() {
	long double x;
	int strWidth; // Total length of the output
	int decimalNum; // Number of reserved digits for the decimal part
	char fillChar;     // Character to fill when the length is less than M digits

	while (true)
	{
		cin >> x; // Read input values for X, M, N, and C
		cin >> strWidth;
		cin >> decimalNum;
		cin >> fillChar;
		if (cin.eof()) break; // Check for EOF

		// Format the output
		cout.setf(ios::fixed, ios::floatfield); // Set fixed-point notation
		cout.width(strWidth); // Set the width for output
		cout.fill(fillChar); // Set the fill character
		cout.precision(decimalNum); // Set precision for decimal digits
		x *= pow(10, decimalNum); // Move decimal point to desired position
		x = trunc(x) / pow(10, decimalNum); // Truncate excess decimal digits
		cout << (long double)x << "\n"; // Output the formatted number
	}
}
