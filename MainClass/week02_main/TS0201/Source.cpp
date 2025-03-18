/***********************************************************************
 * File: Source.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-02-29
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-02-29
 * Description: computes the average and standard deviation of input scores.
***********************************************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	long double totalData;

	while (1) {
		long double sum = 0, avg = 0, deviation = 0;
		cin >> totalData; //store number of element each line
		vector<long double> data; //store each line element

		if (cin.eof()) break;

		for (size_t i = 0; i < totalData; i++) //get each line element
		{
			double currentVal;
			cin >> currentVal;
			sum += currentVal;
			data.push_back((long double)currentVal);
		}

		avg = (long double)sum / totalData; //compute average

		for (size_t i = 0; i < totalData; i++) //compute deviation
		{
			deviation += pow(data[i] - avg, 2);
		}

		deviation /= totalData;
		deviation = sqrt(deviation);

		cout << "Average:" << avg << '\t' << "Standard deviation:" << deviation << "\n";
	}
}
