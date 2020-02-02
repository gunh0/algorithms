#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define INF 1987654321

using namespace std;

int dp[1001][1001], n, w, back[1001];
pair<int, int> d[1001];

int getdist(pair<int, int> a, pair<int, int> b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int func(int x, int y)
{
	if (x == w || y == w)
		return 0;
	int &ret = dp[x][y];
	if (ret != -1)
		return ret;
	int fir, sec;
	if (!x)
		fir = func(max(x, y) + 1, y) + getdist(d[max(x, y) + 1], {1, 1});
	else
		fir = func(max(x, y) + 1, y) + getdist(d[max(x, y) + 1], d[x]);
	if (!y)
		sec = func(x, max(x, y) + 1) + getdist(d[max(x, y) + 1], {n, n});
	else
		sec = func(x, max(x, y) + 1) + getdist(d[max(x, y) + 1], d[y]);
	return ret = min(fir, sec);
}

void solve(int x, int y)
{
	if (x == w || y == w)
		return;
	int fir, sec;
	if (!x)
		fir = func(max(x, y) + 1, y) + getdist(d[max(x, y) + 1], {1, 1});
	else
		fir = func(max(x, y) + 1, y) + getdist(d[max(x, y) + 1], d[x]);
	if (!y)
		sec = func(x, max(x, y) + 1) + getdist(d[max(x, y) + 1], {n, n});
	else
		sec = func(x, max(x, y) + 1) + getdist(d[max(x, y) + 1], d[y]);
	if (fir < sec)
	{
		back[max(x, y) + 1] = 1;
		solve(max(x, y) + 1, y);
	}
	else
	{
		back[max(x, y) + 1] = 2;
		solve(x, max(x, y) + 1);
	}
}

int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &n, &w);
	for (int i = 1; i <= w; i++)
		scanf("%d%d", &d[i].first, &d[i].second);
	printf("%d\n", func(0, 0));
	solve(0, 0);
	for (int i = 1; i <= w; i++)
		printf("%d\n", back[i]);
	return 0;
}