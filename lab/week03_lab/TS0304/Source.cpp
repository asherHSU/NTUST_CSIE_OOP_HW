#include <iostream>
using namespace std;

int main() {
	long double maxVal = 0, resVal = 0, log2 = log10l(2);
	int years, bitsPower, res = 1;

	while (true)
	{
		maxVal = 0;
		resVal = 0;
		res = 1;
		
		cin >> years;
		if (cin.eof()) break;
		bitsPower = pow(2, 2 + (years - 1900) / 10);
		
		for (int i = 0; i < bitsPower; i++) {
			maxVal += log2;
		}

		
		while (resVal <= maxVal)
		{
			res++;
			resVal += log10l(res);
			//cout << res << " " << maxVal << "\n";
		}

		res--;
		cout << res << "\n";
	}

}
