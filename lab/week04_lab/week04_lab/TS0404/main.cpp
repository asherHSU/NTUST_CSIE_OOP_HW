/***********************************************************************
 * File: main.cpp
 * Author: ¶À®x½n(0978wally@gmail.com)
 * Create Date: 2024-03-14
 * Editor: ¶À®x½n(0978wally@gmail.com)
 * Update Date: 2024-03-14
 * Description: demonstrating the usage of BankAccount class.
 * ***********************************************************************/
#include <iostream>
#include "BankAccount.h"

using namespace std;

int main() {
	// Creating instances of BankAccount with different initial balances
	BankAccount bankAccount1(200), bankAccount2, bankAccount3(-100);
	// Displaying the total money in the bank
	cout << BankAccount::getAllMoneyInBank() << endl;
	bankAccount1.withdraw(100);  // Withdrawing money from bankAccount1
	cout << bankAccount1.getBalance() << endl; // Displaying the balance of bankAccount1 after withdrawing
	cout << BankAccount::getAllMoneyInBank() << endl; // Displaying the updated total money in the bank after withdrawal
	bankAccount2.save(50); // Saving money to bankAccount2
	cout << bankAccount2.getBalance() << endl; // Displaying the balance of bankAccount2 after saving
	cout << BankAccount::getAllMoneyInBank() << endl; // Displaying the updated total money in the bank after saving
	return 0;
}
