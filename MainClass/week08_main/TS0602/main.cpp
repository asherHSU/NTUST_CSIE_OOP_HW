/***********************************************************************
 * File: main.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-04-15
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-04-15
 * Description: Demonstrates the usage of PrimeNumber class for finding prime numbers.
***********************************************************************/
#include "PrimeNumber.h"
#include <iostream>

using namespace std;

int main()
{	
	PrimeNumber p1, p2(13);	// Declare two PrimeNumber objects: p1 and p2
	PrimeNumber a = ++p1; // Increment p1 using pre-increment operator and assign the result to a
	PrimeNumber b = p2++; // Increment p2 using post-increment operator and assign the result to b
	cout << a.get() << endl; // Output the value of a
	cout << p1.get() << endl; // Output the value of p1
	cout << b.get() << endl; // Output the value of b
	cout << p2.get() << endl; // Output the value of p2
	return 0; // Indicate successful program execution
}
