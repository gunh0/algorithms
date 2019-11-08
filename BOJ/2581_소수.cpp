#include <iostream>
using namespace std;

int main()
{
	int max, min;
	int count = 0;
	int nCount = 0;
	int result = 0, minNumber;

	cin >> min;
	cin >> max;

	for (int i = min; i <= max; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (i % j == 0)
				count++;
		}

		if (count == 2)
		{
			nCount++;
			result += i;

			if (nCount == 1)
				minNumber = i;
		}
		count = 0;
	}

	if (nCount == 0)
	{
		minNumber = -1;
		cout << minNumber << endl;
	}
	else
	{
		cout << result << endl << minNumber << endl;
	}

	return 0;
}