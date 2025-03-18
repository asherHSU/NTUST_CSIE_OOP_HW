#include <string>
using namespace std;

class Atoi {

private:
	string beTrans;

public:
	Atoi() {
		beTrans = "";
	}

	Atoi(string s) {
		beTrans = s;
	}

	void SetString(string s) {
		beTrans = s;
	}

	const string GetString() {
		return beTrans;
	}

	int Length() {
		if (beTrans[0] == '-') {
			return beTrans.length() - 1;
		}
		return beTrans.length();
	}

	bool IsDigital() {
		bool res = true;

		for (size_t i = 0; i < beTrans.length(); i++)
		{
			if (beTrans[i] == '-') {
				continue;
			}

			if (isdigit(beTrans[i]) == false) {
				res = false;
				break;
			}
		}
		return res;
	}

	int StringToInteger() {
		int res = 0;

		for (size_t i = 0; i < beTrans.length(); i++)
		{
			if (beTrans[i] == '-') {
				continue;
			}

			res *= 10;
			res += beTrans[i] - '0';
		}

		if (beTrans[0] == '-') {
			res *= -1;
		}
		return res;
	}

};