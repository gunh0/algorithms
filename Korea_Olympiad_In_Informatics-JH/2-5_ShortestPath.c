#include <stdio.h>

#define MAX 1000	// No way

int distance[6];
int found[6];
int via[6];
int n = 6;

int cost[6][6] = { {0,50,10,MAX,45,MAX},
{MAX,0,15,MAX,10,MAX},
{20,MAX,0,15,MAX,MAX},
{MAX,20,MAX,0,35,MAX},
{MAX,MAX,MAX,30,0,MAX},
{MAX,MAX,MAX,5,MAX,0} };

int select()
{
	int i, min, minpos;
	min = MAX;
	minpos = -1;
	for (i = 0; i < n; i++)
	{
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}

void print_via(int i)
{
	int j;
	j = via[i];
	if (via[j] != -1)
		print_via(j);
	printf("V%d ", j);
}

void print_result() {
	int i;
	for (i = 1; i < n; i++)
	{
		if (distance[i] != MAX && distance[i] != 0)
		{
			printf("%d : V0 ", distance[i]);
			if (via[i] != -1)
			{
				print_via(i);
			}
			printf("V%d \n", i);
		}
		else printf("V%d access impossible\n", i);
	}
}

int main()
{
	int i, j, x;
	for (i = 0; i < n; i++)
	{
		found[i] = 0;
		distance[i] = cost[0][i];
		via[i] = -1;
	}

	found[0] = 1;
	distance[0] = 0;
	for (i = 0; i < n - 1; i++)
	{
		x = select();
		found[x] = 1;
		for (j = 0; j < n; j++)
		{
			if (!found[j])
			{
				if (distance[x] + cost[x][j] < distance[j])
				{
					distance[j] = distance[x] + cost[x][j];
					via[j] = x;
				}
			}
		}	
	}

	print_result();
	return 0;
}