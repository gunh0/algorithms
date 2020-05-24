#include <iostream>
#include <queue>

using namespace std;

int n, k, m;
int x, y, z, d, ans;
int a[100][100], t[101];
char c[101];
const int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };
const int L[] = { 3, 2, 0, 1 }, D[] = { 2, 3, 1, 0 };
queue<pair<int, int>> q;

void solve() {
	a[0][0] = 2;
	q.push({ 0, 0 });
	while (true) {
		x += dx[d], y += dy[d];
		ans++;
		if (x < 0 || x >= n || y < 0 || y >= n || a[x][y] == 2) {
			printf("%d\n", ans);
			return;
		}
		if (a[x][y] == 0) {
			int nx = q.front().first, ny = q.front().second; q.pop();
			a[nx][ny] = 0;
		}
		a[x][y] = 2;
		q.push({ x, y });
		if (ans == t[z]) {
			if (c[z] == 'L') d = L[d];
			else d = D[d];
			z++;
		}
	}
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int u, v;
		cin >> u >> v;
		a[u - 1][v - 1] = 1;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> t[i] >> c[i];
	}
	solve();

	return 0;
}