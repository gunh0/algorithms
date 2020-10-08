#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int parent[1000001];
int n;

int do_find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = do_find(parent[x]);
}

void do_union(int x, int y) {
	int px = do_find(x);
	int py = do_find(y);

	if (px > py) parent[px] = py;
	else if (px < py) parent[py] = px;
}

int main() {

	int m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i <= n; i++) parent[i] = i;

	for (int i = 0; i < m; i++) {
		int op, x, y;
		scanf("%d %d %d", &op, &x, &y);

		if (op == 0) {
			// union x and y
			do_union(x, y);
		}
		else {
			// find
			if (do_find(x) == do_find(y)) printf("YES\n");
			else printf("NO\n");
		}
	}

	return 0;
}