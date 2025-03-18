/***********************************************************************
 * File: Fraction.h
 * Author: ¶À®x½n(0978wally@gmail.com)
 * Create Date: 2024-03-14
 * Editor: ¶À®x½n(0978wally@gmail.com)
 * Update Date: 2024-03-14
 * Description: Declaration of the Fraction class.
 * ***********************************************************************/
#ifndef Fraction_H
#define Fraction_H

#include <iostream>
#include <iomanip>
using namespace std;

class Fraction
{
private:
	int numerator;
	int denominator;
public:
	void setNumerator(int nu); // Method to set numerator
	void setDenominator(int de); // Method to set denominator
	void getDouble(); // Method to get the decimal value of the fraction
	void outputReducedFraction(); // Method to output the fraction in reduced form
};

#endif //Fraction_H