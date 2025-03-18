/***********************************************************************
 * File: Source.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-03-08
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-03-08
 * Description: This C++ program calculates the maximum positive integer N,
 *				such that N! is within the CPU calculation range of the given year. 
 *              The CPU's capacity increases every 10 years by a multiple of 2. 
***********************************************************************/
#include <iostream>
using namespace std;

int main() {
	long double maxVal = 0, resVal = 0, LOG_10_BASE_2 = log10l(2); // Variables for CPU capacity and calculation
	int years, bitsPower, res = 1; // store year, CPU bit size, and result

	while (true)
	{
		maxVal = 0; // Initialize maxVal
		resVal = 0; // Initialize resVal
		res = 1;    // Initialize result
		
		cin >> years; // Read input year
		if (cin.eof()) break;// Check for EOF
		bitsPower = pow(2, 2 + (years - 1900) / 10); // Calculate CPU bit size for the given year
		
		for (int i = 0; i < bitsPower; i++) { // Calculate maximum value CPU can process
			maxVal += LOG_10_BASE_2;
		}
		
		while (resVal <= maxVal) // Calculate maximum N such that N! is within CPU capacity
		{
			res++;
			resVal += log10l(res);
		}
		
		res--;
		cout << res << "\n";
	}
}
