#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define ms 102
using namespace std;

struct MF {
	struct edge {
		int to, c, C, f;
		edge* d;
		edge(int to1 = -1, int c1 = 0) :to(to1), c(c1), C(c1), f(0), d(nullptr) {}
		int spare() { return c - f; }
		void addFlow(int f1) {
			f += f1;
			d->f -= f1;
		}
	};

	int S = 0, E = ms - 1, mf = 0, n, rows[50], cols[50], Mf, limit;
	vector<edge*>adj[ms];

	void init() {
		for (int i = 0; i < ms; i++)adj[i].clear();
		mf = 0;
	}

	void addEdge(int u, int v, int c) {
		edge* e1 = new edge(v, c), * e2 = new edge(u, 0);
		e1->d = e2;
		e2->d = e1;
		adj[u].push_back(e1);
		adj[v].push_back(e2);
	}

	int solve() {
		while (1) {
			int pre[ms];
			for (int i = 0; i < ms; i++)pre[i] = -1;
			edge* path[ms] = { 0 };
			queue<int> q;
			q.push(S);
			while (!q.empty()) {
				int now = q.front();
				q.pop();
				for (edge* e : adj[now]) {
					int next = e->to;
					if (pre[next] == -1 && e->spare() > 0) {
						pre[next] = now;
						path[next] = e;
						q.push(next);
						if (next == E)break;
					}
				}
			}
			if (pre[E] == -1)break;
			int flow = 1e9;
			for (int i = E; i != S; i = pre[i])flow = min(flow, path[i]->spare());
			for (int i = E; i != S; i = pre[i])path[i]->addFlow(flow);
			mf += flow;
		}
		return mf;
	}

	void inp() {
		cin >> n;
		for (int i = 0; i < n; i++)cin >> rows[i];
		for (int i = 0; i < n; i++)cin >> cols[i];
		for (int i = 0; i < n; i++) {
			addEdge(S, i + 1, rows[i]);
			for (int j = 0; j < n; j++) {
				addEdge(i + 1, n + j + 1, min(rows[i], cols[j]));
			}
			addEdge(n + i + 1, E, cols[i]);
		}
		Mf = solve();

		int l = 1, r = 1001;
		while (l <= r) {
			mf = 0;
			limit = (l + r) >> 1;
			for (int i = 0; i < ms; i++)for (edge* e : adj[i]) {
				e->f = 0;
				if (e->to != S && e->to != E && i != 0) {
					e->c = min(limit, e->C);
				}
			}
			solve();
			if (mf == Mf) r = limit - 1;
			else l = limit + 1;
		}
		if (mf != Mf) {
			limit = l > r ? l : r;
			for (int i = 0; i < ms; i++)for (edge* e : adj[i]) {
				e->f = 0;
				if (e->to != S && e->to != E && i != 0) {
					e->c = min(limit, e->C);
				}
			}
			solve();
		}
		cout << limit << '\n';
		for (int i = 1; i <= n; i++) {
			for (edge* e : adj[i]) {
				if (e->to == S)continue;
				cout << e->f << ' ';
			}
			cout << '\n';
		}
	}
};

int main() {
	ios::sync_with_stdio(false), cin.tie(0);

	MF m;
	m.inp();
}