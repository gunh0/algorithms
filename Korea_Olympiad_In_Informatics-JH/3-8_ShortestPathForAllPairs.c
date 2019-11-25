/*
그래프에서 i<>j인 모든 정점의 연결 Vi와 Vj간의 최단 경로를
출력하는 프로그램을 작성하시오.
*/

#include <stdio.h>
#define MAX 1000

int cost[4][4] = { {0,50,10,MAX},{MAX,0,15,MAX},{20,MAX,0,15},{MAX,20,MAX,0} };
int via[4][4];	// 경유하는 정점
int n = 4;	// 정점의 개수

void print_via(int i, int j)
{
	int k;

	k = via[i][j];
	if (via[i][k] != -1)
		print_via(i, k);
	printf("V%d", k);
}

int main()
{
	int i, j, k;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			via[i][j] = -1;	// 경유하는 정점이 없는 경우
	}

	for (k = 0; k < n; k++)
	{
		for (i = 0; i < n; i++)
		{
			if (k != i)
			{
				for (j = 0; j < n; j++)
				{
					if (cost[i][k] + cost[k][j] < cost[i][j])
					{
						cost[i][j] = cost[i][k] + cost[k][j];
						via[i][j] = k;
					}
				}
			}
		}
	}

	// 출력
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i != j && cost[i][j] != MAX) {
				printf("V%d", i);
				if (via[i][j] != -1)
					print_via(i, j);
				printf("V%d %d\n", j, cost[i][j]);
			}
			else if (cost[i][j] == MAX)
				printf("V%d V%d access impossible", i, j);
		}
		printf("\n");
	}
	
	return 0;
}