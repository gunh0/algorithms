/*
주어진 행렬의 곱셈의 횟수가 가장 적게 되도록
행렬을 곱하는 조합을 출력하는 프로그램을 작성
*/

#include <stdio.h>

#define INT_MAX 1000

int cost[7][7];
int best[7][7];
char name[7] = { ' ','A','B','C','D','E','F' };	// 행렬의 이름
int r[8] = { 0,4,2,3,1,2,2,3 };	// 행렬의 크기 즉, A행렬은 4X2, B의 행렬은 2X3 ...

int n = 6;	// 행렬의 갯수

void dynamic() {
	int i = 0, j = 0, k = 0, t = 0;
	for (i = 0; i <= n; i++)
	{
		for (j = i + 1; j <= n; j++)
		{
			cost[i][j] = INT_MAX;
		}
	}

	for (i = 1; i <= n; i++)
	{
		cost[i][i] = 0;
	}

	for (j = 1; j < n; j++)
	{
		for (i = 1; i <= n - j; i++)
		{
			for (k = i + 1; k <= i + j; k++)	// k : 두 번째 그룹의 위치
			{
				t = cost[i][k - 1] + cost[k][i + j] + r[i] * r[k] * r[i + j + 1];
				if (t < cost[i][i + j])
				{
					cost[i][i + j] = t;
					best[i][i + j] = k;
				}
			}
		}
	}

}

void order(int i, int j)
{
	if (i == j) printf("%c", name[i]);
	else
	{
		printf("(");
		order(i, best[i][j] - 1);
		order(best[i][j], j);
		printf(")");
	}
}

int main()
{
	dynamic();
	order(1, n);
	return 0;
}