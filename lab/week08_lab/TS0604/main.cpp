/***********************************************************************
 * File: main.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-04-15
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-04-15
 * Description: Main program file for demonstrating VecNf operations.
***********************************************************************/
#include<iostream>
#include "VecNf.h"
using namespace std;

int main() {
	VecNf empty;// Create an empty VecNf object
	float a_value[] = { 3.0, 2.0 };// Initialize arrays for vector values
	float b_value[] = { 1, 2, 3 };
	float c_value[] = { 6, 5, 4 };

	// Create VecNf objects A, B, and C with initialized values
	VecNf A(a_value, 2);
	VecNf B(b_value, 3);
	VecNf C(c_value, 3);
	VecNf T;
	T = A; // Assignment operator: Copy values of A to T

	for (int i = 0; i < T.Size(); i++) {// Loop through elements of T and print
		cout << T[i] << " ";
	} cout << endl;

	T = B; // Assignment operator: Copy values of B to T

	for (int i = 0; i < T.Size(); i++) {// Loop through elements of T and print
		cout << T[i] << " ";
	} cout << endl;

	T = B + C; // Vector addition: Add vectors B and C and store in T

	for (int i = 0; i < T.Size(); i++) {// Loop through elements of T and print
		cout << T[i] << " ";
	} cout << endl;
	
	cout << C * B << endl; // Scale
	cout << A * C << endl; // Inconsistent

	return 0;

}