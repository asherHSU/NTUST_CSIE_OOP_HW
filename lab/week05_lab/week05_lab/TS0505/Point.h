/***********************************************************************
 * File: Point.h
 * Author: ¶À®x½n (B11215054, 0978wally@gmail.com)
 * Create Date: 2024-03-21
 * Editor: ¶À®x½n (B11215054, 0978wally@gmail.com)
 * Update Date: 2024-03-21
 * Description: Declaration of the Point class, represents a point in 2D space.
***********************************************************************/
#pragma once
class Point
{
public:
	/* Intent: Default constructor for the Point class.
	 * Pre: None.
	 * Post: Initializes the point to (0,0).
	 */
	Point()
	{
		this->x = 0;
		this->y = 0;
	}

	/* Intent: Destructor for the Point class.
	 * Pre: None.
	 * Post: Frees up any dynamically allocated resources (currently unused).
	 */
	~Point()
	{
		//delete& x;
		//delete& y;
	}

	/* Intent: Sets the coordinates of the point.
	 * Pre: float number x, y.
	 * Post: Updates the x and y coordinates of the point.
	 */
	void Set(float x, float y) {
		this->x = x;
		this->y = y;
	}

	/* Intent: Moves the point by the specified offsets.
	 * Pre: float number x, y.
	 * Post: Adjusts the x and y coordinates of the point by adding the input offsets.
	 */
	void Move(float x, float y) {
		this->x += x;
		this->y += y;
	}

	/* Intent: Rotates the point by 90 degrees clockwise.
	 * Pre: None.
	 * Post: Rotates the point's coordinates by swapping them and applying a sign change to one of them.
	 */
	void Rotate() {
		float temp = y;

		if (x != 0) { //if value is 0, doesn't need change (prevent -0)
			y = x * -1;
		}
		else {
			y = x;
		}

		x = temp;
	}

	/* Intent: Reflects the point about the origin.
	 * Pre: None.
	 * Post: Applies a sign change to both x and y coordinates, effectively reflecting the point about the origin.
	 */
	void Reflect() {
		if (x != 0) { //if value is 0, doesn't need change (prevent -0)
			x *= -1;
		}

		if (y != 0) { //if value is 0, doesn't need change (prevent -0)
			y *= -1;
		}

	}

	/* Intent: Retrieves the horizontal coordinate of the point.
	 * Pre: None.
	 * Post: Returns the horizontal coordinate (x) of the point.
	 */
	float GetHorizontal() const { return x; }

	/* Intent: Retrieves the vertical coordinate of the point.
	 * Pre: None.
	 * Post: Returns the vertical coordinate (y) of the point.
	 */
	float GetVertical() const { return y; }

private:
	float x, y;
};
