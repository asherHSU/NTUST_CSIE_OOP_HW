/***********************************************************************
 * File: Source.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-04-01
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-04-01
 * Description: hypothesis calculation regarding cow calculations.
***********************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string aOpreate(string num1, string nmu2); //addition operation
string rOpreate(string num1); //right shift operation
string lOpreate(string num1); // left shift operation
int getSymbols(char input); // get numeric value from character symbol
string toSymbols(int input); // get character symbol from numeric value

int main() {
	int step = 0; // Variable to store number of steps
	cin >> step;
	cout << "COWCULATIONS OUTPUT\n";

	for (size_t i = 0; i < step; i++) // Loop over each step
	{
		char operations[3] = { 0 }; // Array to store operations
		string num1, num2, checkAns; // Strings to store numbers and answer
		cin >> num1 >> num2;
		cin >> operations[0] >> operations[1] >> operations[2];
		cin >> checkAns;

		for (size_t j = 0; j < 3; j++) // Loop over each operation
		{
			switch (operations[j]) {
			case 'A':
				num2 = aOpreate(num1, num2);
				break;
			case 'R':
				num2 = rOpreate(num2);
				break;
			case 'L':
				num2 = lOpreate(num2);
				break;
			case 'N':
				break;
			}
		}

		for (size_t i = num2.length(); i < 8; i++) // Fill num2 with 'V' to reach 8 characters
		{
			num2.insert(0, "V");
		}
		
		if (num2 == checkAns) { // Check if num2 matches the expected answer
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	cout << "END OF OUTPUT";
}

/*
 *  Intent: Perform addition operation on two numbers represented in a 4-carry format
 *  Pre: Two numbers represented as strings
 *  Post: Returns the result of addition operation as a string
 */
string aOpreate(string num1, string num2) {
	string strRes; // String to store result
	int carry = 0; // Variable to store carry
	reverse(num1.begin(), num1.end()); // Reverse string (compute 4-carry add)
	reverse(num2.begin(), num2.end());

	for (size_t i = 0; i < max(num1.length(),num2.length()); i++) // Loop over each digit
	{
		int a, b;

		if (num1.length() > i) { // Check if num1 still has digits
			a = getSymbols(num1[i]); // Get numeric value of digit
		}
		else {
			a = 0; // If no more digits, set value to 0
		}

		if (num2.length() > i) { // Check if num2 still has digits
			b = getSymbols(num2[i]); // Get numeric value of digit
		}
		else {
			b = 0; // If no more digits, set value to 0
		}

		int sum = a + b + carry; // Calculate sum of digits and carry
		int res = sum % 4;
		carry = sum / 4;
		strRes += toSymbols(res); // Convert result to character symbol and append to result string
	}

	if (carry != 0) { // If carry is not zero
		strRes += "U"; // Append 'U' to indicate carry
	}

	reverse(strRes.begin(), strRes.end());
	return strRes;
}

/*
 *  Intent: Perform right shift operation on a string number
 *  Pre: Number represented as a string
 *  Post: Returns the result of right shift operation as a string
 */
string rOpreate(string num1) {
	num1.erase(num1.length() - 1,1); // Remove the last digit
	num1.insert(0, "V"); // Insert 'V' at the beginnin
	return num1;
}

/*
 *  Intent: Perform left shift operation on a string number
 *  Pre: Number represented as a string
 *  Post: Returns the result of left shift operation as a string
 */
string lOpreate(string num1) {
	num1 += "V"; // Append 'V' at the end
	return num1;
}

/*
 *  Intent: Get numeric value corresponding to a character symbol
 *  Pre: Character symbol representing a number
 *  Post: Returns the numeric value of the symbol
 */
int getSymbols(char input) {
	switch (input) {
	case 'V':
		return 0;
		break;
	case 'U':
		return 1;
		break;
	case 'C':
		return 2;
		break;
	case 'D':
		return 3;
		break;
	}

	return -1;
}

/*
 *  Intent: Get character symbol corresponding to a numeric value
 *  Pre: Numeric value representing a symbol
 *  Post: Returns the character symbol corresponding to the value
 */
string toSymbols(int input) {
	switch (input) {
	case 0:
		return "V";
		break;
	case 1:
		return "U";
		break;
	case 2:
		return "C";
		break;
	case 3:
		return "D";
		break;
	}

	return ""; // Return empty string for invalid input
}