/***********************************************************************
 * File: Diary.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-04-15
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-04-15
 * Description: Implementation file for the Diary class.
***********************************************************************/
#include "Diary.h"
#include <string>
using namespace std;

vector<string> Diary::dateOrder; // Initializing the static vector to store the order of dates
vector<Diary> Diary::allLog; // Initializing the static vector to store all logs
string Diary::nowDate; // Initializing the static variable to store the current date

/*
 * Intent: Add a new log entry to the diary.
 * Pre: 'input', 'creatureName', and 'bodyPartName' are strings representing log details, creature name, and body part name respectively.
 * Post: Creates a new log entry with the specified details and adds it to the allLog vector.
 */
void Diary::NewDay(string day)
{
	dateOrder.push_back(day);// Adding the day to the date order list
	nowDate = day;// Updating the current date
}

/*
 * Intent: Adds a new log entry to the diary.
 * Pre: 'input' is the detailed description of the log, 'creatureName' is the name of the creature being observed, and 'bodyPartName' is the name of the body part being observed.
 * Post: Creates a new Diary object to store the log data, sets the log's date to the current date, sets the log's creature name and body part name, assigns the log's detail, and adds the new log entry to the allLog vector.
 */
void Diary::addLog(string input, string creatureName, string bodyPartName) {
	// Creating a new Diary object to store the log data
	Diary newData;
	newData.dataDate = Diary::nowDate; // Setting the log's date to the current date
	newData.creatureName = creatureName; // Setting the log's creature name
	newData.bodyPartName = bodyPartName; // Setting the log's body part name
	newData.logDetail = input; // Setting the log's detail
	allLog.push_back(newData); // Adding the new log entry to the allLog vector
}
