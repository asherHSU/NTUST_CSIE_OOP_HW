/***********************************************************************
 * File: BodyPart.h
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-04-15
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-04-15
 * Description: Header file for the BodyPart class.
***********************************************************************/
#pragma once
#include <string>
#include "Diary.h"
#include "Creature.h"
#include <string>
#include <vector>
using namespace std;

class BodyPart
{
public:
	/*
	 * Intent: Default constructor to initialize a BodyPart object with default values.
	 * Pre: None
	 * Post: Creates a BodyPart object with empty creature name, name, and zero count of body parts.
	 */
	BodyPart()
	{
		creatureName = "";
		name = "";
		nums = 0;
	}

	/*
	 * Intent: Parameterized constructor to initialize a BodyPart object with specified values.
	 * Pre: 'creatureName' is the name of the creature, 'name' is the name of the body part, and 'nums' is the count of body parts.
	 * Post: Creates a BodyPart object with the provided values.
	 */
	BodyPart(string creatureName, string name, int nums)
	{
		this->creatureName = creatureName;
		this->name = name;
		this->nums = nums;
	}

	/*
	 * Intent: Overloaded assignment operator to assign a new count of body parts and generate a log entry.
	 * Pre: 'rhs' is the new count of body parts.
	 * Post: Assigns 'rhs' to the count of body parts and generates a log entry based on the change.
	 */
	BodyPart& operator=(const int& rhs) {
		string date = Diary::nowDate;
		string log;

		if (nums == 0 && rhs != 0) {// Generate a log entry if the body part appears for the first time
			log = creatureName + "'s " + name + " appeared (" + to_string(nums) + " -> " + to_string(rhs) + ").\n";
			Diary::addLog(log, creatureName, name);
		}
		else if (rhs > nums) {// Generate a log entry if the count of the body part increases
			log = creatureName + "'s " + name + " increased (" + to_string(nums) + " -> " + to_string(rhs) + ").\n";
			Diary::addLog(log, creatureName, name);
		}
		else if (rhs < nums) {// Generate a log entry if the count of the body part decreases
			log = creatureName + "'s " + name + " decreased (" + to_string(nums) + " -> " + to_string(rhs) + ").\n";
			Diary::addLog(log, creatureName, name);
		}

		this->nums = rhs;
		return *this;
	}

	/*
	 * Intent: Overloaded addition assignment operator to add a count to the existing count of body parts and generate a log entry.
	 * Pre: 'rhs' is the count to be added.
	 * Post: Adds 'rhs' to the existing count of body parts and generates a log entry based on the change.
	 */
	BodyPart& operator+=(const int& rhs) {
		string date = Diary::nowDate;
		string log;

		if (nums == 0 && rhs != 0) {// Generate a log entry if the body part appears for the first time
			log = creatureName + "'s " + name + " appeared (" + to_string(nums) + " -> " + to_string(rhs) + ").\n";
			Diary::addLog(log, creatureName, name);
		}
		else if (rhs > 0) {// Generate a log entry if the count of the body part increases
			log = creatureName + "'s " + name + " increased (" + to_string(nums) + " -> " + to_string(rhs + nums) + ").\n";
			Diary::addLog(log, creatureName, name);
		}
		else if (rhs < 0) {// Generate a log entry if the count of the body part decreases
			log = creatureName + "'s " + name + " decreased (" + to_string(nums) + " -> " + to_string(nums + rhs) + ").\n";
			Diary::addLog(log, creatureName, name);
		}

		this->nums += rhs;
		return *this;
	}

	/*
	 * Intent: Overloaded subtraction assignment operator to subtract a count from the existing count of body parts and generate a log entry.
	 * Pre: 'rhs' is the count to be subtracted.
	 * Post: Subtracts 'rhs' from the existing count of body parts and generates a log entry based on the change.
	 */
	BodyPart& operator-=(const int& rhs) {
		string date = Diary::nowDate;
		string log;

		if (nums == 0 && rhs != 0) {// Generate a log entry if the body part appears for the first time
			log = creatureName + "'s " + name + " appeared (" + to_string(nums) + " -> " + to_string(-rhs) + ").\n";
			Diary::addLog(log, creatureName, name);
			this->nums = -rhs;
		}
		else if (rhs < 0) {// Generate a log entry if the count of the body part increases
			log = creatureName + "'s " + name + " increased (" + to_string(nums) + " -> " + to_string(nums - rhs) + ").\n";
			Diary::addLog(log, creatureName, name);
			this->nums -= rhs;
		}
		else if (rhs > 0) {// Generate a log entry if the count of the body part decreases
			log = creatureName + "'s " + name + " decreased (" + to_string(nums) + " -> " + to_string(nums - rhs) + ").\n";
			Diary::addLog(log, creatureName, name);
			this->nums -= rhs;
		}

		return *this;
	}

	string creatureName; // Name of the creature
	string name; // Name of the body part
	int nums; // Count of the body part
};
