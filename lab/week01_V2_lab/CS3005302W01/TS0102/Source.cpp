/***********************************************************************
 * File: Source.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-02-22
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-02-22
 * Description: Convert the time format from (seconds) to (hours: minutes: seconds). (Ver2)
***********************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	unsigned long long int input, hour = 0, min = 0, sec = 0;

	while (true)
	{
		if (!(cin >> input) || cin.eof()) break;

		hour = input / 3600;
		input -= 3600 * hour;
		min = input / 60;
		input -= 60 * min;
		sec = input;

		printf("%llu hours %llu minutes and %llu seconds\n", hour, min, sec);
	}
}