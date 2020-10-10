#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f;

int n;
vector<pair<ll, ll>> p;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	ll s, e;
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		p.emplace_back(s, e);
	}
	sort(p.begin(), p.end());
	ll ans = 0;
	s = -INF, e = -INF;
	for (int i = 0; i < p.size(); i++) {
		auto cur = p[i];
		ll ns = cur.first, ne = cur.second;

		// case 1
		if (s <= ns && ne <= e)
			continue;
		ans += ne - ns;

		// case 2
		if (ns < e)
			ans -= (e - ns);

		s = ns;
		e = ne;
	}
	cout << ans;
	return 0;
}