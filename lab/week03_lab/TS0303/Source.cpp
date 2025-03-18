#include <iostream>
using namespace std;

int main() {
	long double x;
	int strWidth, decmialNum;
	char c;


	while (true)
	{
		cin >> x;
		cin >> strWidth;
		cin >> decmialNum;
		cin >> c;
		if (cin.eof()) break;

		cout.setf(ios::fixed, ios::floatfield);
		cout.width(strWidth);
		cout.fill(c);
		cout.precision(decmialNum);
		x *= pow(10, decmialNum);
		x = trunc(x) / pow(10, decmialNum);
		cout << (long double)x << "\n";
	}

	//cout << x << " "<< strWidth << " " << decmialNum << " " << c;

}
