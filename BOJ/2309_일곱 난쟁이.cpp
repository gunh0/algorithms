#include<iostream>
#include<algorithm>
#define MAX 987654321

using namespace std;

int arr[10];
int n, result = 0;

bool check = false;

int main()
{
	for (int i = 1; i <= 9; i++)
	{
		cin >> arr[i];
		result += arr[i];
	}

	for (int i = 1; i <= 9; i++)
	{
		for (int j = i + 1; j <= 9; j++)
		{
			if ((result - arr[i] - arr[j]) == 100)
			{
				arr[i] = MAX;
				arr[j] = MAX;
				check = true;
				break;
			}
		}

		if (check)
			break;
	}

	sort(arr, arr + 10);

	for (int i = 1; i <= 7; i++)
	{
		if (arr[i] != MAX)
			cout << arr[i] << endl;
	}

	return 0;
}