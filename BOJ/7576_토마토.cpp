#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

struct tomato {
	int x, y;
};

int m, n, ans;
int a[1001][1001];
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };
queue<tomato> q;

void bfs() {
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (a[nx][ny]) continue;
			a[nx][ny] = a[x][y] + 1;
			q.push({ nx, ny });
		}
	}
}

int main() {
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j] == 1) {
				q.push({ i, j });
			}
		}
	}
	bfs();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) {
				printf("-1\n");
				return 0;
			}
			if (ans < a[i][j]) ans = a[i][j];
		}
	}
	printf("%d\n", ans - 1);
	return 0;
}
