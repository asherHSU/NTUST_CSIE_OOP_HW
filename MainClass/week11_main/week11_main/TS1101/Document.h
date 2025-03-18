/***********************************************************************
 * File: Document.h
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-05-01
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-05-01
 * Description: Header file for the Document class.
***********************************************************************/
#pragma once
#include <string>
using namespace std;

class Document
{
public:
	/*
	 * Intent: Construct an empty document.
	 * Pre: None.
	 * Post: Initializes the text of the document to an empty string.
	 */
	Document()
	{
		text = "";
	}

	/*
	 * Intent: Construct a document with specified text.
	 * Pre: None.
	 * Post: Initializes the text of the document with the given text.
	 */
	Document(string text)
	{
		this->text = text;
	}

	/*
	 * Intent: Get the text of the document (const version).
	 * Pre: None.
	 * Post: Returns the text of the document without allowing modification.
	 */
	string getText()const {
		return text;
	}

	/*
	 * Intent: Get the text of the document (non-const version).
	 * Pre: None.
	 * Post: Returns the text of the document, allowing modification.
	 */
	string getText() {
		return text;
	}

	string text;// Text content of the document.
};

