/***********************************************************************
 * File: main.cpp
 * Author: ¶À®x½n (B11215054, 0978wally@gmail.com)
 * Create Date: 2024-03-21
 * Editor: ¶À®x½n (B11215054, 0978wally@gmail.com)
 * Update Date: 2024-03-21
 * Description:  Main function to test the Month class.
***********************************************************************/
#include <iostream>
#include "Month.h"// Including the header file for Month class
using namespace std;

int main(void)
{
	// Creating instances of Month class using different constructors
	Month month1, month2(2), month3('M','a','r'), month4, month5, month6;
	month4 = month3.nextMonth(); // Assigning the next month to month4 using nextMonth() method
	month5.inputInt(); // Reading input for month5 and month6
	month6.inputStr();

	cout << "Month1 = "; // Printing details of each month
	month1.outputInt();
	cout << ' ';
	month1.outputStr();
	cout << endl;

	cout << "Month2 = ";
	month2.outputInt();
	cout << ' ';
	month2.outputStr();
	cout << endl;

	cout << "Month3 = ";
	month3.outputInt();
	cout << ' ';
	month3.outputStr();
	cout << endl;

	cout << "Month4 = ";
	month4.outputInt();
	cout << ' ';
	month4.outputStr();
	cout << endl;

	cout << "Month5 = ";
	month5.outputInt();
	cout << ' ';
	month5.outputStr();
	cout << endl;

	cout << "Month6 = ";
	month6.outputInt();
	cout << ' ';
	month6.outputStr();
	cout << endl;
	return 0;
}