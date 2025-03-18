/***********************************************************************
 * File: BansAccount.cpp
 * Author: ¶À®x½n(0978wally@gmail.com)
 * Create Date: 2024-03-14
 * Editor: ¶À®x½n(0978wally@gmail.com)
 * Update Date: 2024-03-14
 * Description: Implementation of the BankAccount class methods.
 * ***********************************************************************/
#include "BankAccount.h"
using namespace std;

int BankAccount::total = 0; // Static member initialization

BankAccount::BankAccount() { // Default constructor
	this->balance = 0;
}

BankAccount ::BankAccount(int input) { // Parameterized constructor
	this->balance = input;
	this->total += input;
}

void BankAccount::withdraw(int output) { // withdraw money in the bank with the value of output.
	this->balance -= output;
	this->total -= output;
}

void BankAccount::save(int input) { // save money in the bank with the value of input.
	this->balance += input;
	this->total += input;
}

int BankAccount::getBalance() { // return the current balance of this account.
	return this->balance;
}

int BankAccount::getAllMoneyInBank() { // return the value of the total money amount in the bank
	return total;
}