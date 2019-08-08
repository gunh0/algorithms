#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a[10001] = { 0, };
	int num = 0, input=0;
	int max = 0;

	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> input;
		if (input > max) max = input;
		a[input]++;
	}

	for (int i = 1; i <= max; i++)
	{
		if (a[i] != 0)
		{
			for (int j = 1; j <= a[i]; j++)
				cout << i << '\n';
		}
	}

	return 0;
}