/***********************************************************************
 * File: Student.h
 * Author: ¶À®x½n (B11215054, 0978wally@gmail.com)
 * Create Date: 2024-03-21
 * Editor: ¶À®x½n (B11215054, 0978wally@gmail.com)
 * Update Date: 2024-03-21
 * Description: Header file for the Student class.
***********************************************************************/
#pragma once
#include <string>
using namespace std;

class Student
{
public:
	/* Intent: Constructor to initialize a Student object with provided data.
	 * Pre: The provided firstName, lastName, and phone strings are not empty.
	 * Post: A Student object is created with the given firstName, lastName, and phone.
	 */
	Student(string firstName, string lastName, string phone)
	{
		this->firstName = firstName;
		this->lastName = lastName;
		this->phone = phone;
	}

	string getFirstName() const { //Getter method to retrieve the first name of the student.
		return firstName;
	}

	void setFirstName(string firstName) { //Setter method to set the first name of the student.
		this->firstName = firstName;
	}

	string getLastName() const { //Getter method to retrieve the last name of the student.
		return lastName;
	}

	void setLastName(string lastName) { //Setter method to set the last name of the student.
		this->lastName = lastName;
	}

	string getPhone() const { //Getter method to retrieve the phone number of the student.
		return phone;
	}

	void setPhone(string phone) { //Setter method to set the phone number of the student.
		this->phone = phone;
	}

private:
	string firstName, lastName, phone; //member variables of student data 
};
