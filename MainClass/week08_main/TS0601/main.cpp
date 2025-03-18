/***********************************************************************
 * File: main.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-04-15
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-04-15
 * Description: Demonstrates the usage of a Complex class for complex number operations.
***********************************************************************/
#include "Complex.h"
using namespace std;

int main()
{
	Complex x, y(3), z(-3.2, 2.1); // Creating complex number objects: x, y, and z
	cout << "x =  " << x << "y = " << y << "z = " << z << "\n";
	x = Complex(3, -4);// Assigning new values to x and y
	y = Complex(1, -1);
	cout << "x =  " << x << "\n";
	cout << "testing members and support functions as well as"
		<< " output operator:\n"
		<< "complex number x = " << x << endl
		<< "real part: " << x.real() << endl
		<< "real part from friend real(x): " << real(x) << endl
		<< "imaginary part: " << x.imag() << endl
		<< "imaginary part from friend imag(x) : " << imag(x) << endl
		<< "norm: " << norm(x) << endl << endl;
	if (x == y)  // Comparing x and y
		cout << "x = y" << endl << endl;
	else
		cout << "x!=y" << endl << endl;
	z = x + y;  // Performing arithmetic operations on x and y
	cout << "z = x + y = " << z << endl;
	z = x * y;
	cout << "z = x * y = " << z << endl;
	z = x - y;
	cout << "z = x - y = " << z << endl;
	z = x / y;
	cout << "z = x / y = " << z << endl << endl;

	double d(2.0); // Testing arithmetic operations between a Complex number and a double
	cout << "d: " << d << "   x: " << x << endl;
	cout << "x+d: ";
	z = x + d;
	cout << z << endl;
	z = x - d;
	cout << "x-d: ";
	cout << z << endl;
	z = x * d;
	cout << "x*d: ";
	cout << z << endl;
	z = x / d;
	cout << "x/d: ";
	cout << z << endl;

	z = d + x;  // Testing arithmetic operations between a double and a Complex number
	cout << "d+x: ";
	cout << z << endl;
	z = d - x;
	cout << "d-x: ";
	cout << z << endl;
	z = d * x;
	cout << "d*x: ";;
	cout << z << endl;
	z = d / x;
	cout << "d/x: ";;
	cout << z << endl;
	Complex two(2, 0); // Additional operation: 2 / x
	cout << "two/x: ";
	cout << two / x << endl;

	cout << "\nGetting data from standard input: \n"; // Reading complex numbers from standard input
	cin >> x >> y;
	cout << "data read is: x = " << x << " y = " << y << endl << endl;
	return 0;
}