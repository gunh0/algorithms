#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct chess {
	int x, y;
};

int n, sx, sy, ex, ey;
int d[300][300];
const int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
const int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

void bfs() {
	queue<chess> q;
	q.push({ sx, sy });
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y; q.pop();
		if (x == ex && y == ey) {
			printf("%d\n", d[x][y]);
			return;
		}
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (d[nx][ny]) continue;
			d[nx][ny] = d[x][y] + 1;
			q.push({ nx, ny });
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		scanf("%d %d", &sx, &sy);
		scanf("%d %d", &ex, &ey);
		memset(d, 0, sizeof(d));
		bfs();
	}
	return 0;
}