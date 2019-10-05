#include <iostream>
using namespace std;

int main()
{
	int n, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		bool alphabet[26] = { 0, }, overlap = false;
		string input;
		int aryNum;
		cin >> input;
		for (int j = 0; input[j]; j++)
		{
			if (input[j] <= 'Z') aryNum = input[j] - 'A';
			else aryNum = input[j] - 'a';

			if (alphabet[aryNum])
			{
				if (input[j - 1] != input[j])	// check before(input[j-1]) & now(input[j])
				{
					overlap = true;
					break;
				}
			}
			else
				alphabet[aryNum] = true;
		}
		if (!overlap) cnt++;	// is group word
	}

	cout << cnt << endl;
	return 0;
}
