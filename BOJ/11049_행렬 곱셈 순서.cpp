#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <algorithm>

using namespace std;

struct mat {
	int r, c;
};
mat m[501];

int dp[501][501];
int n, i;

int func(int x, int y) {
	if (x == y)
		return 0;

	int& ref = dp[x][y];
	if (ref != -1)
		return ref;

	int mm = INT_MAX;

	for (int k = x; k < y; ++k)
		mm = min(mm, func(x, k) + func(k + 1, y) + m[x].r * m[k].c * m[y].c);

	return ref = mm;
}

int main() {
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%d %d", &m[i].r, &m[i].c);

	memset(dp, -1, sizeof(dp));

	printf("%d", func(0, n - 1));
	return 0;
}