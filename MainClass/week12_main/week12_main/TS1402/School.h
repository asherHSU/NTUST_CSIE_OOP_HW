/***********************************************************************
 * File: School.h
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-05-08
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-05-08
 * Description: declaration of the School, PrivateSchool, and PublicSchool classes.
***********************************************************************/
#pragma once
#include <string>
#include <iostream>
using namespace std;

class School
{
public:
	string name; // The name of the school.
	int studentAmount; // The current number of students in the school.
	int studentAmountNextYear; // The number of students in the school for the next year.

	/*
	 * Intent: Default constructor for the School class.
	 * Pre: None.
	 * Post: A School object is created with default values.
	 */
	School()
	{
		studentAmount = 0;
		studentAmountNextYear = 0;
	}

	/*
	 * Intent: Parameterized constructor for the School class.
	 * Pre: The name of the school and the number of students are provided.
	 * Post: A School object is created with the given values.
	 */
	School(string name, int amount)
	{
		this->name = name;
		studentAmount = amount;
		studentAmountNextYear = amount;
	}

	/*
	 * Intent: Admits new students to the school.
	 * Pre: The number of new students is provided.
	 * Post: The current number of students is increased by the given amount.
	 */
	virtual void admissions(float amount) {
		if (amount > 0) {//check amount vaild
			studentAmount += amount;
		}
	}

	/*
	 * Intent: Drops students from the school.
	 * Pre: The number of students to be dropped is provided.
	 * Post: The current number of students is decreased by the given amount.
	 */
	virtual void dropouts(float amount) {
		if (amount > 0 && studentAmount >= amount) {//check amount vaild
			studentAmount -= amount;
		}
	}

	/*
	 * Intent: Transfers students from this school to another school.
	 * Pre: The number of students to be transferred and the school to transfer to are provided.
	 * Post: The current number of students is decreased by the given amount and the number of students in the other school is increased by the same amount.
	 */
	void transfer(float amount, School& toSchool) {
		if (amount > 0 && studentAmount >= amount) {//check amount vaild
			dropouts(amount);
			toSchool.admissions(amount);
		}
	}

	/*
	 * Intent: Overloads the << operator for the School class.
	 * Pre: An ostream object and a School object are provided.
	 * Post: The name, current number of students, and projected number of students for the next year of the School object are output to the ostream object.
	 */
	friend ostream& operator<<(ostream& outputStream, School school) {
		outputStream << school.name << "\t" << school.studentAmount << "\t" << school.studentAmountNextYear;
		return outputStream;
	}
};

class PrivateSchool : public School
{
public:
	bool hasOneWave;// Indicates whether the school has had a wave of dropouts.

	/*
	 * Intent: Parameterized constructor for the PrivateSchool class.
	 * Pre: The name of the school and the number of students are provided.
	 * Post: A PrivateSchool object is created with the given values.
	 */
	PrivateSchool(string name, int amount)
	{
		this->name = name;
		studentAmount = amount;
		studentAmountNextYear = amount;
		hasOneWave = false;
	}

	/*
	 * Intent: Drops students from the school.
	 * Pre: The number of students to be dropped is provided.
	 * Post: The current number of students is decreased by the given amount. If the school has had a wave of dropouts, the projected number of students for the next year is decreased by 100. Otherwise, the wave of dropouts is set to true.
	 */
	void dropouts(float amount) {
		if (amount > 0 && studentAmount >= amount) {//check amount vaild
			studentAmount -= amount;

			if (hasOneWave) { //check penalties 
				studentAmountNextYear -= 100;
			}
			else {
				hasOneWave = true;
			}
		}
	}
};

class PublicSchool : public School
{
public:
	float growing_rate;// The growth rate of the school.

	/*
	 * Intent: Parameterized constructor for the PublicSchool class.
	 * Pre: The name of the school and the number of students are provided.
	 * Post: A PublicSchool object is created with the given values.
	 */
	PublicSchool(string name, int amount)
	{
		this->name = name;
		studentAmount = amount;
		studentAmountNextYear = amount;
		growing_rate = 0.05;
	}

	/*
	 * Intent: Applies the growth rate to the projected number of students for the next year.
	 * Pre: None.
	 * Post: The projected number of students for the next year is increased by the growth rate.
	 */
	void apply_growth() {
		studentAmountNextYear += growing_rate * studentAmountNextYear;
	}

	/*
	 * Intent: Drops students from the school.
	 * Pre: The number of students to be dropped is provided.
	 * Post: The current number of students is decreased by the given amount. If the number of students to be dropped is greater than 100, the projected number of students for the next year is decreased by 5%.
	 */
	void dropouts(float amount) {
		if (amount > 0 && studentAmount >= amount) { //check amount vaild
			studentAmount -= amount;

			if (amount > 100) { //amount > 100, penalties 5%
				studentAmountNextYear -= (studentAmountNextYear * 0.05);
			}
		}
	}
};
