/***********************************************************************
 * File: Complex.h
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-04-15
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-04-15
 * Description: Header file for the Complex class representing complex numbers.
***********************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Complex
{
public:
	double realValue, imaginaryValue;

	/*
	 *  Intent: Default constructor to initialize a Complex object with zero real and imaginary parts.
	 *  Pre: None.
	 *  Post: Initializes a Complex object with zero real and imaginary parts.
	 */
	Complex() {
		realValue = 0;
		imaginaryValue = 0;
	}

	/*
	 *  Intent: Constructor to initialize a Complex object with a given real part and zero imaginary part.
	 *  Pre: 'r' is the real part of the complex number.
	 *  Post: Initializes a Complex object with the provided real part and zero imaginary part.
	 */
	Complex(double r) {
		realValue = r;
		imaginaryValue = 0;
	}

	/*
	 *  Intent: Constructor to initialize a Complex object with given real and imaginary parts.
	 *  Pre: 'r' is the real part and 'i' is the imaginary part of the complex number.
	 *  Post: Initializes a Complex object with the provided real and imaginary parts.
	 */
	Complex(double r, double i) {
		realValue = r;
		imaginaryValue = i;
	}

	/*
	*  Intent: Accessor method to get the real part of the complex number.
	*  Pre: None.
	*  Post: Returns the real part of the complex number.
	*/
	double real() {
		return realValue;
	}

	/*
	 *  Intent: Accessor method to get the imaginary part of the complex number.
	 *  Pre: None.
	 *  Post: Returns the imaginary part of the complex number.
	 */
	double imag() {
		return imaginaryValue;
	}

	/*
	 *  Intent: Calculate the norm (magnitude) of the complex number.
	 *  Pre: None.
	 *  Post: Returns the norm (magnitude) of the complex number.
	 */
	double norm() {
		return sqrt(pow(realValue, 2) + pow(imaginaryValue, 2));
	}

	/*
	 *  Intent: Friend function to access the real part of a Complex object.
	 *  Pre: 'c' is the Complex object.
	 *  Post: Returns the real part of the Complex object.
	 */
	friend double real(Complex c) {
		return c.realValue;
	}

	/*
	 *  Intent: Friend function to access the imaginary part of a Complex object.
	 *  Pre: 'c' is the Complex object.
	 *  Post: Returns the imaginary part of the Complex object.
	 */
	friend double imag(Complex c) {
		return c.imaginaryValue;
	}

	/*
	 *  Intent: Friend function to calculate the norm (magnitude) of a Complex object.
	 *  Pre: 'c' is the Complex object.
	 *  Post: Returns the norm (magnitude) of the Complex object.
	 */
	friend double norm(Complex c) {
		return sqrt(pow(c.realValue, 2) + pow(c.imaginaryValue, 2));
	}

	/*
	 *  Intent: Overloaded addition operator to add two Complex numbers.
	 *  Pre: 'c' is the Complex number to be added.
	 *  Post: Returns the sum of the two Complex numbers.
	 */
	Complex operator+(Complex c) {
		Complex result(realValue + c.realValue, imaginaryValue + c.imaginaryValue);
		return result;
	}

	/*
	 *  Intent: Overloaded subtraction operator to subtract one Complex number from another.
	 *  Pre: 'c' is the Complex number to be subtracted.
	 *  Post: Returns the result of subtracting the second Complex number from the first.
	 */
	Complex operator-(Complex c) {
		Complex result(realValue - c.realValue, imaginaryValue - c.imaginaryValue);
		return result;
	}

	/*
	 *  Intent: Overloaded multiplication operator to multiply two Complex numbers.
	 *  Pre: 'c' is the Complex number to be multiplied.
	 *  Post: Returns the product of the two Complex numbers.
	 */
	Complex operator*(Complex c) {
		Complex result;
		result.realValue = this->realValue * c.realValue - this->imaginaryValue * c.imaginaryValue;
		result.imaginaryValue = this->imaginaryValue * c.realValue + this->realValue * c.imaginaryValue;
		return result;
	}

	/*
	 *  Intent: Overloaded division operator to divide one Complex number by another.
	 *  Pre: 'c' is the Complex number to divide by.
	 *  Post: Returns the result of dividing the first Complex number by the second.
	 */
	Complex operator/(Complex c) {
		Complex result;
		result.realValue = (this->realValue * c.realValue + this->imaginaryValue * c.imaginaryValue) / (pow(c.realValue, 2) + pow(c.imaginaryValue, 2));
		result.imaginaryValue = (-1 * this->realValue * c.imaginaryValue + this->imaginaryValue * c.realValue) / (pow(c.realValue, 2) + pow(c.imaginaryValue, 2));
		return result;
	}

	/*
	 *  Intent: Overloaded addition operator to add a double to a Complex number.
	 *  Pre: 'd' is the double to be added.
	 *  Post: Returns the sum of the Complex number and the double.
	 */
	friend Complex operator+(double d, Complex c) {
		// Calculate the sum of the double and the real part of the Complex number
		Complex result(d + c.realValue, c.imaginaryValue);
		return result;
	}

	/*
	 *  Intent: Overloaded subtraction operator to subtract a Complex number from a double.
	 *  Pre: 'd' is the double to be subtracted from.
	 *  Post: Returns the result of subtracting the Complex number from the double.
	 */
	friend Complex operator-(double d, Complex c) {
		Complex result(d - c.realValue, c.imaginaryValue * -1);
		return result;
	}

	/*
	 *  Intent: Overloaded multiplication operator to multiply a double by a Complex number.
	 *  Pre: 'd' is the double to be multiplied.
	 *  Post: Returns the product of the double and the Complex number.
	 */
	friend Complex operator*(double d, Complex c) {
		Complex result(d * c.realValue, c.imaginaryValue * d);
		return result;
	}

	/*
	 *  Intent: Overloaded division operator to divide a double by a Complex number.
	 *  Pre: 'd' is the double to divide by.
	 *  Post: Returns the result of dividing the double by the Complex number.
	 */
	friend Complex operator/(double d, Complex c) {
		Complex result;
		// Perform division of the double by the Complex number
		result.realValue = (d * c.realValue) / (pow(c.realValue, 2) + pow(c.imaginaryValue, 2));
		result.imaginaryValue = (-1 * d * c.imaginaryValue) / (pow(c.realValue, 2) + pow(c.imaginaryValue, 2));
		return result;
	}

	/*
	 *  Intent: Overloaded equality operator to check if two Complex numbers are equal.
	 *  Pre: 'c1' and 'c2' are the Complex numbers to be compared.
	 *  Post: Returns true if the two Complex numbers are equal, otherwise returns false.
	 */
	friend bool operator==(Complex c1, Complex c2) {
		if (c1.realValue == c2.realValue && c1.imaginaryValue == c2.imaginaryValue) {
			return true;
		}

		return false;
	}

	/*
	 *  Intent: Overloaded stream insertion operator to output a Complex number.
	 *  Pre: 'strm' is the output stream, 'c' is the Complex number to be output.
	 *  Post: Outputs the real and imaginary parts of the Complex number.
	 */
	friend ostream& operator<<(ostream& strm, const Complex& c) {
		// Write the Complex number in the format: real + imaginary*i
		strm << c.realValue << " + " << c.imaginaryValue << "*i";
		return strm;
	}

	/*
	 *  Intent: Overloaded stream extraction operator to read a Complex number from input.
	 *  Pre: 'strm' is the input stream, 'c' is the Complex number to be read.
	 *  Post: Reads the real and imaginary parts of the Complex number from input.
	 */
	friend istream& operator>>(istream& strm, Complex& c) {
		vector<string> input(5);

		for (size_t i = 0; i < 5; i++)// Read input into vector of strings
		{
			strm >> input[i];
		}

		// Extract real and imaginary parts from input
		double real = strtod(input[2].c_str(), nullptr);
		input[4].erase(strchr(input[4].c_str(), '*') - input[4].c_str(), 10);
		double image = strtod(input[4].c_str(), nullptr);

		// Check if the imaginary part is negative
		if (input[3] == "-") {
			image *= -1;
		}

		// Assign extracted parts to the Complex number
		c.realValue = real;
		c.imaginaryValue = image;
		return strm;
	}
};
