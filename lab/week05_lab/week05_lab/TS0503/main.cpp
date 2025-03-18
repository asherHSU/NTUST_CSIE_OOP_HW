/***********************************************************************
 * File: main.cpp
 * Author: ¶À®x½n (B11215054, 0978wally@gmail.com)
 * Create Date: 2024-03-21
 * Editor: ¶À®x½n (B11215054, 0978wally@gmail.com)
 * Update Date: 2024-03-21
 * Description: manage student records with insert, search, delete.
***********************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include "Student.h"
using namespace std;

// Function prototypes
bool checkInputVaild(string firstName, string lastName, string phone);
void insertStu(vector<Student>& student, string firstName, string lastName, string phone);
void deleteStu(vector<Student>& student, string firstName, string lastName, string phone);
int searchStu(vector<Student>& student, string firstName, string lastName, string phone);

int main() {
	string firstCommand, firstName, lastName, phone; // student records data
	vector<Student> student; // store student records
	vector<string> commands; // store user commands

	while (true) // Continuous reading of commands until end-of-file is reached
	{
		if (cin.eof()) {
			break;
		}

		string command;
		cin >> command; //get input command
		commands.push_back(command);
	}

	for (size_t i = 0; i < commands.size() - 1; i++)  // Iterate through the commands vector
	{
		if (commands[i] == "print") { // Check if the command is to print student records
			if (student.size() > 0) { // Check if student records not empty
				for (size_t i = 0; i < student.size(); i++)
				{
					// Print student information
					cout << student[i].getFirstName() << " " << student[i].getLastName() << " " << student[i].getPhone() << "\n";
				}
			}
			else {
				cout << "Print Error\n"; // Print error message if there are no student records
			}
		}
		else if (commands[i] == "insert") { // Check if the command is to insert a student record
			firstName = commands[i + 1]; //get student record data
			lastName = commands[i + 2];
			phone = commands[i + 3];
			i += 3;

			if (checkInputVaild(firstName, lastName, phone) == false) { // Check if the input data is valid
				cout << "Input Error\n";
				continue;
			}

			insertStu(student, firstName, lastName, phone); // Insert the student record
		}
		else if (commands[i] == "search") { // Check if the command is to search for a student record
			firstName = commands[i + 1]; //get student record data
			lastName = commands[i + 2];
			phone = commands[i + 3];
			i += 3;

			if (checkInputVaild(firstName, lastName, phone) == false) {  // Check if the input data is valid
				cout << "Input Error\n";
				continue;
			}

			int searchIndex = searchStu(student, firstName, lastName, phone); // Search for the student record

			if (searchIndex != -1) {
				cout << searchIndex << "\n"; // Print the index of the found student record
			}
			else {
				cout << "Search Error\n";  // Print error message if student record is not found
			}
		}
		else if (commands[i] == "delete") {
			firstName = commands[i + 1]; //get student record data
			lastName = commands[i + 2];
			phone = commands[i + 3];
			i += 3;

			if (checkInputVaild(firstName, lastName, phone) == false) {  // Check if the input data is valid
				cout << "Input Error\n";
				continue;
			}

			deleteStu(student, firstName, lastName, phone); // Delete the student record
		}
		else {
			cout << "Input Error\n";
		}
	}
}

/* Intent: Check if the input data (firstName, lastName, phone) is valid.
 * Pre: input strings firstName, lastName, and phone are provided.
 * Post:  Returns true if the input data is valid, otherwise returns false.
 */
bool checkInputVaild(string firstName, string lastName, string phone) {
	// Check if the length of input strings exceeds the specified limits
	if (firstName.length() > 25 || lastName.length() > 30 || phone.length() > 15) {
		return false;
	}

	for (size_t i = 0; i < phone.length(); i++)
	{
		if (!isdigit(phone[i])) { // Check if phone contains non-digit characters
			return false;
		}
	}
	return true;
}

/* Intent: Insert a new student record into the student vector.
 * Pre: The student vector and input data (firstName, lastName, phone) are provided.
 * Post:  Inserts the new student record into the student vector if record not repeat and record size < 10.
 */
void insertStu(vector<Student>& student, string firstName, string lastName, string phone) {
	if (student.size() < 10 && searchStu(student, firstName, lastName, phone) == -1) { //check record not repeat and record size < 10
		Student newStudent(firstName, lastName, phone); // temp student object
		student.push_back(newStudent); // Add the new student record to the student vector
	}
	else {
		cout << "Insert Error\n";
	}
}

/* Intent: Delete a student record from the student vector.
 * Pre: The student vector and input data (firstName, lastName, phone) are provided.
 * Post: Deletes the specified student record from the student vector if found.
 */
void deleteStu(vector<Student>& student, string firstName, string lastName, string phone) {
	bool canDelete = false;

	for (size_t i = 0; i < student.size(); i++)
	{
		// find correspond student
		if (student[i].getFirstName() == firstName && student[i].getLastName() == lastName && student[i].getPhone() == phone) {
			canDelete = true;
			student.erase(student.begin() + i); // Delete the student record from the student vector
		}
	}

	if (canDelete == false) {
		cout << "Delete Error\n";
	}
}

/* Intent: Search for a student record in the student vector.
 * Pre: The student vector and input data (firstName, lastName, phone) are provided.
 * Post: Returns the index of the found student record if exists, otherwise returns -1.
 */
int searchStu(vector<Student>& student, string firstName, string lastName, string phone) {
	bool canFind = false;

	for (size_t i = 0; i < student.size(); i++)
	{
		// find correspond student
		if (student[i].getFirstName() == firstName && student[i].getLastName() == lastName && student[i].getPhone() == phone) {
			canFind = true;
			return i;
			break;
		}
	}

	if (canFind == false) { //studend record doesn't exist, return -1
		return -1;
	}
	return -1;
}
