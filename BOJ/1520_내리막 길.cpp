#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;
int n, m;
int input[501][501];
int dp[501][501];   //값 저장 메모장
int a[4] = { 1, 0, -1, 0 };
int b[4] = { 0, 1, 0, -1 };

int dfs(int x, int y)
{
	if (dp[x][y] != -1) return dp[x][y];
	if (x < 0 || x >= n || y < 0 || y >= m) return 0;   //범위 벗어난 경우, 0리턴
	if (x == 0 && y == 0) return 1;

	dp[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		int nextX = x + a[i];
		int nextY = y + b[i];   //상하좌우 이동

		if (input[nextX][nextY] > input[x][y])
			dp[x][y] += dfs(nextX, nextY);
	}

	return dp[x][y];
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &input[i][j]);

	memset(dp, -1, sizeof(dp));

	printf("%d", dfs(n - 1, m - 1));

	return 0;
}
