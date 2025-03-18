#include <iostream>
#include <vector>
#include <string>
using namespace std;

string aOpreate(string num1, string nmu2);
string rOpreate(string num1);
string lOpreate(string num1);
int getSymbols(char input);
string toSymbols(int input);

int main() {
	int step = 0;
	cin >> step;

	cout << "COWCULATIONS OUTPUT\n";
	for (size_t i = 0; i < step; i++)
	{
		char operations[3] = { 0 };
		string num1, num2, checkAns;
		cin >> num1 >> num2;
		cin >> operations[0] >> operations[1] >> operations[2];
		cin >> checkAns;

		for (size_t j = 0; j < 3; j++)
		{
			switch (operations[j]) {
			case 'A':
				num2 = aOpreate(num1, num2);
				break;
			case 'R':
				num2 = rOpreate(num2);
				break;
			case 'L':
				num2 = lOpreate(num2);
				break;
			case 'N':
				break;
			}
			
		}

		for (size_t i = num2.length(); i < 8; i++)
		{
			num2.insert(0, "V");
		}
		
		if (num2 == checkAns) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
		//cout << "correct:" << num2 << "\n";
	}
	cout << "END OF OUTPUT";
}

string aOpreate(string num1, string num2) {
	string strRes;
	int carry = 0;
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());

	for (size_t i = 0; i < max(num1.length(),num2.length()); i++)
	{
		int a, b;

		if (num1.length() > i) {
			a = getSymbols(num1[i]);
		}
		else {
			a = 0;
		}

		if (num2.length() > i) {
			b = getSymbols(num2[i]);
		}
		else {
			b = 0;
		}

		int sum = a + b + carry;
		int res = sum % 4;
		carry = sum / 4;
		strRes += toSymbols(res);
	}

	if (carry != 0) {
		strRes += "U";
	}
	reverse(strRes.begin(), strRes.end());
	return strRes;
}

string rOpreate(string num1) {
	num1.erase(num1.length() - 1,1);
	num1.insert(0, "V");
	return num1;
}

string lOpreate(string num1) {
	num1 += "V";
	return num1;
}

int getSymbols(char input) {
	switch (input) {
	case 'V':
		return 0;
		break;
	case 'U':
		return 1;
		break;
	case 'C':
		return 2;
		break;
	case 'D':
		return 3;
		break;
	}

	return -1;
}

string toSymbols(int input) {

	switch (input) {
	case 0:
		return "V";
		break;
	case 1:
		return "U";
		break;
	case 2:
		return "C";
		break;
	case 3:
		return "D";
		break;
	}

	return "";
}
