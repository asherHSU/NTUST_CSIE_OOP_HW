/***********************************************************************
 * File: HotDogStand.cpp
 * Author: ¶À®x½n (B11215054, 0978wally@gmail.com)
 * Create Date: 2024-03-21
 * Editor: ¶À®x½n (B11215054, 0978wally@gmail.com)
 * Update Date: 2024-03-21
 * Description: Implementation file for the HotDogStand class
***********************************************************************/
#include "HotDogStand.h"
#include <iostream>
#include <string>
using namespace std;

int HotDogStand::totalSellAmount = 0;

/* Intent: Construct a HotDogStand object with the given ID and initialize sales volume to 0.
 * Pre: Takes a string ID representing the stand ID.
 * Post: Initializes standId with the provided ID and sets hotDogSellAmount to 0.
 */
HotDogStand::HotDogStand(const string id)
{
	this->standId = id;
	this->hotDogSellAmount = 0;
}

/* Intent: Construct a HotDogStand object with the given ID and sales volume.
 * Pre: Takes a string ID representing the stand ID and an integer amount representing the sales volume.
 * Post: Initializes standId with the provided ID and sets hotDogSellAmount to the provided amount.
 *       Updates the static variable totalSellAmount accordingly.
 */
HotDogStand::HotDogStand(const string id, int amount)
{
	this->standId = id;
	this->hotDogSellAmount = amount;
	totalSellAmount += amount;
}

/* Intent: Increment the sales volume of the hot dog stand by 1.
 * Pre: None.
 * Post: Increases hotDogSellAmount by 1 and updates totalSellAmount accordingly.
 */
void HotDogStand::justSold()
{
	this->hotDogSellAmount++;
	totalSellAmount++;
}

/* Intent: Print the ID and sales volume of the hot dog stand.
 * Pre: None.
 * Post: Prints the standId and hotDogSellAmount separated by a space.
 */
void HotDogStand::print()
{
	cout << this->standId << " " << this->hotDogSellAmount <<"\n";
}

/* Intent: Retrieve the sales volume of the hot dog stand.
 * Pre: None.
 * Post: Returns the value of hotDogSellAmount.
 */
int HotDogStand::thisStandSoldAmount()
{
	return this->hotDogSellAmount;
}

/* Intent: Retrieve the total sales volume of all hot dog stands.
 * Pre: None.
 * Post: Returns the value of totalSellAmount.
 */
int HotDogStand::allStandSoldAmount()
{
	return totalSellAmount;
}
