/***********************************************************************
 * File: main.cpp
 * Author: ¶À®x½n (B11215054, 0978wally@gmail.com)
 * Create Date: 2024-03-21
 * Editor: ¶À®x½n (B11215054, 0978wally@gmail.com)
 * Update Date: 2024-03-21
 * Description: Main function to test the HotDogStand class.
***********************************************************************/
#include <iostream>
#include "HotDogStand.h" // Including the header file for HotDogStand class
using namespace std;

int main() {
	HotDogStand stand1("Stand1", 0); // Creating instances of HotDogStand with different IDs and initial sales volumes
	HotDogStand stand2("Stand2", 100);
	HotDogStand stand3("Stand3");
	// Simulating sales by incrementing sales volume for each stand
	stand1.justSold();
	stand2.justSold();
	stand3.justSold();
	// Printing details of each stand
	stand1.print();
	stand2.print();
	stand3.print();
	// Printing total sold amount by accessing static member function
	std::cout << "Total Sold : " << HotDogStand::allStandSoldAmount() << std::endl;
	return 0;

}