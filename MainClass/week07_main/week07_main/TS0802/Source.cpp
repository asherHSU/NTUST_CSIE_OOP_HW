/***********************************************************************
 * File: Source.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-04-08
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-04-08
 * Description: Program to calculate matrix multiplication.
***********************************************************************/
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int rowA = 0, colA = 0, rowB = 0, colB = 0; //matrix dimensions.
	vector<vector<int>> matrixA, matrixB, result; //store matrix

	while (true)  // Check for end of file.
	{
		cin >> rowA >> colA >> rowB >> colB; // Input matrix dimensions.

		if (cin.eof())break;

		if (colA != rowB) {  // Check if dimensions allow matrix multiplication.
			cout << "Matrix multiplication failed.";
			return 0;
		}

		for (size_t i = 0; i < rowA; i++)  // Input elements of matrix A.
		{
			vector<int> tempRow(colA);

			for (size_t j = 0; j < colA; j++)
			{
				cin >> tempRow[j];
			}

			matrixA.push_back(tempRow);
		}

		for (size_t i = 0; i < rowB; i++) // Input elements of matrix B.
		{
			vector<int> tempRow(colB);

			for (size_t j = 0; j < colB; j++)
			{
				cin >> tempRow[j];
			}

			matrixB.push_back(tempRow);
		}

		for (size_t i = 0; i < rowA; i++)  // Calculate matrix multiplication.
		{
			vector<int> rowRes(colB);

			for (size_t j = 0; j < colB; j++)
			{
				int sum = 0;

				for (size_t k = 0; k < colA; k++)
				{
					sum += matrixA[i][k] * matrixB[k][j]; // Perform dot product of rows of A and columns of B.
				}

				rowRes[j] = sum;
			}

			result.push_back(rowRes);
		}

		for (size_t i = 0; i < rowA; i++)  // Output the result of matrix multiplication.
		{
			for (size_t j = 0; j < colB; j++)
			{
				cout << result[i][j];

				if (j < colB - 1) { //no space in the end
					cout << " ";
				}
			}

			if (i < rowA - 1) { //no \n int the end
				cout << "\n";
			}
		}
	}
}
