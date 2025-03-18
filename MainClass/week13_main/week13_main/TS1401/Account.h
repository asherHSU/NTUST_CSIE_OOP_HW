/***********************************************************************
 * File: Account.h
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-05-15
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-05-15
 * Description: Header file for the Account class.
***********************************************************************/
#pragma once
// Declaration of custom exception class InsufficientFunds derived from std::exception.
class InsufficientFunds : public std::exception {

};

// Declaration of custom exception class NegativeDeposit derived from std::exception.
class NegativeDeposit : public std::exception {

};

// Declaration of the Account class.
class Account
{
private:
	double balance; // Private member variable to store the account balance.
public:
	/*
	 *  Intent: Default constructor for the Account class.
	 *  Pre: None.
	 *  Post: Initializes the balance to 0.
	 */
	Account() { balance = 0; }

	/*
	 *  Intent: Constructor for the Account class with initial deposit.
	 *  Pre: initialDeposit.
	 *  Post: Initializes the balance to the provided initialDeposit.
	 */
	Account(double initialDeposit) { balance = initialDeposit; }

	/*
	 *  Intent: Retrieve the current balance of the account.
	 *  Pre: None.
	 *  Post: Returns the current balance of the account.
	 */
	double getBalance() { return balance; }

	/*
	 *  Intent: Deposit a specified amount into the account.
	 *  Pre: Amount should be greater than 0.
	 *  Post: Increases the balance by the deposited amount.
	 */
	double deposit(double amount)
	{
		if (amount > 0) {//NegativeDeposit exception if the amount is not positive.
			balance += amount;
		}
		else {
			throw NegativeDeposit();
		}

		return balance;
	}

	/*
	 *  Intent: Withdraw a specified amount from the account.
	 *  Pre: Amount should be non-negative and less than or equal to balance.
	 *  Post: Decreases the balance by the withdrawn amount.
	 */
	double withdraw(double amount)
	{
		if ((amount > balance) || (amount < 0)) {//InsufficientFunds exception if the amount exceeds the balance or is negative.
			throw InsufficientFunds();
		}
		else {
			balance -= amount;
		}

		return balance;
	}
};

