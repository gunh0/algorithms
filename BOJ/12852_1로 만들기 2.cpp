#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000002];
int DP[1000002] = { 0,0,1,1 };
int trace[1000002] = { 0, 0, 1, 1 };

int main()
{
	int n;
	int a, b, c, d, e, f;
	int empty = 100;
	scanf("%d", &n);

	for (int i = 4; i <= n; i++)
	{
		a = empty; b = empty; c = empty; d = empty; e = empty;

		if ((i - 1) % 3 == 0)
			a = DP[(i - 1) / 3] + 2;

		if (i % 6 == 0)
			b = DP[i / 3] + 1;

		if (i % 2 == 0)
			c = DP[i / 2] + 1;

		if (i % 3 == 0)
			d = DP[i / 3] + 1;

		e = min({ DP[i - 1] + 1, DP[i - 2] + 2, DP[(i - 1) / 2] + 2, empty, empty });

		DP[i] = min({ a, b, c, d, e });

		if (DP[i] == a)
		{
			trace[i] = (i - 1);
			trace[i - 1] = (i - 1) / 3;
		}
		else if (DP[i] == b)
			trace[i] = i / 3;
		else if (DP[i] == c)
			trace[i] = i / 2;
		else if (DP[i] == d)
			trace[i] = i / 3;
		else if (DP[i] == e)
		{
			if (e == DP[i - 1] + 1)
				trace[i] = i - 1;
			else if (e == DP[i - 2] + 2)
			{
				trace[i] = i - 1;
				trace[i - 1] = i - 2;
			}
			else
			{
				trace[i] = (i - 1);
				trace[i - 1] = (i - 1) / 2;
			}
		}
	}
	printf("%d\n", DP[n]);

	while (n != 1)
	{
		printf("%d ", n);
		n = trace[n];
	}
	printf("1");

	return 0;
}
