/***********************************************************************
 * File: Point.cpp
 * Author: ¶À®x½n(0978wally@gmail.com)
 * Create Date: 2024-03-14
 * Editor: ¶À®x½n(0978wally@gmail.com)
 * Update Date: 2024-03-14
 * Description: Implementation of the Point class methods.
 * ***********************************************************************/
#include "Point.h"

/* Intent: Set the coordinate position of the point.
 * Pre: Integer values vertical and horizontal.
 * Post: Sets the vertical and horizontal values of the point.
 */
void Point::Set(int vertical, int horizontal)
{
	this->vertical = vertical;
	this->horizontal = horizontal;
}

/* Intent: Move the point by given x and y values.
 * Pre: Integer values x and y.
 * Post: Moves the point by x pixels on x-axis and y pixels on y-axis.
 */
void Point::Move(int x, int y)
{
	this->horizontal += y;
	this->vertical += x;
}

/* Intent: Rotate the point 90 degrees clockwise from origin.
 * Pre: None.
 * Post: Rotates the point 90 degrees clockwise.
 */
void Point::Rotate()
{
	int temp = this->horizontal;
	this->horizontal = this->vertical * -1;
	this->vertical = temp;
}
