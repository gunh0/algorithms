#include <iostream>

using namespace std;

int main()
{
	int input = 0;
	cin >> input;
	int stick = 64, sum=0, cnt=0;
	while (input > 0)
	{
		if (stick > input) stick /= 2;
		else
		{
			cnt++;
			input -= stick;
		}
	}

	cout << cnt << endl;

	return 0;
}