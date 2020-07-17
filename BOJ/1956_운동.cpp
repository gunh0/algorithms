#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>

using namespace std;
const int MAX = 401;
const int INF = 1e9;
int n, m;
int graph[MAX][MAX];

void print() {
	int _min = INF;
	for (int i = 1; i <= n; i++) {
		if (_min > graph[i][i]) _min = graph[i][i];
	}
	if (_min != INF) printf("%d\n", _min);
	else printf("-1\n");
}

void solve_fw() {
	for (int i = 1; i <= n; i++) {
		for (int v = 1; v <= n; v++) {
			if (v == i) continue;
			for (int nv = 1; nv <= n; nv++) {
				if (nv == i) continue;
				if (graph[v][nv] > graph[v][i] + graph[i][nv]) {
					graph[v][nv] = graph[v][i] + graph[i][nv];
				}
			}
		}
	}
	print();
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			graph[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (graph[a][b] > c) graph[a][b] = c;
	}
	solve_fw();
	return 0;
}