#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, u, v, V[50010];
char op;
vector<pair<int, int>> vp;
vector<vector<int>> node;

struct Union {
	vector<int> p, r;
	Union(int n) : p(n), r(n, 1) {
		for (int i = 0; i < n; ++i) {
			p[i] = i;
		}
	}
	int find(int u) {
		if (u == p[u]) {
			return u;
		}
		return p[u] = find(p[u]);
	}
	void merge(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) {
			return;
		}

		if (r[u] > r[v]) {
			swap(u, v);
		}
		p[u] = v;
		if (r[u] == r[v]) {
			++r[v];
		}
	}
};

bool findCycle(int here) {
	if (V[here]) {
		if (V[here] == -1) {
			return true;
		}
		return false;
	}

	V[here] = -1;
	for (int there : node[here]) {
		if (findCycle(there)) {
			return true;
		}
	}
	V[here] = 1;

	return false;
}

int main() {
	scanf("%d%d", &n, &m);
	Union uni(n);
	while (m--) {
		scanf("%d %c %d", &u, &op, &v);
		if (op == '=') {
			uni.merge(u, v);
		}
		else {
			vp.emplace_back(u, v);
		}
	}

	node.resize(n);
	for (auto& pii : vp) {
		u = uni.find(pii.first);
		v = uni.find(pii.second);
		node[u].push_back(v);
	}

	for (int i = 0; i < n; ++i) {
		if (findCycle(i)) {
			puts("inconsistent");
			return 0;
		}
	}
	puts("consistent");
}