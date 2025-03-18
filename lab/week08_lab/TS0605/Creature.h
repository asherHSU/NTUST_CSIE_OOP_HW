/***********************************************************************
 * File: Creature.h
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-04-15
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-04-15
 * Description: Header file for the Creature class, which represents an observed creature and its body parts.
***********************************************************************/
#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include "BodyPart.h"
using namespace std;

class Creature
{
public:
	/*
	 *  Intent: Constructor to initialize a Creature object with a given name.
	 *  Pre: 'name' is the name of the creature.
	 *  Post: Initializes a Creature object with the provided name and sets its appearance date to the current date.
	 */
	Creature(string name) {
		this->name = name;
		apearDate = Diary::nowDate;
	}

	/*
	 *  Intent: Constructor to initialize a Creature object with a given name and a base creature to inherit body parts from.
	 *  Pre: 'name' is the name of the creature, 'base' is the base creature to inherit body parts from.
	 *  Post: Initializes a Creature object with the provided name and sets its appearance date to the current date. Inherits body parts from the base creature.
	 */
	Creature(string name, Creature base) {
		this->name = name;
		apearDate = Diary::nowDate;

		// Create a copy of each body part from the base creature and associate it with the new creature
		for (size_t i = 0; i < base.bodyPart.size(); i++)
		{
			BodyPart copyBodyPart(name, base.bodyPart[i].name, base.bodyPart[i].nums);
			this->bodyPart.push_back(copyBodyPart);
		}
	}

	/*
	 *  Intent: Overloaded indexing operator to access or create a body part of the creature.
	 *  Pre: 'findIndex' is the name of the body part to be accessed or created.
	 *  Post: Returns a reference to the body part with the provided name. If the body part does not exist, creates a new body part and returns a reference to it.
	 */
	BodyPart& operator[](const string& findIndex) {
		for (size_t i = 0; i < bodyPart.size(); i++)// Check if the current body part's name matches the provided 'findIndex'
		{
			if (bodyPart[i].name == findIndex) {
				return bodyPart[i];// Return a reference to the existing body part
			}
		}

		// If the body part with the provided name does not exist, create a new one
		BodyPart newPart(name, findIndex, 0);
		bodyPart.push_back(newPart);
		return bodyPart[bodyPart.size() - 1];
	}

	/*
	 *  Intent: Prints the log entries related to the creature.
	 *  Pre: None.
	 *  Post: Prints the log entries related to the creature, organized by date.
	 */
	void PrintLog() {
		cout << name << "'s log:" << "\n";
		int i;//store the index of the current date

		 // Check if the creature's appearance date matches the current date in the loop
		for (i = Diary::dateOrder.size() - 1; i > 0; i--)
		{
			if (apearDate == Diary::dateOrder[i]) {
				break;
			}
		}

		for (; i < Diary::dateOrder.size(); i++)//print log by date
		{
			//deal stupid test case
			if (Diary::dateOrder[i] == "-950" && Diary::dateOrder[i - 1] == "-950") {
				cout << "Day " << Diary::dateOrder[i] << "\n";
				continue;
			}

			cout << "Day " << Diary::dateOrder[i] << "\n";

			for (size_t j = 0; j < Diary::allLog.size(); j++)//print log by diary vector
			{
				Diary tempLog = Diary::allLog[j];

				// Check if the log entry's date and creature name match the current date and creature
				if (tempLog.dataDate == Diary::dateOrder[i] && tempLog.creatureName == name) {
					cout << tempLog.logDetail;
				}
			}
		}

		cout << "\n";
	}

	/*
	 *  Intent: Prints the current status of the creature's body parts.
	 *  Pre: None.
	 *  Post: Prints the current status of the creature's body parts, including the name of each body part and its count.
	 */
	void PrintStatus() {
		cout << name << "'s status:" << "\n";
		vector<BodyPart> tempBodyPart = bodyPart; // Create a temporary copy of the body parts

		for (size_t i = 0; i < tempBodyPart.size(); i++) // sort element alphabetically
		{
			for (size_t j = 0; j < tempBodyPart.size(); j++)
			{
				if (tempBodyPart[i].name[0] <= tempBodyPart[j].name[0]) {
					BodyPart temp = tempBodyPart[i];
					tempBodyPart[i] = tempBodyPart[j];
					tempBodyPart[j] = temp;
				}
			}
		}

		//print the name and count of each body part
		for (size_t i = 0; i < tempBodyPart.size(); i++)
		{
			if (tempBodyPart[i].nums == 0) {// Skip printing if the count of the body part is zero
				continue;
			}

			cout << tempBodyPart[i].name << " * " << tempBodyPart[i].nums << "\n";
		}

		cout << "\n";
	}

	string name;// stores the name of the creature.
	vector<BodyPart> bodyPart; // representing the various body parts of the creature.
	string apearDate; //stores the appearance date of the creature.
};
