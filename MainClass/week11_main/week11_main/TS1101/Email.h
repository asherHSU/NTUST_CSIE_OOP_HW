/***********************************************************************
 * File: Email.h
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-05-01
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-05-01
 * Description: Header file for the Email class, derived from Document.
***********************************************************************/
#pragma once
#include <string>
using namespace std;

class Email : public Document
{
public:
	/*
	 * Intent: Construct an email with specified message, sender, recipient, and title.
	 * Pre: None.
	 * Post: Initializes the email object with the given message, sender, recipient, and title.
	 */
	Email(string message, string sender, string recipient, string title)
	{
		this->sender = sender;
		this->recipient = recipient;
		this->title = title;
		this->text = message;
	}

	/*
	 * Intent: Get the sender of the email.
	 * Pre: None.
	 * Post: Returns the sender of the email.
	 */
	string getSender() {
		return sender;
	}

	/*
	 * Intent: Get the recipient of the email.
	 * Pre: None.
	 * Post: Returns the recipient of the email.
	 */
	string getRecipient() {
		return recipient;
	}

	/*
	 * Intent: Get the title of the email.
	 * Pre: None.
	 * Post: Returns the title of the email.
	 */
	string getTitle() {
		return title;
	}

	/*
	 * Intent: Set the sender of the email.
	 * Pre: None.
	 * Post: Sets the sender of the email to the specified value.
	 */
	void setSender() {
		this->sender = sender;
	}

	/*
	 * Intent: Set the recipient of the email.
	 * Pre: None.
	 * Post: Sets the recipient of the email to the specified value.
	 */
	void setRecipient() {
		this->recipient = recipient;
	}

	/*
	 * Intent: Set the title of the email.
	 * Pre: None.
	 * Post: Sets the title of the email to the specified value.
	 */
	void setTitle() {
		this->title = title;
	}
private:
	string sender, recipient, title;// Sender, recipient, and title of the email.
};
