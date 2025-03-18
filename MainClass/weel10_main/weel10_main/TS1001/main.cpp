/***********************************************************************
 * File: main.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-04-26
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-04-26
 * Description: Main program file to demonstrate the use of PrintCombination function.
***********************************************************************/
#include "PrintCombination.h"

#define ELEMENTS_FOR_COMBINATION 6	//i.e., C(5,4) Define the number of elements for combination.
#define DLEMENTS_FOR_CHOICE 3 // Define the number of elements to choose from the combination.

int main(void)
{
	int *arrayPtr = new int[ELEMENTS_FOR_COMBINATION];

	//Get all elements for combination
	for (int i = 0; i < ELEMENTS_FOR_COMBINATION; ++i)
		arrayPtr[i] = i + 1; // Assign each element a value starting from 1.

	PrintCombination(arrayPtr, ELEMENTS_FOR_COMBINATION, DLEMENTS_FOR_CHOICE);

	if (arrayPtr != NULL)
		delete[] arrayPtr;

	return 0;
}
