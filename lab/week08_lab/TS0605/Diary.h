/***********************************************************************
 * File: Diary.h
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-04-15
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-04-15
 * Description: Header file for the Diary class.
***********************************************************************/
#pragma once
#include <string>
#include <vector>
#include <map>
using namespace std;

class Diary
{
public:
	Diary()
	{
	}

	static void NewDay(string day);// Static method to start a new day in the diary.
	static void addLog(string input, string creatureName, string bodyPartName);//Static method to add a new log entry to the diary.

	// Static members
	static vector<string> dateOrder; // Vector to store the order of dates
	static string nowDate; // Current date
	static vector<Diary> allLog; // Vector to store all log entries

	// Instance members
	string creatureName; // Name of the creature associated with the log
	string bodyPartName; // Name of the body part associated with the log
	string dataDate; // Date of the log entry
	string logDetail; // Details of the log entry
};

