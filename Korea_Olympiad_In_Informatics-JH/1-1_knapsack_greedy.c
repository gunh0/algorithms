#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// The initial value
int sackw = 17;
int s[5] = { 3, 4, 7, 8, 9 }; // Weight
int v[5] = { 4, 5, 10, 11, 13 }; // Value
float r[5] = { 0, 0, 0, 0, 0 }; // Worth
int include[5] = { 0, 0, 0, 0, 0 }; // A variable for storing

int show();
int sort();
int greedy(int sackw);
int result();

int main()
{
	system("cls");

	show();
	sort();

	printf("\nPlease enter the weight of the sack (Max=43) : ");
	printf("%d\n", sackw);
	greedy(sackw);

	result();

	return 0;
}

int show()
{
	printf("\t\tA   B   C   D   E\n");
	printf("The Weight : ");
	for (int i = 0; i<5; i++)
		printf("%4d", s[i]);

	printf("\nThe Value  : ");
	for (int i = 0; i<5; i++)
		printf("%4d", v[i]);

	printf("\n");
	return 0;
}

int sort()
{
	float temp;
	int i, j;

	// The ratio of the value of the weight
	// A[4/3] B[5/4] C[10/7] D[11/8] E[13/9]
	for (i = 0; i<5; i++)
		r[i] = (float)v[i] / (float)s[i];

	for (i = 0; i<4; i++)
	{
		for (j = i + 1; j<5; j++)
		{
			if (r[i]<r[j])
			{
				// Worth
				temp = (float)r[i];
				r[i] = r[j];
				r[j] = temp;

				// Weight
				temp = (float)s[i];
				s[i] = s[j];
				s[j] = (int)temp;

				// Value
				temp = (float)v[i];
				v[i] = v[j];
				v[j] = (int)temp;
			}
		}
	}

	return 0;
}

int greedy(int sackw)
{
	int w = 0;
	int i;

	for (i = 0; i<5; i++)
	{
		w += s[i];
		if (w <= sackw) include[i] = 1;
		else break;
	}

	return 0;
}

int result()
{
	int i = 0;
	int val = 0;

	printf("The weight of the bag you choose : ");
	while (include[i] == 1)
	{
		printf("%d ", s[i]); // Weight
		val += v[i];
		i++;
	}

	printf("\nThe Maximum Value is %d.\n", val);

	return 0;
}