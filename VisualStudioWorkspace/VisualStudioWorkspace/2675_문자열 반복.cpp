#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T = 0, rep = 0;;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> rep;
		string input;
		for (int x = 0; x < input.length(); x++)
		{
			for (int y = 0; y < rep; y++)
				cout << input[x];
		}
	}

	return 0;
}