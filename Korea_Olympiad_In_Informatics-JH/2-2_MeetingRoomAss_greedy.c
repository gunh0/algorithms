#include <stdio.h>

int roomNum[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int start[9] = { 3, 1, 2, 5, 5, 0, 8, 8, 12 };
int finish[9] = { 5, 4, 13, 9, 7, 6, 11, 12, 14 };
int n = 9;

int sort(){
	int i = 0, j = 0, temp = 0;

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j<n; j++)
		{
			if (finish[i]>finish[j])
			{
				temp = finish[i];
				finish[i] = finish[j];
				finish[j] = temp;

				temp = start[i];
				start[i] = start[j];
				start[j] = temp;

				temp = roomNum[i];
				roomNum[i] = roomNum[j];
				roomNum[j] = temp;
			}
		}
	}

	return 0;
}

int main(){
	int timeTable[9];
	int count = 0, last = 0, i = 0, j = 0;

	sort();

	count = 1;
	last = 0;
	i = 0;
	timeTable[i++] = roomNum[last];

	for (j = 1; j < n; j++)
	{
		if (start[j] >= finish[last]){
			count++;
			last = j;
			timeTable[i++] = roomNum[last];
		}
	}

	printf("%d\n", count);
	for (j = 0; j < i; j++)
		printf("%d  ", timeTable[j]);

	return 0;
}
