/***********************************************************************
 * File: HotDogStand.h
 * Author: ¶À®x½n (B11215054, 0978wally@gmail.com)
 * Create Date: 2024-03-21
 * Editor: ¶À®x½n (B11215054, 0978wally@gmail.com)
 * Update Date: 2024-03-21
 * Description: Header file for the HotDogStand class, representing a hot dog stand.
***********************************************************************/
#pragma once
#include <string>
#include <string>
using namespace std;

class HotDogStand
{
public:
	HotDogStand(const string id); // Constructor: initializes standId with provided ID and sets sales volume to 0
	HotDogStand(const string id, int amount);  // Constructor: initializes standId with provided ID and sets sales volume to provided amount
	void justSold(); // Increment sales volume of the stand by 1
	void print(); // Print ID and sales volume of the stand
	int thisStandSoldAmount(); // Retrieve sales volume of the stand
	static int allStandSoldAmount(); // Retrieve total sales volume of all stands
private:
	string standId; // ID of the hot dog stand
	int hotDogSellAmount; // Sales volume of the hot dog stand
	static int totalSellAmount; // Total sales volume of all hot dog stands
};

