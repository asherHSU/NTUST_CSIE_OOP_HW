/***********************************************************************
 * File: File.h
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-05-01
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-05-01
 * Description: Header file for the File class, derived from Document.
***********************************************************************/
#pragma once
#include <string>
using namespace std;

class File:public Document
{
public:
	/*
	 * Intent: Construct a file with specified message and file name.
	 * Pre: None.
	 * Post: Initializes the file object with the given message and file name.
	 */
	File(string message, string fileName)
	{
		this->text = message;
		this->fileName = fileName;
	}

	/*
	 * Intent: Get the pathname of the file.
	 * Pre: None.
	 * Post: Returns the pathname of the file.
	 */
	string getPathname() {
		return fileName;
	}

	/*
	 * Intent: Set the pathname of the file.
	 * Pre: None.
	 * Post: Sets the pathname of the file to the specified value.
	 */
	void setPathname(string path) {
		this->fileName = path;
	}
private:
	string fileName;// File name or pathname of the file.
};
