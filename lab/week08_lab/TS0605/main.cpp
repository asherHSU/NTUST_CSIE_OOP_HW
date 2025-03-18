/***********************************************************************
 * File: main.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-04-15
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-04-15
 * Description:
***********************************************************************/

#include "Diary.h" // Including the header file for the Diary class
#include "Creature.h" // Including the header file for the Creature class
#include "BodyPart.h" // Including the header file for the BodyPart class
#include <iostream> // Including the standard I/O stream library
using namespace std; // Using the standard namespace

int main() {

	// Creating a new day entry in the diary with date "0000"
	Diary::NewDay("0000");
	// Creating a new Creature object named unknownA with identifier "UA"
	Creature unknownA("UA");
	// Assigning 16 to the "leg" body part of unknownA
	unknownA["leg"] = 16;

	// Creating a new day entry in the diary with date "0102"
	Diary::NewDay("0102");
	// Creating a new Creature object named unknownB with identifier "UB" based on unknownA
	Creature unknownB("UB", unknownA);
	// Adding 26 to the "leg" body part of unknownB
	unknownB["leg"] += 26;
	// Printing the observation log of unknownA
	unknownA.PrintLog();

	// Creating a new day entry in the diary with date "0227"
	Diary::NewDay("0227");
	// Resetting the "leg" body part count of unknownA to 0
	unknownA["leg"] = 0;
	// Printing the status of unknownA
	unknownA.PrintStatus();
	// Printing the observation log of unknownB
	unknownB.PrintLog();

	// Creating a new day entry in the diary with date "0353"
	Diary::NewDay("0353");
	// Adding 6 to the "leg" body part and 4 to the "wing" body part of unknownA
	unknownA["leg"] += 6;
	unknownA["wing"] += 4;
	// Printing the observation log of unknownA
	unknownA.PrintLog();
	cout << "----------------------\n"; // Printing a separator line

	// Creating historical records in the diary
	Diary::NewDay("-2000");
	Diary::NewDay("-1050");
	// Creating a new Creature object named horse
	Creature horse("Horse");
	// Assigning 4 to the "leg" and 2 to the "hand" body parts of horse
	horse["leg"] = 4;
	horse["hand"] = 2;

	Diary::NewDay("-1000");
	// Adding 1 to the "leg" and subtracting 1 from the "hand" body parts of horse
	horse["leg"] += 1;
	horse["hand"] -= 1;

	Diary::NewDay("-950");
	// Adding 1 to the "leg" and subtracting 1 from the "hand" body parts of horse
	horse["leg"] += 1;
	horse["hand"] -= 1;

	Diary::NewDay("-950");
	// Resetting the "hand" body part count of horse to 0
	horse["hand"] = 0;
	// Creating a new Creature object named horse2 based on horse
	Creature horse2("Horse2", horse);
	// Printing the observation log of horse2
	horse2.PrintLog();

	Diary::NewDay("1000");
	// Printing the status of horse2
	horse2.PrintStatus();
	// Adding 1 to the "horn" body part of horse
	horse["horn"] += 1;
	// Resetting the "horn" body part count of horse to 1
	horse["horn"] = 1;

	Diary::NewDay("1220");
	// Subtracting 2 from the "wing" body part of horse2
	horse2["wing"] -= 2;
	// Printing the observation log of horse
	horse.PrintLog();
	// Printing the status of horse
	horse.PrintStatus();

	Diary::NewDay("4320");
	// Printing the observation log of horse2
	horse2.PrintLog();
	// Printing the status of horse2
	horse2.PrintStatus();

	Diary::NewDay("5500OwO");

	// Additional observations
	cout << "----------------------\n";
	Diary::NewDay("0-0");
	Diary::NewDay("0-1");
	// Creating a new Creature object named Worm
	Creature Worm("Worm");

	Diary::NewDay("0-2");
	// Creating a new Creature object named Snake based on Worm
	Creature Snake("Snake", Worm);
	// Printing the status of Snake
	Snake.PrintStatus();

	Diary::NewDay("1-1");
	// Assigning values to the "tail" body parts of Worm and Snake
	Worm["tail"] = 2;
	Snake["tail"] = 1;
	Snake["head"] = 1;
	// Printing the observation log of Snake
	Snake.PrintLog();

	Diary::NewDay("1-2");
	// Creating a new Creature object named Mul based on Snake
	Creature Mul("Multi-headed", Snake);
	// Adding 7 to the "head" and subtracting -7 from the "tail" body parts of Mul
	Mul["head"] += 7;
	Mul["tail"] -= -7;
	// Adding -1 to the "tail" body part of Worm
	Worm["tail"] -= -1;

	Diary::NewDay("1-3");
	// Adding -1 to the "tail" body part of Worm
	Worm["tail"] += -1;

	Diary::NewDay("1-4");
	// Resetting the "tail" body part count of Worm to 0
	Worm["tail"] = 0;

	Diary::NewDay("2-1");
	// Printing the observation log and status of Worm
	Worm.PrintLog();
	Worm.PrintStatus();
	// Printing the observation log and status of Mul
	Mul.PrintLog();
	Mul.PrintStatus();

	Diary::NewDay("???-1");
	// Assigning values to new body parts for Snake
	Snake["hammer?"] = 1;
	Snake["OwO"] = 0;
	// Printing the observation log and status of Snake
	Snake.PrintLog();
	Snake.PrintStatus();
}
