/***********************************************************************
 * File: Point.h
 * Author: ¶À®x½n(0978wally@gmail.com)
 * Create Date: 2024-03-14
 * Editor: ¶À®x½n(0978wally@gmail.com)
 * Update Date: 2024-03-14
 * Description: Declaration of the Point class.
 * ***********************************************************************/
#ifndef Point_H
#define Point_H

#include <iostream>
using namespace std;

class Point
{
private:
	int vertical;
	int horizontal;

public:
	Point() // Constructor to initialize coordinates to (0, 0)
	{
		vertical = 0;
		horizontal = 0;
	}

	void Set(int vertical, int horizontal);  // Method to set coordinates of the point
	void Move(int x, int y);  // Method to move the point by given values
	void Rotate();   // Method to rotate the point 90 degrees clockwise
	int RetrieveVertical() const { return vertical; }   // Method to retrieve vertical coordinate
	int RetrieveHorizontal() const { return horizontal; } // Method to retrieve horizontal coordinate
};

#endif //Point_H