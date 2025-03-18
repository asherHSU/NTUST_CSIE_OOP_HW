/***********************************************************************
 * File: main.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-03-29
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-03-29
 * Description: Main function to demonstrate the usage of Atoi class for string to integer conversion.
***********************************************************************/
#include <iostream>
#include "Atoi.h"

int main() {
	string beTrans;

	while (cin >> beTrans) { // Continue taking input until no more input is provided
		Atoi atoi(beTrans + "20");  // Create an instance of Atoi class with modified input
		if (atoi.IsDigital()) { // Check if the modified input can be converted to an integer
			cout << atoi.Length() << endl; //print instance data
			cout << atoi.StringToInteger() << endl;
			cout << sizeof(atoi.StringToInteger()) << endl;
		}

		atoi.SetString(beTrans); // Reset Atoi instance with original input
		if (atoi.IsDigital()) {
			cout << atoi.Length() << endl; //print instance data
			cout << atoi.StringToInteger() << endl;
			cout << sizeof(atoi.StringToInteger()) << endl;
		}
	}

	return 0;
}