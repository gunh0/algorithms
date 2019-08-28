#include <iostream>
#include <string>

using namespace std;

int main()
{
	int t = 0, score = 0;
	string str;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> str;
		int val = 1;
		score = 0;
		if (str[0] == 'O') score += val;
		for (int j = 1; j<str.length(); j++)
		{
			if (str[j] == 'O')
			{
				if (str[j - 1] == 'O')
				{
					val += 1;
					score += val;
				}
				else score += val;
			}
			else val = 1;
		}
		cout << score << endl;;
	}
	return 0;
}