#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

struct map {
	int x, y, w;
};

int n, m;
char a[1001][1001];
int dist[1001][1001][2];
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };

int bfs() {
	queue<map> q;
	q.push({ 0, 0, 0 });
	dist[0][0][0] = 1;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, w = q.front().w;
		q.pop();
		if (x == n - 1 && y == m - 1) return dist[x][y][w];
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[nx][ny][w]) continue;
			if (a[nx][ny] == '0') {
				dist[nx][ny][w] = dist[x][y][w] + 1;
				q.push({ nx, ny, w });
			}
			if (a[nx][ny] == '1' && w == 0) {
				dist[nx][ny][1] = dist[x][y][w] + 1;
				q.push({ nx, ny, 1 });
			}
		}
	}
	return -1;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%s", a[i]);
	printf("%d\n", bfs());
	return 0;
}