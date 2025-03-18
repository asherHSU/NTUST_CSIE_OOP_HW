/***********************************************************************
 * File: Template.h
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-05-15
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-05-15
 * Description: calculates and returns the absolute value of the difference between two numeric values
***********************************************************************/
#pragma once
#include <math.h>

/*
 *  Intent: Calculate the absolute value of the difference between two characters.
 *  Pre: Takes two character values as input.
 *  Post: Returns the absolute value of the difference between the two characters.
 */
int absoluteValue(char num1, char num2) {
	int res = num1 - num2; // Calculate the difference between num1 and num2.
	return abs(res);// Return the absolute value of the difference.
}

/*
 *  Intent: Calculate the absolute value of the difference between two values of the same type.
 *  Pre: Takes two values of type T as input.
 *  Post: Returns the absolute value of the difference between the two values.
 */
template<class T>
T absoluteValue(T num1, T num2) {
	return fabsl(num1 - num2); // Calculate the difference between num1 and num2 and return its absolute value.
}