#include <algorithm>
#include <complex>
#include <cstring>
#include <iostream>
#include <vector>

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

vector<int> prime;
bool isp[101010];
void sieve(int n = 100000) {
	memset(isp, 1, sizeof isp);
	for (int i = 2; i <= n; i++) {
		if (isp[i]) prime.push_back(i);
		for (auto j : prime) {
			if (i * j > n) break;
			isp[i * j] = 0;
			if (i % j == 0) break;
		}
	}
}

// FFT
typedef complex<double> cpx;
void fft(vector<cpx>& a, bool inv) {
	int n = a.size(), j = 0;
	vector<cpx> roots(n / 2);
	for (int i = 1; i < n; i++) {
		int bit = (n >> 1);
		while (j >= bit) j -= bit, bit >>= 1;
		j += bit;
		if (i < j) swap(a[i], a[j]);
	}
	double ang = 2 * acos(-1) / n * (inv ? -1 : 1);
	for (int i = 0; i < n / 2; i++) roots[i] = cpx(cos(ang * i), sin(ang * i));
	for (int i = 2; i <= n; i <<= 1) {
		int step = n / i;
		for (int j = 0; j < n; j += i) for (int k = 0; k < i / 2; k++) {
			cpx u = a[j + k], v = a[j + k + i / 2] * roots[step * k];
			a[j + k] = u + v; a[j + k + i / 2] = u - v;
		}
	}
	if (inv) for (int i = 0; i < n; i++) a[i] /= n;
}
vector<ll> multiply(vector<ll>& v, vector<ll>& w) {
	vector<cpx> fv(v.begin(), v.end()), fw(w.begin(), w.end());
	int n = 2; while (n < v.size() + w.size()) n <<= 1;
	fv.resize(n); fw.resize(n);
	fft(fv, 0); fft(fw, 0);
	for (int i = 0; i < n; i++) fv[i] *= fw[i];
	fft(fv, 1);
	vector<ll> ret(n);
	for (int i = 0; i < n; i++) ret[i] = (ll)round(fv[i].real());
	return ret;
}

ll n;
vector<int> g[101010];
int sz[101010], use[101010];
ll cnt[101010];

// Centroid
int getSize(int v, int p) {
	sz[v] = 1;
	for (auto i : g[v]) if (i != p && !use[i]) {
		sz[v] += getSize(i, v);
	}
	return sz[v];
}
int getCent(int v, int p, int s) {
	for (auto i : g[v]) if (i != p && !use[i]) {
		if (sz[i] > s / 2) return getCent(i, v, s);
	}
	return v;
}

vector<ll> subtree, acc; int depth;

void update_sub(int v, int p, int d) {
	depth = max(depth, d);
	subtree[d]++;
	for (auto i : g[v]) if (i != p && !use[i]) update_sub(i, v, d + 1);
}

void calc() {
	auto t = multiply(subtree, acc);
	for (int i = 1; i < t.size(); i++) cnt[i] += t[i];
}

void solve(int v) {
	int cent = getCent(v, -1, getSize(v, -1));
	getSize(cent, -1);
	use[cent] = 1;
	acc.resize(1); acc.reserve(sz[cent] + 1);
	acc[0] = 1;
	sort(all(g[cent]), [&](int a, int b) { return sz[a] < sz[b]; });

	for (auto i : g[cent]) if (!use[i]) {
		depth = 0; subtree.clear(); subtree.resize(sz[i] + 1);
		update_sub(i, cent, 1);
		calc();
		if (acc.size() <= depth) acc.resize(depth + 1);
		for (int j = 0; j <= depth; j++) acc[j] += subtree[j];
	}
	for (auto i : g[cent]) if (!use[i]) solve(i);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int s, e; cin >> s >> e;
		g[s].push_back(e);
		g[e].push_back(s);
	}
	solve(1);
	sieve();
	ll sum = 0;
	for (auto i : prime) sum += cnt[i];
	cout << fixed; cout.precision(10);
	cout << 1.0 * sum / (n * (n - 1) / 2);
}