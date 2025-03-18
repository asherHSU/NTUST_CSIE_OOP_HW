/***********************************************************************
 * File: Source.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-02-29
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-02-29
 * Description: adding large number.(Ver2)
***********************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool checkNum(string strA, string strB); //Make sure the input number is valid
string add(string strA, string strB); //add two large number

int main() {
	int datas; //store number of data pairs
	cin >> datas;

	for (size_t i = 0; i < datas; i++)
	{
		string strA, strB, res; //store each data pairs and result
		cin >> strA;
		cin >> strB;

		if (checkNum(strA, strB)) { //if input number is valid, add input number
			res = add(strA, strB);
			reverse(res.begin(), res.end());
			cout << res << "\n";
		}
		else {
			cout << "Not a valid number, please try again.\n";
		}
	}
}

/* Intent: Make sure the input number is valid
 * Pre: two input string
 * Post: boolean, Is input number valid
 */
bool checkNum(string strA, string strB) {
	for (size_t i = 0; i < strA.length(); i++) //check every char in the string is digit
	{
		if (!isdigit(strA[i])) return false;
	}

	for (size_t i = 0; i < strB.length(); i++)
	{
		if (!isdigit(strB[i])) return false;
	}
	return true;
}

/* Intent: add two large number
 * Pre: two input string
 * Post: string result, sum of two large number
 */
string add(string strA, string strB) {
	string res;
	reverse(strA.begin(), strA.end());
	reverse(strB.begin(), strB.end());
	int a, b, carry = 0, sum;

	//add two char from lowest Number of digits
	for (size_t i = 0; i < max(strA.length(), strB.length()); i++)
	{
		a = 0;
		b = 0;
		sum = 0;

		//convert string input to intger
		if (i < strA.length()) a = strA[i] - '0';
		if (i < strB.length()) b = strB[i] - '0';

		sum = a + b + carry;
		if (sum >= 10) carry = 1;
		else carry = 0;

		res.append(to_string(sum % 10));
	}

	if (carry == 1) res.append("1"); //if Highest digit had carry, add "1" after Highest digit

	return res;
}