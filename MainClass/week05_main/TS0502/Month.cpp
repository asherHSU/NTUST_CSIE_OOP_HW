/***********************************************************************
 * File: Month.cpp
 * Author: ¶À®x½n (B11215054, 0978wally@gmail.com)
 * Create Date: 2024-03-21
 * Editor: ¶À®x½n (B11215054, 0978wally@gmail.com)
 * Update Date: 2024-03-21
 * Description: Implementation file for the Month class.
***********************************************************************/
#include "Month.h"
#include <iostream>
#include <string>
using namespace std;

Month::Month()
{
	this->month = 1; // Default constructor initializes month to January (1)
}

/* Intent: Constructs a Month object using abbreviation letters.
 * Pre: Takes three characters representing the abbreviation of a month.
 * Post: Initializes the month variable based on the abbreviation.
 */
Month::Month(char first, char second, char third)
{
	if (first == 'J' && second == 'a' && third == 'n') {
		this->month = 1;
	}
	else if (first == 'F' && second == 'e' && third == 'b') {
		this->month = 2;
	}
	else if (first == 'M' && second == 'a' && third == 'r') {
		this->month = 3;
	}
	else if (first == 'A' && second == 'p' && third == 'r') {
		this->month = 4;
	}
	else if (first == 'M' && second == 'a' && third == 'y') {
		this->month = 5;
	}
	else if (first == 'J' && second == 'u' && third == 'n') {
		this->month = 6;
	}
	else if (first == 'J' && second == 'u' && third == 'l') {
		this->month = 7;
	}
	else if (first == 'A' && second == 'u' && third == 'g') {
		this->month = 8;
	}
	else if (first == 'S' && second == 'e' && third == 'p') {
		this->month = 9;
	}
	else if (first == 'O' && second == 'c' && third == 't') {
		this->month = 10;
	}
	else if (first == 'N' && second == 'o' && third == 'v') {
		this->month = 11;
	}
	else if (first == 'D' && second == 'e' && third == 'c') {
		this->month = 12;
	}
	else {
		this->month = 1;
	}
}

/* Intent: Constructs a Month object using an integer.
 * Pre: Takes an integer value representing a month.
 * Post: Initializes the month variable based on the given integer.
 */
Month::Month(int monthInt)
{
	if (monthInt >= 1 && monthInt <= 12) {
		this->month = monthInt;
	}
	else {
		this->month = 1;
	}
}

/* Intent: Reads an integer input and sets the month value.
 * Pre: None.
 * Post: Modifies the month variable based on the input integer.
 */
void Month::inputInt()
{
	int month;
	cin >> month;

	if (month >= 1 && month <= 12) {
		this->month = month;
	}
	else {
		this->month = 1;
	}
}

/* Intent: Reads three characters input and sets the month value.
 * Pre: None.
 * Post: Modifies the month variable based on the input characters representing the abbreviation of a month.
 */
void Month::inputStr()
{
	char first = 'J', second = 'a', third = 'n';
	cin >> first >> second >> third;

	if (first == 'J' && second == 'a' && third == 'n') {
		this->month = 1;
	}
	else if (first == 'F' && second == 'e' && third == 'b') {
		this->month = 2;
	}
	else if (first == 'M' && second == 'a' && third == 'r') {
		this->month = 3;
	}
	else if (first == 'A' && second == 'p' && third == 'r') {
		this->month = 4;
	}
	else if (first == 'M' && second == 'a' && third == 'y') {
		this->month = 5;
	}
	else if (first == 'J' && second == 'u' && third == 'n') {
		this->month = 6;
	}
	else if (first == 'J' && second == 'u' && third == 'l') {
		this->month = 7;
	}
	else if (first == 'A' && second == 'u' && third == 'g') {
		this->month = 8;
	}
	else if (first == 'S' && second == 'e' && third == 'p') {
		this->month = 9;
	}
	else if (first == 'O' && second == 'c' && third == 't') {
		this->month = 10;
	}
	else if (first == 'N' && second == 'o' && third == 'v') {
		this->month = 11;
	}
	else if (first == 'D' && second == 'e' && third == 'c') {
		this->month = 12;
	}
	else {
		this->month = 1;
	}
}

/* Intent: Outputs the integer value of the month.
 * Pre: None.
 * Post: Prints the month value to the console.
 */
void Month::outputInt()
{
	cout << this->month;
}

/* Intent: Outputs the abbreviation of the month.
 * Pre: None.
 * Post: Prints the abbreviation of the month to the console.
 */
void Month::outputStr()
{
	switch (month)
	{
	case 1:
		cout << "Jan";
		break;
	case 2:
		cout << "Feb";
		break;
	case 3:
		cout << "Mar";
		break;
	case 4:
		cout << "Apr";
		break;
	case 5:
		cout << "May";
		break;
	case 6:
		cout << "Jun";
		break;
	case 7:
		cout << "Jul";
		break;
	case 8:
		cout << "Aug";
		break;
	case 9:
		cout << "Sep";
		break;
	case 10:
		cout << "Oct";
		break;
	case 11:
		cout << "Nov";
		break;
	case 12:
		cout << "Dec";
		break;
	default:
		break;
	}
}

/* Intent: Returns the next month.
 * Pre: None.
 * Post: Returns a Month object representing the next month.
 */
Month Month::nextMonth()
{
	int setMonth = this->month + 1;
	Month newMonth(setMonth);
	return newMonth;
}
