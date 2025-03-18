/***********************************************************************
 * File: main.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-04-15
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-04-15
 * Description:a class named PrimeNumber that stores a prime number.
***********************************************************************/
#pragma once

class PrimeNumber {
public:
	int value;

	/*
	 *  Intent: Constructor to initialize a PrimeNumber object with a value of 1.
	 *  Pre: None.
	 *  Post: Initializes the PrimeNumber object with a value of 1.
	 */
	PrimeNumber() {
		value = 1;
	}

	/*
	 *  Intent: Constructor to initialize a PrimeNumber object with a specified value.
	 *  Pre: '_value' is the value to be assigned to the PrimeNumber object.
	 *  Post: Initializes the PrimeNumber object with the specified value.
	 */
	PrimeNumber(int _value) {
		value = _value;
	}

	/*
	 *  Intent: Getter function to retrieve the value of the PrimeNumber.
	 *  Pre: None.
	 *  Post: Returns the current value of the PrimeNumber.
	 */
	int get() {
		return value;
	}

	/*
	 *  Intent: Overloaded pre-increment operator to find the next prime number after the current value.
	 *  Pre: None.
	 *  Post: Finds the next prime number after the current value and updates the value of the PrimeNumber object accordingly.
	 */
	PrimeNumber& operator++() {
		int res = value;

		// Loop to find the next prime number
		while (true)
		{
			bool isPrime = true;
			res++;

			// Check if 'res' is a prime number
			for (size_t i = 2; i < res; i++)
			{
				if (res % i == 0) {
					isPrime = false;
					break;
				}
			}

			// If 'res' is a prime number, break the loop
			if (isPrime == true) {
				break;
			}
		}

		this->value = res; // Update the value of the PrimeNumber object
		PrimeNumber result(res);// Create a PrimeNumber object with the previous value
		return result;
	}

	/*
	*  Intent: Overloaded post-increment operator to find the next prime number after the current value.
	*  Pre: None.
	*  Post: Finds the next prime number after the current value and updates the value of the PrimeNumber object accordingly.
	*/
	PrimeNumber operator++(int){
		int res = value, beforeResult = value;

		// Loop to find the next prime number
		while (true)
		{
			bool isPrime = true;
			res++;

			// Check if 'res' is a prime number
			for (size_t i = 2; i < res; i++)
			{
				if (res % i == 0) {
					isPrime = false;
					break;
				}
			}

			// If 'res' is a prime number, break the loop
			if (isPrime == true) {
				break;
			}
		}

		this->value = res; // Update the value of the PrimeNumber object
		PrimeNumber result(beforeResult);// Create a PrimeNumber object with the previous value
		return result;
	}

	/*
	 *  Intent: Overloaded pre-decrement operator to find the previous prime number before the current value.
	 *  Pre: None.
	 *  Post: Finds the previous prime number before the current value and updates the value of the PrimeNumber object accordingly.
	 */
	PrimeNumber& operator--() {
		int res = value;

		// Loop to find the previous prime number
		while (true)
		{
			bool isPrime = true;
			res--;

			// Check if 'res' is a prime number
			for (size_t i = 2; i < res; i++)
			{
				if (res % i == 0) {
					isPrime = false;
					break;
				}
			}

			// If 'res' is a prime number, break the loop
			if (isPrime == true) {
				break;
			}
		}

		this->value = res;// Update the value of the PrimeNumber object
		PrimeNumber result(res);// Create a PrimeNumber object with the previous value
		return result;
	}

	/*
	 *  Intent: Overloaded post-decrement operator to find the previous prime number before the current value.
	 *  Pre: None.
	 *  Post: Finds the previous prime number before the current value and updates the value of the PrimeNumber object accordingly.
	 */
	PrimeNumber operator--(int) {
		int res = value, beforeResult = value;

		while (true)// Loop to find the previous prime number
		{
			bool isPrime = true;
			res--;

			// Check if 'res' is a prime number
			for (size_t i = 2; i < res; i++)
			{
				if (res % i == 0) {
					isPrime = false;
					break;
				}
			}

			// If 'res' is a prime number, break the loop
			if (isPrime == true) {
				break;
			}
		}

		this->value = res; // Update the value of the PrimeNumber object
		PrimeNumber result(beforeResult);// Create a PrimeNumber object with the previous value
		return result;
	}
};