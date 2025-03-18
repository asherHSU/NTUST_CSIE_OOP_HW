#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> input;

	while (true)
	{
		char getInput = getc(stdin);

		if (getInput == EOF) {
			break;
		}

		if (isdigit(getInput)) {
			input.push_back(getInput - '0');
		}

		if (getInput == '\n') {
			for (size_t i = 0; i < 3; i++)
			{
				for (size_t j = 0; j < input.size(); j++)
				{
					switch (i)
					{
					case 0:
						switch (input[j])
						{
						case 1:
							cout << "   ";
							break;
						case 4:
							cout << "   ";
							break;
						default:
							if (j == input.size() - 1) {
								cout << " _ ";
							}
							else {
								cout << " _ ";
							}

							break;
						}
						break;

					case 1:
						switch (input[j])
						{
						case 1:
							cout << "  |";
							break;

						case 2:
						case 3:
							cout << " _|";
							break;

						case 7:
							cout << "  |";
							break;

						case 5:
						case 6:
							cout << "|_ ";
							break;

						case 4:
						case 8:
						case 9:
							cout << "|_|";
							break;

						case 0:
							cout << "| |";
							break;
						default:
							break;
						}
						break;

					case 2:
						switch (input[j])
						{
						case 1:
							cout << "  |";
							break;
						case 2:
							cout << "|_ ";
							break;
						case 3:
						case 5:
						case 9:
							cout << " _|";
							break;

						case 6:
						case 8:
						case 0:
							cout << "|_|";
							break;

						case 4:
						case 7:
							cout << "  |";
							break;
						}
						break;
					}
				}
				cout << "\n";
			}
			input.clear();
		}
	}
}
