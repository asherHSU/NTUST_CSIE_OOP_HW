/***********************************************************************
 * File: Atoi.h
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-03-29
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-03-29
 * Description: Declaration of the Atoi class for string to integer conversion.
***********************************************************************/
#pragma once
#include <string>
using namespace std;

class Atoi {

private:
	string beTrans; // store the original string value

public:
	/*
	 *  Intent: Default constructor to initialize beTrans as an empty string.
	 *  Pre: None
	 *  Post: Initializes beTrans to an empty string.
	 */
	Atoi() {
		beTrans = "";
	}

	/*
	 *  Intent: Constructor to initialize beTrans with the given string.
	 *  Pre: string s
	 *  Post: Initializes beTrans with the given string s.
	 */
	Atoi(string s) {
		beTrans = s;
	}

	/*
	 *  Intent: Set the value of beTrans to the given string s.
	 *  Pre: string of sey value
	 *  Post: Updates the value of beTrans with the given string s.
	 */
	void SetString(string s) {
		beTrans = s;
	}

	/*
	 *  Intent: Retrieve the value of beTrans.
	 *  Pre: None
	 *  Post: Returns the value of beTrans.
	 */
	const string GetString() {
		return beTrans;
	}

	/*
	 *  Intent: Calculate the length of the string in beTrans.
	 *  Pre: None
	 *  Post: Returns the length of the string in beTrans.
	 */
	int Length() {
		if (beTrans[0] == '-') { // Check if the first character is '-'
			return beTrans.length() - 1; // Subtract 1 if it is to exclude the '-'
		}
		return beTrans.length(); // Return the length of the string
	}

	/*
	 *  Intent: Check if the string in beTrans contains only digits.
	 *  Pre: None
	 *  Post: Returns true if the string in beTrans can be transformed into an integer, otherwise returns false.
	 */
	bool IsDigital() {
		bool res = true; // Initialize the result flag

		for (size_t i = 0; i < beTrans.length(); i++)
		{
			if (beTrans[i] == '-') { // Skip if the character is '-'
				continue;
			}

			if (isdigit(beTrans[i]) == false) { // If the character is not a digit,set the result flag as false
				res = false;
				break;
			}
		}
		return res;
	}

	/*
	 *  Intent: Convert the string in beTrans to an integer.
	 *  Pre: The string in beTrans should represent a valid integer.
	 *  Post: Returns the integer value represented by the string in beTrans.
	 */
	int StringToInteger() {
		int res = 0; // Initialize the result as 0

		for (size_t i = 0; i < beTrans.length(); i++) // Loop through each character of beTrans
		{
			if (beTrans[i] == '-') { // Skip if the character is '-'
				continue;
			}

			res *= 10; // shift digits left
			res += beTrans[i] - '0'; // Add the digit to the result
		}

		if (beTrans[0] == '-') { // If the first character is '-', Make the result negative
			res *= -1;
		}
		return res;
	}

};