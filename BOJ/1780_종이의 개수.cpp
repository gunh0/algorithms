#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int n;
int board[2500][2500];
int ans[3];

void solve(int, int, int);

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &board[i][j]);
		}
	}

	solve(0, 0, n);
	for (int i = 0; i < 3; ++i) printf("%d\n", ans[i]);

	return 0;
}

void solve(int x, int y, int cur)
{
	int first = board[x][y];
	bool isallsame = true;
	for (int i = x; i < x + cur; ++i) {
		for (int j = y; j < y + cur; ++j) {
			if (first != board[i][j]) {
				isallsame = false;
				break;
			}
		}
		if (!isallsame)break;
	}
	if (isallsame) {
		ans[first + 1]++;
		return;
	}
	int k = cur / 3;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			solve(x + i * k, y + j * k, k);
		}
	}
}
