/***********************************************************************
 * File: main.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-04-08
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-04-08
 * Description: Main function to demonstrate the usage of the Polynomial class.
***********************************************************************/
#include <iostream>
#include <string>
#include "Polynomial.h"
using namespace std;

int main()
{
	// Define different polynomials for testing.
	Polynomial empty; // Polynomial with default constructor.
	double one[] = { 1 }; // Polynomial with a single coefficient.
	Polynomial One(one, 1);
	double quad[] = { 3, 2, 1 };
	double cubic[] = { 1, 2, 0, 3 };
	Polynomial q(quad, 3); // q is 3 + 2*x + x*x
	Polynomial c(cubic, 4); // c is 1 + 2*x + 0*x*x + 3*x*x*x
	Polynomial p = q;  // Test copy constructor.
	Polynomial r;
	r = q;             // Test operator=
	r = c;

	// Display coefficients of polynomial q.
	cout << "Polynomial q " << endl;
	for (int i = 0; i < 3; i++)
		cout << "term with degree " << i << " has coefficient " << q[i] << endl;

	// Display coefficients of polynomial c.
	cout << "Polynomial c " << endl;
	for (int i = 0; i < 4; i++)
		cout << "term with degree " << i << " has coefficient " << c[i] << endl;

	// Evaluate polynomials at a certain value.
	cout << "value of q(2) is " << evaluate(q, 2) << endl;
	cout << "value of p(2) is " << evaluate(p, 2) << endl;
	cout << "value of r(2) is " << evaluate(r, 2) << endl;
	cout << "value of c(2) is " << evaluate(c, 2) << endl;

	// Perform arithmetic operations on polynomials.
	r = q + c;
	cout << "value of (q + c)(2) is " << evaluate(r, 2) << endl;

	r = q - c;
	cout << "value of (q - c)(2) is " << evaluate(r, 2) << endl;

	r = q * c;
	cout << "size of q*c is " << r.mySize() << endl;
	cout << "Polynomial r (= q*c) " << endl;

	// Display coefficients of polynomial r.
	for (int i = 0; i < r.mySize(); i++)
		cout << "term with degree " << i << " has coefficient " << r[i] << endl;

	// Evaluate polynomial r at a certain value.
	cout << "value of (q * c)(2) is " << evaluate(r, 2) << endl;
	return 0;
}