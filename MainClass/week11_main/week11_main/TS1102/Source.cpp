/***********************************************************************
 * File: Source.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-05-01
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-05-01
 * Description: Source file for matrix multiplication program.
***********************************************************************/
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int rowA, colA, rowB, colB;// Variables to store matrix dimensions.
	vector<vector<int>> matrixA, matrixB, result;// Vectors to store matrices and the result.
	cin >> rowA >> colA >> rowB >> colB;

	if (colA != rowB) { // Check if matrix multiplication is possible
		cout << "Matrix multiplication failed.\n";
		return 0;
	}

	for (size_t i = 0; i < rowA; i++)// Read matrix A from input
	{
		vector<int> temp;

		for (size_t j = 0; j < colA; j++)
		{
			int input;
			cin >> input;
			temp.push_back(input);
		}

		matrixA.push_back(temp);
	}

	for (size_t i = 0; i < rowB; i++)// Read matrix B from input
	{
		vector<int> temp;

		for (size_t j = 0; j < colB; j++)
		{
			int input;
			cin >> input;
			temp.push_back(input);
		}

		matrixB.push_back(temp);
	}

	for (size_t i = 0; i < rowA; i++)// Perform matrix multiplication
	{
		vector<int> tempRes;

		for (size_t j = 0; j < colB; j++)
		{
			int res = 0;

			for (size_t k = 0; k < colA; k++)
			{
				res += matrixA[i][k] * matrixB[k][j];
			}

			tempRes.push_back(res);
		}

		result.push_back(tempRes);
	}

	for (size_t i = 0; i < result.size(); i++)// Output the result matrix
	{
		for (size_t j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j];

			if (j < result[i].size() - 1) {
				cout << " ";
			}
		}

		cout << "\n";
	}
}
