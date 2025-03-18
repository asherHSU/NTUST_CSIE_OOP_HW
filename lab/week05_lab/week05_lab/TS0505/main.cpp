/***********************************************************************
 * File: main.cpp
 * Author: ¶À®x½n (B11215054, 0978wally@gmail.com)
 * Create Date: 2024-03-21
 * Editor: ¶À®x½n (B11215054, 0978wally@gmail.com)
 * Update Date: 2024-03-21
 * Description: Test program for the Point class, demonstrating its functionalities.
***********************************************************************/
#include<iostream>
#include"Point.h"
using namespace std;

int main(void) {
	Point point;
	point.Set(0, 5); // Setting the initial position
	cout << point. GetHorizontal() << " " << point. GetVertical() << endl;
	point.Reflect(); // Reflecting the point
	cout << point. GetHorizontal() << " " << point. GetVertical() << endl;
	point.Move(1, 2); // Moving the point
	cout << point. GetHorizontal() << " " << point. GetVertical() << endl;
	point.Rotate(); // Rotating the point
	cout << point.GetHorizontal() << " " << point.GetVertical() << endl;
	Point copy = point; // Creating a copy of the point
	cout << "Copy point:" << endl;		
	cout << copy. GetHorizontal() << " " << copy. GetVertical() << endl;
	return 0;
}
