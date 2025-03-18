/***********************************************************************
 * File: Source.cpp
 * Author: ¶À®x½n(0978wally@gmail.com)
 * Create Date: 2024-03-14
 * Editor: ¶À®x½n(0978wally@gmail.com)
 * Update Date: 2024-03-14
 * Description: calculates the Collatz sequence length
 *              for a given range of integers.
 * ***********************************************************************/
#include <iostream>
using namespace std;

int collatz(int input, int times); //Calculates the length of the Collatz sequence

int main() {
	int length, in1, in2; //store input and result

	while (true)
	{
		length = 0; //reset result
		cin >> in1 >> in2;

		if (cin.eof()) { // Check for end-of-file (EOF) input
			break;
		}

		// Iterate through the range of integers and calculate the 
		// length of the Collatz sequence for each integer
		for (size_t i = min(in1, in2); i <= max(in1, in2); i++)
		{
			int nowCollatz = collatz(i, 0);

			if (nowCollatz > length) length = nowCollatz; // Update the maximum Collatz sequence length
		}

		// Output the input integers and the length of the longest 
		// Collatz sequence within the given range
		cout << in1 << " " << in2 << " " << length + 1 << "\n";
	}
	return 0;
}

/* Intent: Calculates the length of the Collatz sequence for a given input integer.
 * Pre: integer input, times
 * Post: Returns the length of the Collatz sequence.
 */
int collatz(int input, int times) {
	if (input == 1) { //if input becomes 1, return the number of steps
		return times;
	}

	if (input % 2 == 0) { //if N is an even number, n/2
		return collatz(input / 2, times + 1);
	}
	else //if N is an odd number, N*3+1
	{ 
		return collatz(input * 3 + 1, times + 1);
	}

	return times; // Return the final number of steps
}
