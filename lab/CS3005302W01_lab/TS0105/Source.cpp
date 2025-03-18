/***********************************************************************
 * File: Source.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-02-22
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-02-22
 * Description: Given a radius r, compute the volume of a sphere. (Ver2)
***********************************************************************/
#include <iostream>
using namespace std;

int main() {
	double input;
	const double PI = 3.14159265358979323846;

	while (true)
	{
		cin >> input;
		if (cin.eof()) break;

		double volume = (4 * PI * pow(input, 3)) / 3.0; // compute volume

		cout.setf(ios::fixed);
		cout << volume << "\n";
	}
}