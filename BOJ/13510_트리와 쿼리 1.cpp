#include <iostream>
#include <vector>
#include <cmath>

#define rep(i, n) for (int i = 0; i < n; ++i)
#define REP(i, n) for (int i = 1; i <= n; ++i)
#define FAST                                                                                                           \
    cin.tie(NULL);                                                                                                     \
    cout.tie(NULL);                                                                                                    \
    ios::sync_with_stdio(false)

using namespace std;

const int MAXN = 100001;

int N, M, Q, cnt, len;
vector<int> adj[MAXN];
int top[MAXN], pa[MAXN], sz[MAXN], idx[MAXN];
int eu[MAXN], ev[MAXN], ew[MAXN];
int tree[MAXN << 2];

int dfs(int here) {
	sz[here] = 1;
	for (auto& there : adj[here]) {
		if (pa[here] ^ there) {
			pa[there] = here;
			sz[here] += dfs(there);
			int& h = adj[here][0];

			if (h == pa[here] || sz[h] < sz[there])
				swap(h, there);
		}
	}
	return sz[here];
}

void hld(int here) {
	idx[here] = cnt++;
	for (auto there : adj[here]) {
		if (there ^ pa[here]) {
			top[there] = there == adj[here][0] ? top[here] : there;
			hld(there);
		}
	}
}
void init() {
	for (int i = 1; i < N; ++i) {
		if (pa[ev[i]] == eu[i])
			swap(ev[i], eu[i]);
		tree[len + idx[eu[i]]] = ew[i];
	}

	for (int i = len - 1; i > 0; --i) {
		tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
	}
}

void update(int i, int v) {
	tree[i += len] = v;
	i >>= 1;
	for (; i > 0; i >>= 1) {
		tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
	}
}

int query(int l, int r) {
	l += len;
	r += len;
	int ret = 0;
	for (; l <= r; l >>= 1, r >>= 1) {
		if (l & 1)
			ret = max(ret, tree[l++]);
		if (!(r & 1))
			ret = max(ret, tree[r--]);
	}
	return ret;
}

int solve(int u, int v) {
	int ret = 0;
	while (top[u] ^ top[v]) {
		if (sz[top[u]] < sz[top[v]])
			swap(u, v);
		ret = max(ret, query(idx[top[v]], idx[v]));
		v = pa[top[v]];
	}
	if (idx[u] > idx[v])
		swap(u, v);
	ret = max(ret, query(idx[u] + 1, idx[v]));
	return ret;
}

int main() {
	FAST;
	cin >> N;
	len = pow(2, ceil(log2(N)));

	for (int i = 1; i < N; ++i) {
		cin >> eu[i] >> ev[i] >> ew[i];
		eu[i]--;
		ev[i]--;
		adj[eu[i]].emplace_back(ev[i]);
		adj[ev[i]].emplace_back(eu[i]);
	}
	dfs(0);
	hld(0);
	init();
	cin >> Q;
	while (Q--) {
		int q, u, v;
		cin >> q >> u >> v;
		if (q == 1) {
			update(idx[eu[u]], v);
		}
		else {
			--u, --v;
			cout << solve(u, v) << '\n';
		}
	}
	return 0;
}