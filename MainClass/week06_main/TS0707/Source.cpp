/***********************************************************************
 * File: Source.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-03-29
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-03-29
 * Description: compute large numbers represented as strings.
***********************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string strSum(string a, string b, bool maskCarry); //addition of two large numbers
string diff(string a, string b); //subtraction of two large numbers
string product(string a, string b); //multiplication of two large numbers
string cancelZero(string input); //remove leading zeros from a string
string complement(string input); //calculate the complement of a number

int main() {
	string a, b; //store input numbers

	while (true) //read input until EOF
	{
		cin >> a >> b; // Read two input numbers

		if (cin.eof()) { // Check if end-of-file is reached
			break;
		}

		string sumRes = strSum(a, b, false); // Calculate the sum
		string diffRes = diff(a, b); // Calculate the difference 
		string productRes = product(a, b); // Calculate the product

		// Remove leading zeros
		sumRes = cancelZero(sumRes); 
		diffRes = cancelZero(diffRes); 
		productRes = cancelZero(productRes); 
		
		// Output the result
		cout << sumRes << "\n";
		cout << diffRes << "\n";
		cout << productRes << "\n";
	}
}

/*
 *  Intent: addition of two large numbers represented as strings.
 *  Pre: Two strings representing non-negative integers, bool to set complement mode.
 *  Post: Returns the sum of the two numbers as a string.
 */
string strSum(string strA, string strB, bool isInverse) {
	string strRes; // Result string
	vector<int> result; //store result digits

	// Reverse the input string (low->high when compute)
	reverse(strA.begin(), strA.end());
	reverse(strB.begin(), strB.end());

	int sum = 0, carry = 0, res = 0, a = 0, b = 0; //digit compute value

	for (size_t i = 0; i < max(strA.length(), strB.length()); i++) // Loop through each digit
	{
		if (i < strA.length()) { 
			a = strA[i] - '0'; // Convert character to integer
		}
		else {
			a = 0; // Set to 0 if out of range
		}

		if (i < strB.length()) {
			b = strB[i] - '0'; // Convert character to integer
		}
		else if (isInverse == true) {
			b = 9; // Set to 9 if out of range and performing subtraction
		}
		else {
			b = 0; // Set to 0 if out of range
		}

		sum = a + b + carry; //sum of digits
		carry = sum / 10; // Calculate carry
		res = sum % 10; // Calculate result digit
		result.push_back(res); // Store result digit
	}

	if (carry == 1 && isInverse == false) {  // Check if has a final carry
		result.push_back(1); // Add the carry
	}

	reverse(result.begin(), result.end()); // Reverse the result digits(high->low)

	for (size_t i = 0; i < result.size(); i++) // Convert result digits to string
	{
		strRes += result[i] + '0';
	}

	if (carry == 0 && isInverse == true && strRes != "0") { // Check if result is negative after subtraction
		strRes = cancelZero(strRes); // Remove leading zeros
		strRes = complement(strRes); // Calculate complement
		strRes.insert(0, "-"); // Insert negative sign
	}
	return strRes;
}

/*
 *  Intent: Perform subtraction of two large numbers represented as strings.
 *  Pre: Two strings representing non-negative integers.
 *  Post: Returns the difference of the two numbers as a string.
 */
string diff(string strA, string strB) {
	if(strB == "0") { // Check if second number is zero
		return strA; // Return first number as difference
	}

	strB = complement(strB); // Calculate complement of second number
	return strSum(strA, strB, true); //addition with complemented second number
}

/*
 *  Intent: Perform multiplication of two large numbers represented as strings.
 *  Pre: Two strings representing non-negative integers.
 *  Post: Returns the product of the two numbers as a string.
 */
string product(string strA, string strB) {
	vector<string> rowRes; // Vector to store each row compute results
	string res; // Final result

	if (strA.length() < strB.length()) { // Ensure strA is longer or equal to strB, otherwise swap
		string temp = strA;
		strA = strB;
		strB = temp;
	}

	// Reverse the input string(low->high when compute)
	reverse(strA.begin(), strA.end());
	reverse(strB.begin(), strB.end());

	/*
		99
	X	99
	-------
	   891	<- row result
	+891'0' (append 0) 	
	-------
	  9801	
	*/
	for (size_t i = 0; i < min(strA.length(), strB.length()); i++) // Loop through each digit of strB
	{
		string tempStrRes; // Temporary result for each row
		int carry = 0; // Carry for multiplication

		for (size_t j = 0; j < max(strA.length(), strB.length()); j++) // Loop through each digit of strA
		{
			int a, b, sum;
			a = strA[j] - '0'; // Convert character to integer
			b = strB[i] - '0';
			sum = (a * b + carry); // Calculate product and add carry
			tempStrRes += sum % 10 + '0'; // Append result digit character to temporary result
			carry = sum / 10; // Update carry
		}

		if (carry != 0) { // Check if has a final carry
			tempStrRes += carry + '0'; // Append carry
		}

		reverse(tempStrRes.begin(), tempStrRes.end()); // Reverse the temporary result

		for (size_t j = 0; j < i; j++) // Append trailing zeros based on row position
		{
			tempStrRes += '0';
		}

		rowRes.push_back(tempStrRes); // Store the row result in the vector
	}

	for (int i = 0; i < rowRes.size(); i++) // Iterate over each row result
	{
		res = strSum(res, rowRes[i], false); // Accumulate row results
	}

	return res;
}

/*
 *  Intent: Remove leading zeros from a string.
 *  Pre: A result string
 *  Post: Returns the string with leading zeros removed.
 */
string cancelZero(string input) {
	string res; // Result string
	size_t i; //string index position

	for (i = 0; i < input.length()-1; i++) // Find the index of the first non-zero digit
	{
		if (input[i] == '0') {
			continue;
		}
		else {
			break;
		}
	}

	for (; i < input.length(); i++) // Append non-zero digits to result string
	{
		res += input[i];
	}
	return res;
}

/*
 *  Intent: Calculate the complement of a number.
 *  Pre: A string representing a non-negative integer.
 *  Post: Returns the complement of the input number as a string.
 */
string complement(string input) {
	if (input == "0") { // Check if input is zero, return orgin input (avoid -0)
		return "0";
	}

	for (size_t i = 0; i < input.length(); i++) // Iterate over each digit of the input number
	{
		int temp = input[i] - '0'; // Convert character to integer
		temp = abs(9 - temp); // Calculate 9's complement of the digit
		input[i] = temp + '0'; // Convert complement back to character

	}

	input = strSum(input, "1", false); // Add 1 to the complement to get the final result
	return input;
}

