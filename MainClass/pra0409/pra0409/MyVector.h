#pragma once
#include <iostream>
using namespace std;

class MyVector
{
public:
	MyVector()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	MyVector(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	MyVector(const MyVector& copy)
	{
		this->x = copy.x;
		this->y = copy.y;
		this->z = copy.z;
	}

	friend MyVector operator+(MyVector& a, MyVector& b) {
		MyVector result;
		result.setX(a.getX() + b.getX());
		result.setY(a.getY() + b.getY());
		result.setZ(a.getZ() + b.getZ());
		return result;
	}

	friend MyVector operator-(MyVector& a, MyVector& b) {
		MyVector result;
		result.setX(a.getX() - b.getX());
		result.setY(a.getY() - b.getY());
		result.setZ(a.getZ() - b.getZ());
		return result;
	}

	friend MyVector operator-(MyVector& a) {
		MyVector result;
		result.setX(a.getX() * -1);
		result.setY(a.getY() * -1);
		result.setZ(a.getZ() * -1);
		return result;
	}

	friend bool operator==(MyVector& a, MyVector& b) {
		if (a.getX() == b.getX() && a.getY() == b.getY() && a.getZ() == b.getZ()) {
			return true;
		}

		return false;
	}

	friend bool operator!=(MyVector& a, MyVector& b) {
		if (a.getX() != b.getX() || a.getY() != b.getY() || a.getZ() != b.getZ()) {
			return true;
		}

		return false;
	}

	MyVector& operator=(MyVector a) {
		x = a.x;
		y = a.y;
		z = a.z;
		return *this;
	}

	friend MyVector operator*(MyVector& a, int input) {
		MyVector result;
		result.setX(a.getX() * input);
		result.setY(a.getY() * input);
		result.setZ(a.getZ() * input);
		return result;
	}

	friend MyVector operator*(int input, MyVector& a) {
		MyVector result;
		result.setX(a.getX() * input);
		result.setY(a.getY() * input);
		result.setZ(a.getZ() * input);
		return result;
	}

	friend MyVector operator*(MyVector& a, MyVector& b) {
		MyVector result;
		result.setX(a.getY() * b.getZ() - a.getZ() * b.getY());
		result.setY(a.getZ() * b.getX() - a.getX() * b.getZ());
		result.setZ(a.getX() * b.getY() - a.getY() * b.getX());
		return result;
	}

	friend ostream& operator<<(ostream& outputStream, MyVector& a) {
		outputStream << "(" << a.getX() << "," << a.getY() << "," << a.getZ() << ")";
		return outputStream;
	}

	friend istream& operator<<(istream& inputStream, MyVector& a) {
		int x, y, z;
		inputStream >> x >> y >> z;
		a.setX(x);
		a.setY(y);
		a.setZ(z);
		return inputStream;
	}

	friend int dot(MyVector& a, MyVector& b) {
		int res = 0;
		res += a.getX() * b.getX();
		res += a.getY() * b.getY();
		res += a.getZ() * b.getZ();
		return res;
	}

	void setX(double x) {
		this->x = x;
	}

	void setY(double y) {
		this->y = y;
	}

	void setZ(double z) {
		this->z = z;
	}

	double getX() {
		return x;
	}

	double getY() {
		return y;
	}

	double getZ() {
		return z;
	}


private:
	double x, y, z;
};
