/***********************************************************************
 * File: Polynomial.h
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-04-08
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-04-08
 * Description: Definition of a Polynomial class for mathematical operations.
***********************************************************************/
#pragma once
#include <vector>
using namespace std;

class Polynomial
{
public:
	/*
	 *  Intent: Default constructor for Polynomial class.
	 *  Pre: None.
	 *  Post: Initializes a Polynomial object with one coefficient, 0.
	 */
	Polynomial()
	{
		this->coefficients.push_back(0);
	}

	/*
	 *  Intent: Constructor for Polynomial class that initializes with given coefficients.
	 *  Pre: Pointer to an array of coefficients, and the size of the array.
	 *  Post: Initializes a Polynomial object with coefficients provided in the array.
	 */
	Polynomial(double* coefficients, int size) {
		for (size_t i = 0; i < size; i++)
		{
			this->coefficients.push_back(coefficients[i]); //set coefficients
		}
	}

	/*
	 *  Intent: Copy constructor for Polynomial class.
	 *  Pre: Another Polynomial object.
	 *  Post: Initializes a Polynomial object with the same coefficients as the input Polynomial.
	 */
	Polynomial(const Polynomial& poly) {
		this->coefficients = poly.coefficients; //set coefficients
	}

	/*
	 *  Intent: Get the degree of the polynomial.
	 *  Pre: None.
	 *  Post: Returns the degree of the polynomial (highest power of the variable).
	 */
	int mySize() {
		int size = 0, i;

		for (i = coefficients.size() - 1; i >= 0; i--) //pass first 0 coefficients
		{
			if (coefficients[i] == 0) {
				continue;
			}
			else {
				break;
			}
		}

		for (; i >= 0; i--) //count real size
		{
			size++;
		}

		return size;
	}

	/*
	 *  Intent: Evaluate the polynomial for a given value of the variable.
	 *  Pre: Another Polynomial object and a double variable for evaluation.
	 *  Post: Returns the result of polynomial evaluation for the given variable value.
	 */
	friend double evaluate(const Polynomial& poly, const double& var) {
		double res = 0; //result
		vector<double> tempCoefficients = poly.coefficients; //get count coefficients

		for (size_t i = 0; i < tempCoefficients.size(); i++)
		{
			res += pow(var, i) * tempCoefficients[i]; //count result
		}

		return res;
	}

	/*
	 *  Intent: Overloaded [] operator for accessing coefficients by index.
	 *  Pre: An integer index.
	 *  Post: Returns a reference to the coefficient at the specified index.
	 *        If the index exceeds the size of coefficients, expands the coefficients vector.
	 */
	double& operator[](int index) {
		if (index >= coefficients.size()) { //If the index exceeds, expands the coefficients vector
			coefficients.resize(index + 1, 0);
		}

		return coefficients[index]; //return coefficients index
	}

	/*
	 *  Intent: Overloaded + operator for adding two polynomials.
	 *  Pre: Two Polynomial objects.
	 *  Post: Returns a new Polynomial object which is the sum of the two input Polynomials.
	 */
	friend Polynomial operator+(const Polynomial& poly1, const Polynomial& poly2) {
		// Declare vector to store the resulting coefficients,  hold coefficients of both polynomials.
		vector<double> res, vecA = poly1.coefficients, vecB = poly2.coefficients;

		// Iterate through coefficients of both polynomials up to the maximum degree.
		for (size_t i = 0; i < max(vecA.size(), vecB.size()); i++)
		{
			double a = 0, b = 0;

			// If index is within bounds of polynomial A, assign its coefficient.
			if (i < vecA.size()) {
				a = vecA[i];
			}

			// If index is within bounds of polynomial B, assign its coefficient
			if (i < vecB.size()) {
				b = vecB[i];
			}

			res.push_back(a + b); // Add coefficients
		}

		Polynomial result; // Assign the resulting coefficients to the result Polynomial.
		result.coefficients = res;
		return result;
	}

	/*
	 *  Intent: Overloaded + operator for adding a constant value to a polynomial.
	 *  Pre: A Polynomial object and a double constant.
	 *  Post: Returns a new Polynomial object which is the sum of the input Polynomial and the constant.
	 */
	friend Polynomial operator+(const Polynomial& poly1, const double input) {
		vector<double> res = poly1.coefficients; // Create a copy of the coefficients of the input polynomial.
		res[0] += input; //add input to lowest degree
		Polynomial result; // Assign the resulting coefficients to the result Polynomial and return.
		result.coefficients = res;
		return result;
	}

	/*
	 *  Intent: Overloaded + operator for adding a constant value to a polynomial.
	 *  Pre: A Polynomial object and a double constant.
	 *  Post: Returns a new Polynomial object which is the sum of the input Polynomial and the constant.
	 */
	friend Polynomial operator+(const double input, const Polynomial& poly1) {
		vector<double> res = poly1.coefficients; // Create a copy of the coefficients of the input polynomial.
		res[0] += input;//add input to lowest degree
		Polynomial result; // Assign the resulting coefficients to the result Polynomial and return.
		result.coefficients = res;
		return result;
	}

	/*
	 *  Intent: Overloaded - operator for subtracting two polynomials.
	 *  Pre: Two Polynomial objects.
	 *  Post: Returns a new Polynomial object which is the difference of the two input Polynomials.
	 */
	friend Polynomial operator-(const Polynomial& poly1, const Polynomial& poly2) {
		// Declare vector to store the resulting coefficients,  hold coefficients of both polynomials.
		vector<double> res, vecA = poly1.coefficients, vecB = poly2.coefficients;

		// Iterate through coefficients of both polynomials up to the maximum degree.
		for (size_t i = 0; i < max(vecA.size(), vecB.size()); i++)
		{
			double a = 0, b = 0;

			// If index is within bounds of polynomial A, assign its coefficient.
			if (i < vecA.size()) {
				a = vecA[i];
			}

			// If index is within bounds of polynomial B, assign its coefficient
			if (i < vecB.size()) {
				b = vecB[i];
			}

			res.push_back(a - b); // reduce coefficients
		}

		Polynomial result;
		result.coefficients = res;
		return result;
	}

	/*
	 *  Intent: Overloaded - operator for subtracting a constant value from a polynomial.
	 *  Pre: A Polynomial object and a double constant.
	 *  Post: Returns a new Polynomial object which is the difference of the input Polynomial and the constant.
	 */
	friend Polynomial operator-(const Polynomial& poly1, const double input) {
		vector<double> res = poly1.coefficients; // Create a copy of the coefficients of the input polynomial.
		res[0] -= input; //resuce input to lowest degree
		Polynomial result; // Assign the resulting coefficients to the result Polynomial and return.
		result.coefficients = res;
		return result;
	}

	/*
	 *  Intent: Overloaded - operator for subtracting a constant value from a polynomial.
	 *  Pre: A Polynomial object and a double constant.
	 *  Post: Returns a new Polynomial object which is the difference of the input Polynomial and the constant.
	 */
	friend Polynomial operator-(const double input, const Polynomial& poly1) {
		vector<double> res = poly1.coefficients; // Create a copy of the coefficients of the input polynomial.
		 // Negate each coefficient of the polynomial.
		for (size_t i = 0; i < res.size(); i++)
		{
			res[i] *= -1;
		}

		res[0] += input; // Add the constant value to the constant term of the polynomial.
		Polynomial result; // Assign the resulting coefficients to the result Polynomial and return.
		result.coefficients = res;
		return result;
	}

	/*
	*  Intent: Overloaded * operator for multiplying two polynomials.
	*  Pre: Two Polynomial objects.
	*  Post: Returns a new Polynomial object which is the product of the two input Polynomials.
	*/
	friend Polynomial operator*(const Polynomial& poly1, const Polynomial& poly2) {
		vector<double> vecA = poly1.coefficients, vecB = poly2.coefficients; // Retrieve coefficients of both polynomials.
		vector<double> res(vecA.size() + vecB.size()); //result vector

		for (size_t i = 0; i < vecA.size(); i++)
		{
			for (size_t j = 0; j < vecB.size(); j++)
			{
				double a = vecA[i], b = vecB[j]; // Multiply corresponding coefficients and accumulate into the result vector.
				res[i + j] += a * b;
			}
		}

		Polynomial result; // Create a new Polynomial object to hold the result and return.
		result.coefficients = res;
		return result;
	}

	/*
	 *  Intent: Overloaded * operator for multiplying a constant value by a polynomial.
	 *  Pre: A double constant and a Polynomial object.
	 *  Post: Returns a new Polynomial object which is the product of the input constant and the Polynomial.
	 */
	friend Polynomial operator*(const Polynomial& poly1, double input) {
		vector<double> res = poly1.coefficients; // Create a copy of the coefficients of the input polynomial.
		// Multiply each coefficient of the polynomial by the constant value.
		for (size_t i = 0; i < res.size(); i++)
		{
			res[i] *= input;
		}

		Polynomial result; // Create a new Polynomial object to hold the result, and return.
		result.coefficients = res;
		return result;
	}

	/*
	 *  Intent: Overloaded * operator for multiplying a constant value by a polynomial.
	 *  Pre: A double constant and a Polynomial object.
	 *  Post: Returns a new Polynomial object which is the product of the input constant and the Polynomial.
	 */
	friend Polynomial operator*(double input, const Polynomial& poly1) {
		vector<double> res = poly1.coefficients; // Create a copy of the coefficients of the input polynomial.
		// Multiply each coefficient of the polynomial by the constant value.
		for (size_t i = 0; i < res.size(); i++)
		{
			res[i] *= input;
		}

		Polynomial result; // Create a new Polynomial object to hold the result, and return.
		result.coefficients = res;
		return result;
	}

	/*
	 *  Intent: Overloaded assignment operator for assigning one Polynomial to another.
	 *  Pre: Another Polynomial object.
	 *  Post: Assigns the coefficients of the input Polynomial to this Polynomial.
	 */
	Polynomial& operator=(const Polynomial& poly1) {
		coefficients = poly1.coefficients; // Assign the coefficients of the input Polynomial to this Polynomial.
		return *this; // Return a reference to this Polynomial object.
	}

	/*
	 *  Intent: Overloaded [] operator for accessing coefficients by index in a const context.
	 *  Pre: An integer index.
	 *  Post: Returns a const reference to the coefficient at the specified index.
	 */
	const double& operator[](int index) const {
		return this->coefficients[index]; // Return a const reference to the coefficient at the specified index.
	}

	vector<double> coefficients; // Vector to store coefficients of the polynomial.
};


