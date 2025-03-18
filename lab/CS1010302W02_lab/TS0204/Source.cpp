/***********************************************************************
 * File: Source.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-02-29
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-02-29
 * Description: print out N employee¡¦s information.
 *				Each employee has three attributes: Name, Salary and Bonus.
***********************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int employees; //store number of employees

	while (1)
	{
		cin >> employees;
		if (cin.eof()) break;
		vector<string> names, salary, bonus; //Attribute array
		int nameColLen = 0, salaryColLen = 0, bonusColLen = 0; //max width of each Attribute column

		for (size_t i = 0; i < employees; i++)
		{
			string getName, getSalary, getBonus; //current employee Attribute
			cin >> getName;
			cin >> getSalary;
			cin >> getBonus;

			//compare each Attribute max width
			if (getName.length() > nameColLen) nameColLen = getName.length();
			if (getSalary.length() > salaryColLen) salaryColLen = getSalary.length();
			if (getBonus.length() > bonusColLen) bonusColLen = getBonus.length();

			//store each Attribute to Attribute array
			names.push_back(getName);
			salary.push_back(getSalary);
			bonus.push_back(getBonus);
		}

		for (size_t i = 0; i < employees; i++) //print out employee¡¦s information
		{
			cout.width(nameColLen);
			cout << names[i] << "|";
			cout.width(salaryColLen + 2);
			cout << salary[i] << "|";
			cout.width(bonusColLen + 2);
			cout << bonus[i] << "\n";
		}
	}
}