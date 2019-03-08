#include <stdio.h>
int guestNum[5] = { 1, 2, 3, 4, 5 };
int serviceTime[5] = { 1, 3, 2, 8, 5 };
int users = 5;

int sort()
{
	int i, j, tmp;

	for (i = 0; i < users - 1; i++)
	{
		for (j = i + 1; j < users; j++)
		{
			if (serviceTime[i]>serviceTime[j])
			{
				tmp = serviceTime[i];
				serviceTime[i] = serviceTime[j];
				serviceTime[j] = tmp;

				tmp = guestNum[i];
				guestNum[i] = guestNum[j];
				guestNum[j] = tmp;
			}
		}
	}
}

int main(){
	int totalTime = 0;
	int i = 0, j = 0;

	sort();

	for (i = 0; i < users; i++)
	{
		for (j = 0; j <= i; j++)
		{
			totalTime += serviceTime[j];
		}
	}

	printf("%d\n", totalTime);
	for (i = 0; i < users; i++)
	{
		printf("%4d", guestNum[i]);
	}
	
	printf("\n");
	return 0;
}