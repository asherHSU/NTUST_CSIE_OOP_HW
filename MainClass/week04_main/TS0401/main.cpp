/***********************************************************************
 * File: main.cpp
 * Author: ¶À®x½n(0978wally@gmail.com)
 * Create Date: 2024-03-14
 * Editor: ¶À®x½n(0978wally@gmail.com)
 * Update Date: 2024-03-14
 * Description: Main program demonstrating the usage of Point class.
 * ***********************************************************************/
#include <iostream>
#include "Point.h"
using namespace std;

int main(void) {
	Point point; // Creating a Point object

	point.Set(0, 5);    // Setting initial position and outputting coordinates
	cout << point.RetrieveVertical() << " " << point.RetrieveHorizontal() << endl;

	point.Move(1, 2);  // Moving point and outputting coordinates
	cout << point.RetrieveVertical() << " " << point.RetrieveHorizontal() << endl;

	// Rotating point and outputting coordinates
	for (int i = 0; i < 4; i++) {
		point.Rotate();
		cout << point.RetrieveVertical() << " " << point.RetrieveHorizontal() << endl;
	}

	return 0;
}