#include <iostream>
#include "MyVector.h"
using namespace std;

int main() {
	MyVector v1(1, 2, 3), v2(4, 5, 6);
	MyVector res;
	res = v1 + v2; //+
	cout << "add: " << res << "\n";

	res = v1 - v2; //-
	cout << "reduce:" << res << "\n";
	
	v1 = -v1; //minus
	v2 = -v2;
	cout << "minus v1:" << v1 << "\n";
	cout << "minus v2:" << v2 << "\n";

	if (v1 != v2) { //!=
		cout << "v1 != v2\n";
	}

	v1 = MyVector(2, 2, 2);
	v2 = MyVector(2, 2, 2);

	if (v1 == v2) { //==
		cout << "v1 == v2\n";
	}

	v1 = v1 * 3; //*
	v2 = v2 * 5;
	cout << "v1*3:" << v1 << "\n";
	cout << "v2*5:" << v2 << "\n";

	cout << "dot:" << dot(v1, v2) << "\n"; //dot

	v1 = MyVector(5, 4, 3);
	v2 = MyVector(4, 5, 6);
	res = v1 * v2;
	cout << "cross:" << res << "\n";
}