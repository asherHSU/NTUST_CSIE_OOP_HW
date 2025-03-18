/***********************************************************************
 * File: Source.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-02-29
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-02-29
 * Description: Compute the tax of different income ranges
***********************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	float income;

	while (1) {
		float tax = 0;
		cin >> income;

		if (cin.eof()) break;

		if (income <= 750) { //compute tax payable of citizens on question table formula
			tax = income * 0.01;
		}
		else if (income <= 2250) {
			tax = 7.5 + (income - 750) * 0.02;
		}
		else if (income <= 3750) {
			tax = 37.5 + (income - 2250) * 0.03;
		}
		else if (income <= 5250) {
			tax = 82.5 + (income - 3750) * 0.04;
		}
		else if (income <= 7000) {
			tax = 142.5 + (income - 5250) * 0.05;
		}
		else {
			tax = 230.0 + (income - 7000) * 0.06;
		}

		printf("%.2f\n", tax);
	}
}
