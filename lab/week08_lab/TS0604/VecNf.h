/***********************************************************************
 * File: VecNf.h
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-04-15
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-04-15
 * Description: Header file for VecNf class, which represents a multidimensional vector and implements vector operations.
***********************************************************************/
#pragma once
#include <iostream>
#include <vector>
using namespace std;

class VecNf
{
public:
	vector<float> index;// Vector to store the elements

	/*
	 * Intent: Default constructor to create a one-dimensional zero vector.
	 * Pre: None
	 * Post: Constructs a vector with one element (0).
	 */
	VecNf()
	{
		index.push_back(0);
	}

	/*
	 * Intent: Constructor to create a vector using the first cnt elements from dest.
	 * Pre: dest is a valid float array with at least cnt elements.
	 * Post: Constructs a vector with cnt elements copied from dest.
	 */
	VecNf(float* dest, int cnt) {
		// Add the current element to the index vector of the VecNf object
		for (size_t i = 0; i < cnt; i++)
		{
			index.push_back(dest[i]);
		}
	}

	/*
	 * Intent: Copy constructor to create a new vector from an existing VecNf object.
	 * Pre: None
	 * Post: Constructs a new vector with elements copied from rhs.
	 */
	VecNf(const VecNf& rhs) {
		index = rhs.index;
	}

	/*
	 * Intent: Assignment operator to copy the contents of one vector to another.
	 * Pre: None
	 * Post: Copies the elements from v1 to the current vector.
	 */
	VecNf& operator=(const VecNf& v1) {
		cout << "ASSIGNMENT!!!\n";
		index = v1.index;// Copy the elements from v1 to the current vector
		return *this;// Return a reference to the current vector
	}

	/*
	 * Intent: Overloaded operator to access the value of a specific dimension in the vector.
	 * Pre: in is a valid index within the range of vector dimensions.
	 * Post: Returns a reference to the element at index 'in' in the vector.
	 */
	float& operator[](int in) {
		return this->index[in];// Return a reference to the element at index 'in' in the vector
	}

	/*
	 * Intent: Overloaded operator to perform vector addition.
	 * Pre: Both vectors v1 and v2 must have the same dimensions.
	 * Post: Returns a new vector containing the element-wise sum of v1 and v2.
	 */
	friend VecNf operator+( VecNf& v1,  VecNf& v2) {
		VecNf res;

		if (v1.index.size() != v2.index.size()) {// Check if the dimensions of the vectors are inconsistent
			cout << "dimensions inconsistent\n";
			return res;
		}
		
		res.index.resize(v1.index.size());// Resize the index vector of the result VecNf object to match the size of v1

		for (size_t i = 0; i < v1.index.size(); i++) // Calculate the element - wise sum and store the result in the corresponding index of the result vector
		{
			res.index[i] = v1.index[i] + v2.index[i];
		}

		return res;
	}

	/*
	 * Intent: Overloaded operator to perform vector subtraction.
	 * Pre: Both vectors v1 and v2 must have the same dimensions.
	 * Post: Returns a new vector containing the element-wise difference of v1 and v2.
	 */
	friend VecNf operator-(VecNf& v1, VecNf& v2) {
		VecNf res;

		if (v1.index.size() != v2.index.size()) {// Check if the dimensions of the vectors are inconsistent
			cout << "dimensions inconsistent\n";
			return res;
		}

		
		res.index.resize(v1.index.size());// Resize the index vector of the result VecNf object to match the size of v1

		for (size_t i = 0; i < v1.index.size(); i++)// Calculate the element-wise difference and store the result in the corresponding index of the result vector
		{
			res.index[i] = v1.index[i] - v2.index[i];
		}

		return res;
	}

	/*
	 * Intent: Overloaded operator to perform inner product of two vectors.
	 * Pre: Both vectors v1 and v2 must have the same dimensions.
	 * Post: Returns the inner product of v1 and v2.
	 */
	friend float operator*(VecNf& v1, VecNf& v2) {
		if (v1.index.size() != v2.index.size()) {// Check if the dimensions of the vectors are inconsistent
			cout << "dimensions inconsistent\n";
			return 0;
		}

		int res = 0;// Initialize the result variable to store the inner product

		for (size_t i = 0; i < v1.index.size(); i++)// Calculate the inner product by multiplying corresponding elements and adding them to the result
		{
			res += v1[i] * v2[i];
		}

		return res;
	}

	/*
	 * Intent: Overloaded operator to perform scalar multiplication of a vector with an integer.
	 * Pre: int scalar and from vector 
	 * Post: Returns a new vector containing the elements of v1 multiplied by the scalar s.
	 */
	friend VecNf operator*(VecNf& v1, int s) {
		VecNf res;
		res.index.resize(v1.index.size());// Resize the index vector of the result VecNf object to match the size of v1

		for (size_t i = 0; i < v1.index.size(); i++)// Loop through each element of v1
		{
			res.index[i] += v1[i] * s;// Multiply each element of v1 by the scalar s and store the result in the corresponding index of the result vector
		}

		return res;
	}

	/*
	 * Intent: Overloaded operator to perform scalar multiplication of a vector with an integer.
	 * Pre: int scalar and from vector 
	 * Post: Returns a new vector containing the elements of v1 multiplied by the scalar s.
	 */
	friend VecNf operator*(int s, VecNf& v1) {
		VecNf res;
		res.index.resize(v1.index.size());// Resize the index vector of the result VecNf object to match the size of v1

		for (size_t i = 0; i < v1.index.size(); i++)// Loop through each element of v1
		{
			res.index[i] += v1[i] * s;// Multiply each element of v1 by the scalar s and store the result in the corresponding index of the result vector
		}

		return res;
	}

	/*
	 * Intent: Get the size of the vector.
	 * Pre: None
	 * Post: Returns the number of elements in the vector.
	 */
	int Size() {
		return index.size();
	}
};

