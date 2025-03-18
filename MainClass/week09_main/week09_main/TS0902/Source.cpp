/***********************************************************************
 * File: Source.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-04-19
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-04-19
 * Description:prompts the user to enter a username and a password, validating each against specific criteria.
 ***********************************************************************/
#include <iostream>
#include <string>
using namespace std;

namespace username
{
	bool isValid();// Function declaration to check if the entered username is valid
	string userName;//store the username

	/*
	 * Intent: Prompt the user to enter a valid username
	 * Pre: None
	 * Post: User inputs a valid username
	 */
	void inputUserName()
	{
		do
		{
			cout << "Enter your username (8 letters only)" << endl;
			cin >> userName;
		} while (!isValid());// Continue prompting until a valid username is entered
	}

	/*
	 * Intent: Get the stored username
	 * Pre: Username is initialized and valid
	 * Post: Return the stored username
	 */
	string getUserName()
	{
		return userName;
	}

	/*
	 * Intent: Check if the entered username is valid
	 * Pre: None
	 * Post: Return true if the username is valid, false otherwise
	 */
	bool isValid() {
		if (userName.length() != 8) {// Username is invalid if it's not 8 characters long
			return false;
		}

		for (size_t i = 0; i < 8; i++)
		{
			// Check if each character of the username is an alphabet letter
			if (isalpha(userName[i]) == false) {
				return false;
			}
		}

		return true;
	}
}

namespace password
{
	bool isValid();//check if the entered password is valid
	string password;// Variable to store the password

	/*
	 * Intent: Prompt the user to enter a valid password
	 * Pre: None
	 * Post: User inputs a valid password
	 */
	void inputPassword()
	{
		do
		{
			cout << "Enter your password (at least 8 characters " <<
				"and at least one non-letter)" << endl;
			cin >> password;
		} while (!isValid());// Continue prompting until a valid password is entered
	}

	/*
	 * Intent: Get the stored password
	 * Pre: Password is initialized and valid
	 * Post: Return the stored password
	 */
	string getPassword()
	{
		return password;
	}

	/*
	 * Intent: Check if the entered password is valid
	 * Pre: None
	 * Post: Return true if the password is valid, false otherwise
	 */
	bool isValid() {
		if (password.length() < 8) {// Password is invalid if it's less than 8 characters
			return false;
		}

		bool hasDigit = false;

		for (size_t i = 0; i < password.length(); i++)
		{
			if (isdigit(password[i])) {// Check if the character is a digit
				hasDigit = true;
			}
		}

		if (hasDigit) {// Return true if the password has at least one digit
			return true;
		}

		return false;
	}
}

int main()
{
    username::inputUserName();// Prompt the user to input a username ans passwd
    password::inputPassword();
    cout << "Your username is " << username::getUserName() <<
        " and your password is: " <<
		password::getPassword() << endl;// Output the entered username and password
    return 0;
}