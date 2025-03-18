#include <iostream>
#include <string>
#include <vector>
using namespace std;

string sum(string a, string b, bool maskCarry);
string diff(string a, string b);
string product(string a, string b);
bool checkStrB(string strB);

int main() {
	string a, b;

	while (true)
	{
		cin >> a >> b;

		if (cin.eof()) {
			break;
		}

		cout << sum(a, b, false) << "\n";
		cout << diff(a, b) << "\n";
		cout << product(a, b) << "..\n";
	}
}

string sum(string strA, string strB, bool isInverse) {
	string strRes;
	vector<int> result;
	reverse(strA.begin(), strA.end());
	reverse(strB.begin(), strB.end());

	int sum = 0, carry = 0, res = 0, a = 0, b = 0;

	for (size_t i = 0; i < max(strA.length(), strB.length()); i++)
	{
		if (i < strA.length()) {
			a = strA[i] - '0';
		}
		else {
			a = 0;
		}

		if (i < strB.length()) {
			b = strB[i] - '0';
		}
		else if (isInverse == true) {
			b = 9;
		}
		else {
			b = 0;
		}

		sum = a + b + carry;
		carry = sum / 10;
		res = sum % 10;
		result.push_back(res);
	}

	if (carry == 1 && isInverse == false) {
		result.push_back(1);
	}

	if (carry == 1 && isInverse == true) {
		result[0]++;
	}

	reverse(result.begin(), result.end());


	bool hearderZero = true;
	for (size_t i = 0; i < result.size(); i++)
	{
		if (hearderZero == true && result[i] == 0) {
			continue;
		}
		else if (hearderZero == true && result[i] != 0) {
			hearderZero = false;
		}
		strRes += result[i] + '0';
	}


	return strRes;
}

string diff(string strA, string strB) {
	reverse(strB.begin(), strB.end());

	for (size_t i = 0; i < strB.length(); i++)
	{

		int temp = strB[i] - '0';
		temp = abs(9 - temp);
		strB[i] = temp + '0';

	}

	reverse(strB.begin(), strB.end());
	return sum(strA, strB, true);
}

string product(string strA, string strB) {
	string res;

	
	return res;
}

bool checkStrB(string strB) {
	if (strB[strB.length() - 1] != '1') {
		return false;
	}

	for (size_t i = 0; i < strB.length() - 1; i++)
	{
		if (strB[i] != '0') {
			return false;
		}
	}

	return true;
}
