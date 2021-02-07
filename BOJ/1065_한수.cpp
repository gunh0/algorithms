#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int num = 0, hansu = 0;
	cin >> num;

	for (int i = 1; i <= num; i++)
	{
		if (i < 100)
			hansu = i;
		else if (i == 1000)
			break;
		else
		{
			int digit = 0, tmp = i;
			vector<int> numArr(3);
			while (tmp > 0)
			{
				numArr[digit] = tmp % 10;
				tmp /= 10;
				digit++;
			}
			if (numArr[0] - numArr[1] == numArr[1] - numArr[2])
				hansu++;
		}
	}

	cout << hansu << endl;
	return 0;
}