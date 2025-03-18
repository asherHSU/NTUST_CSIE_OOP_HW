/***********************************************************************
 * File: Fraction.cpp
 * Author: ¶À®x½n(0978wally@gmail.com)
 * Create Date: 2024-03-14
 * Editor: ¶À®x½n(0978wally@gmail.com)
 * Update Date: 2024-03-14
 * Description: Implementation of the Fraction class methods.
 * ***********************************************************************/
#include "Fraction.h"
using namespace std;

/* Intent: Find the greatest common divisor of two integers.
 * Pre: Two integers a and b.
 * Post:  Returns the greatest common divisor of a and b.
 */
int gcd(int a, int b)
{
	if (a == 0) { //if a is 0, return b
		return b;
	}

	return gcd(b % a, a); // Recursive call with b and remainder of a divided by b
}

/* Intent: Set the numerator of the fraction.
 * Pre: Integer value nu.
 * Post: Sets the numerator of the fraction object to nu.
 */
void Fraction::setNumerator(int nu)
{
	this->numerator = nu;
}

/* Intent: Set the denominator of the fraction.
 * Pre: Integer value de.
 * Post: Sets the denominator of the fraction object to de.
 */
void Fraction::setDenominator(int de)
{
	this->denominator = de;
}

/* Intent: Calculate the decimal value of the fraction and output it.
 * Pre: None.
 * Post: Outputs the decimal value of the fraction.
 */
void Fraction::getDouble()
{
	double res = (double)this->numerator / this->denominator;

	if (fmodl(res, 1) == 0) { // Checking if the result is an integer
		cout.precision(0);
		cout << res << "\n";
	}
	else {
		cout.setf(ios::fixed);
		cout.precision(6);
		cout << res << "\n";
	}

}

/* Intent: Output the fraction in reduced form.
 * Pre: None.
 * Post: Outputs the fraction in reduced form.
 */
void Fraction::outputReducedFraction()
{
	int getGcd = gcd(this->numerator, this->denominator); // Finding the greatest common divisor of numerator and denominator

	// Outputting the reduced fraction
	if (this->denominator / getGcd == 1) {
		cout << this->numerator / getGcd << "\n";
	}
	else
	{
		cout << this->numerator / getGcd << "/" << this->denominator / getGcd << "\n";
	}
}
