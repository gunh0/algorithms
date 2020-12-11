#include <iostream>
#include <vector>
#include <set>

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> p;

const int di[] = { 1, 0, -1, 0, 1, 1, -1, -1 }, dj[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
ll mod(ll a, ll b) { return ((a % b) + b) % b; }
ll ext_gcd(ll a, ll b, ll& x, ll& y) { //ax + by = gcd(a, b)
	ll g = a; x = 1, y = 0;
	if (b) g = ext_gcd(b, a % b, y, x), y -= a / b * x;
	return g;
}
ll inv(ll a, ll m) { //return x when ax mod m = 1, fail -> -1
	ll x, y;
	ll g = ext_gcd(a, m, x, y);
	if (g > 1) return -1;
	return mod(x, m);
}
void finish() { exit(0); }

int sz[101010], use[101010], dep[101010];
int dp[22][101010];
vector<int> g[101010];
int cdtree[101010];
multiset<int> st[101010];
int color[101010];

void dfs(int now, int prv = -1) {
	dp[0][now] = prv;
	dep[now] = dep[prv] + 1;
	for (auto i : g[now]) {
		if (i == prv) continue;
		dfs(i, now);
	}
}

int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	int diff = dep[u] - dep[v];
	for (int i = 0; diff; i++) {
		if (diff & 1) u = dp[i][u];
		diff >>= 1;
	}
	if (u == v) return u;
	for (int i = 21; i >= 0; i--) {
		if (dp[i][u] ^ dp[i][v]) u = dp[i][u], v = dp[i][v];
	}
	return dp[0][u];
}

int getDist(int u, int v) {
	return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

int getSize(int now, int prv = -1) {
	sz[now] = 1;
	for (auto i : g[now]) {
		if (use[i] || prv == i) continue;
		sz[now] += getSize(i, now);
	}
	return sz[now];
}

int getCent(int now, int prv, int cnt) {
	for (auto i : g[now]) {
		if (use[i] || i == prv) continue;
		if (sz[i] > cnt / 2) return getCent(i, now, cnt);
	}
	return now;
}

void cd(int now, int prv = -1) {
	int cnt = getSize(now, prv);
	int cent = getCent(now, prv, cnt);
	if (prv == -1) cdtree[cent] = cent;
	else cdtree[cent] = prv;
	use[cent] = 1;
	for (auto i : g[cent]) {
		if (!use[i]) cd(i, cent);
	}
}

void update(int v) {
	color[v] = !color[v];
	int i = v;
	while (1) {
		int dist = getDist(i, v);
		if (color[v]) st[i].insert(dist);
		else {
			st[i].erase(st[i].find(dist));
		}
		if (i == cdtree[i]) break;
		i = cdtree[i];
	}
}

int query(int v) {
	int i = v;
	int ret = 1e9 + 7;
	while (1) {
		int dist = getDist(i, v);
		if (!st[i].empty()) ret = min(ret, dist + *st[i].begin());
		if (i == cdtree[i]) break;
		i = cdtree[i];
	}
	if (ret > 1e9) return -1;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int s, e; cin >> s >> e;
		g[s].push_back(e); g[e].push_back(s);
	}
	dfs(1);
	for (int j = 1; j < 22; j++) {
		for (int i = 1; i <= n; i++) {
			dp[j][i] = dp[j - 1][dp[j - 1][i]];
		}
	}
	cd(1);
	int q; cin >> q;
	while (q--) {
		int op, v; cin >> op >> v;
		if (op == 1) {
			update(v);

		}
		else {
			cout << query(v) << "\n";
		}
	}
}