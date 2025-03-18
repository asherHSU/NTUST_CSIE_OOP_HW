/***********************************************************************
 * File: BankAccount.h
 * Author: ¶À®x½n(0978wally@gmail.com)
 * Create Date: 2024-03-14
 * Editor: ¶À®x½n(0978wally@gmail.com)
 * Update Date: 2024-03-14
 * Description: Declaration of the BankAccount class.
 * ***********************************************************************/
#ifndef _BankAccount_H_
#define _BankAccount_H_

class BankAccount {
private:
	int balance; //store the total money amount of all accounts in the bank.
	static int total; //store the money amount of each account.
public:
	BankAccount(); // Default constructor
	BankAccount(int input); // Parameterized constructor
	void withdraw(int output); // Method to withdraw money
	void save(int input); // Method to save money
	int getBalance(); // Method to get the balance
	static int getAllMoneyInBank(); // Static method to get the total money in the bank
};

#endif
