/***********************************************************************
 * File: Month.h
 * Author: ¶À®x½n (B11215054, 0978wally@gmail.com)
 * Create Date: 2024-03-21
 * Editor: ¶À®x½n (B11215054, 0978wally@gmail.com)
 * Update Date: 2024-03-21
 * Description: Header file for the Month class.
***********************************************************************/
#pragma once
#include <string>
using namespace std;

class Month
{
public:
	Month(); // Default constructor initializes the month to January
	Month(char first, char second, char third); // Constructor initializes the month based on the abbreviation letters provided
	Month(int monthInt);  // Constructor initializes the month based on the integer value provide

	void inputInt();  // Reads an integer input and sets the month value
	void inputStr(); // Reads three characters input and sets the month value
	void outputInt(); // Outputs the integer value of the month
	void outputStr(); // Outputs the abbreviation of the month
	Month nextMonth(); // Returns the next month

private:
	int month; // Represents the month as an integer (1 to 12)
};

