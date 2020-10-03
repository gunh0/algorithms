#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, c, s[500001], e[500001], lazy[2000000], seg[2000000], x, y, a[500001];
vector<vector<int>> vt;
char f;

void dfs(int here) {
	s[here] = ++c;
	for (auto next : vt[here])
		if (!s[next])
			dfs(next);
	e[here] = c;
}

void u_lazy(int node, int x, int y) {
	if (!lazy[node])
		return;
	seg[node] += lazy[node] * (y - x + 1);
	if (x != y) {
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}

int update(int lo, int hi, int val, int node, int x, int y) {
	u_lazy(node, x, y);
	if (y < lo || hi < x)
		return seg[node];
	if (lo <= x && y <= hi) {
		lazy[node] += val;
		u_lazy(node, x, y);
		return seg[node];
	}
	int mid = (x + y) >> 1;
	return seg[node] = update(lo, hi, val, node * 2, x, mid) + update(lo, hi, val, node * 2 + 1, mid + 1, y);
}

int query(int lo, int hi, int node, int x, int y) {
	u_lazy(node, x, y);
	if (y < lo || hi < x)
		return 0;
	if (lo <= x && y <= hi)
		return seg[node];
	int mid = (x + y) >> 1;
	return query(lo, hi, node * 2, x, mid) + query(lo, hi, node * 2 + 1, mid + 1, y);
}

int main() {
	scanf("%d%d", &n, &m);
	vt.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (i != 1) {
			scanf("%d", &x);
			vt[x].push_back(i);
		}
	}
	dfs(1);
	for (int i = 1; i <= n; i++)
		update(s[i], s[i], a[i], 1, 1, n);
	for (int i = 0; i < m; i++) {
		getchar();
		scanf("%c", &f);
		if (f == 'p') {
			scanf("%d%d", &x, &y);
			if (s[x] == e[x])continue;
			update(s[x] + 1, e[x], y, 1, 1, n);
		}
		else {
			scanf("%d", &x);
			printf("%d\n", query(s[x], s[x], 1, 1, n));
		}
	}
	return 0;
}