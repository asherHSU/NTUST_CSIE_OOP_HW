/***********************************************************************
 * File: main.cpp
 * Author: ¶À®x½n(0978wally@gmail.com)
 * Create Date: 2024-03-14
 * Editor: ¶À®x½n(0978wally@gmail.com)
 * Update Date: 2024-03-14
 * Description: Main program demonstrating the usage of Fraction class.
 * ***********************************************************************/
#include <iostream>
#include "Fraction.h"
using namespace std;

int main()
{
	Fraction f1, f2; // Creating Fraction objects
	f1.setNumerator(4); // Setting numerator and denominator for f1, calculating and outputting
	f1.setDenominator(2);
	f1.getDouble();
	f1.outputReducedFraction();

	f2.setNumerator(20);  // Setting numerator and denominator for f2, calculating and outputting
	f2.setDenominator(60);
	f2.getDouble();
	f2.outputReducedFraction();

	f1.setNumerator(4); // Setting numerator and denominator for f1 again, recalculating and outputting
	f1.setDenominator(2);
	f1.getDouble();
	f1.outputReducedFraction();
	
	return 0;
}