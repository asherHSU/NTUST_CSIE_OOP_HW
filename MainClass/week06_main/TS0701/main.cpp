/***********************************************************************
 * File: main.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-03-29
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-03-29
 * Description: Main function to demonstrate the word game.
***********************************************************************/
#include"Form.h"

int main()
{
	Form form1;
	form1.SetInputWord("SWIMMING"); // set input
	form1.ProcessInputWord(); // process input
	form1.SetFileName("words.txt"); // set file name
	form1.Load_CompareWord(); // read-in data and compare
	form1.PrintFoundWords(); // print answers
	return 0;
}