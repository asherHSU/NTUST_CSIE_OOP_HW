/***********************************************************************
 * File: Template.h
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-05-15
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-05-15
 * Description: Header file for templated binary search functions.
***********************************************************************/
#pragma once
/*
 *  Intent: Perform iterative binary search on a sorted array to find a key.
 *  Pre: Takes a sorted array 'a', the first and last indices of the array, the key to search for,
 *       a boolean variable 'found' to indicate if the key is found, and an integer 'location' to store the index of the key if found.
 *  Post: Modifies 'found' to true if the key is found, and updates 'location' with the index of the key if found.
 */
template<class T>
void ItrBinarySearch(const T a[], int first, int last, T key, bool& found, int& location) {
	while (first <= last)
	{
		location = (first + last) / 2;// Calculate the midpoint.

		if (a[location] == key) {//set found to true and return if match target
			found = true;
			return;
		}
		else if (a[location] < key) {// If key is greater than the midpoint, search the right half.
			first = location + 1;
		}
		else {// If key is smaller than the midpoint, search the left half.
			last = location - 1;
		}
	}

	found = false;// If key is not found, set found to false.
}

/*
 *  Intent: Perform recursive binary search on a sorted array to find a key.
 *  Pre: Takes a sorted array 'a', the first and last indices of the array, the key to search for,
 *       a boolean variable 'found' to indicate if the key is found, and an integer 'location' to store the index of the key if found.
 *  Post: Modifies 'found' to true if the key is found, and updates 'location' with the index of the key if found.
 */
template<class T>
void RecBinarySearch(const T a[], int first, int last, T key, bool& found, int& location) {
	if (first > last) { //If first is greater than last, key is not found.
		found = false;
		return;
	}

	location = (first + last) / 2; // Calculate the midpoint.

	if (a[location] == key) {//set found to true and return if match target
		found = true;
		return;
	}
	else if (a[location] < key) {// If key is greater than the midpoint, search the right half.
		RecBinarySearch(a, location + 1, last, key, found, location);
	}
	else {// If key is smaller than the midpoint, search the left half.
		RecBinarySearch(a,first, location - 1, key, found, location);
	}
}
