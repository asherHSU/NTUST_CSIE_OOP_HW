#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string input;
	bool isFirst = true;

	while (1)
	{
		cin >> input;
		//cout << input << "//";
		unsigned long long int strlen = input.length();
		unsigned long long int colLen = lroundf(sqrt(strlen));
		unsigned long long int rowLen = ceil((double)strlen / colLen);
		//cout << colLen << " " << rowLen << "\n";

		for (size_t i = 0; i < rowLen; i++)
		{
			if (i != 0) cout << "\n";
			for (size_t j = 0, cursor = i; j < colLen; j++)
			{
				if (cursor >= strlen) continue;
				cout << input[cursor];
				cursor += std::max((int)rowLen, (int)colLen);
			}

		}

		if (cin.eof()) break;
		else cout << "\n";
	}

}


