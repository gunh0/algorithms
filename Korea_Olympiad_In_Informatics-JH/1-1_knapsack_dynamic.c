#include <stdio.h>
#include <stdlib.h>

void main()
{
	int s[5] = { 3, 4, 7, 8, 9 }; // Weight
	int v[5] = { 4, 5, 10, 11, 13 }; // Value

	int cost[18];
	int best[18];

	int i, j;
	int sackw;

	system("cls");
	sackw = 17;

	//Reset
	for (i = 0; i <= sackw; i++)
	{
		cost[i] = 0;
		best[i] = -1;
	}

	for (j = 0; j<5; j++) // Apply the stuff from A to E
	{
		for (i = 1; i <= sackw; i++) // Weight change 1-17
		{
			if (i >= s[j])
			{
				if (cost[i]<cost[i - s[j]] + v[j])
				{
					cost[i] = cost[i - s[j]] + v[j];
					best[i] = j;
				}
			}
		}
	}

	i = sackw; // Print result
	do
	{
		printf("%d ", s[best[i]]);
		i -= s[best[i]];
	} while (i>0);

	printf("\nThe Maximum Value is %d.\n", cost[sackw]);
}