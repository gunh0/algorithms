#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

typedef long long ll;
#define f first
#define s second

int main() {
	int b[27][9], d[9];
	ll m, p[9] = { 2,3,5,7,11,13,17,19,23 };
	vector<pair<ll, ll>> ans;

	for (int i = 2; i <= 26; i++) {		// 26까지 소인수분해
		for (int j = 0; j < 9; j++) {
			b[i][j] = 0;
			for (ll k = i; k > 0 && k % p[j] == 0; k /= p[j]) b[i][j]++;
		}
	}

	cin >> m;
	ans.push_back({ m,1ll });	// k=1인 경우
	ans.push_back({ m,m - 1ll });

	ll t = ll(sqrt(m * 2ll)) + 1ll;
	if (t * (t - 1) == m * 2ll) {	// k=2인 경우
		ans.push_back({ t,2ll });
		ans.push_back({ t,t - 2ll });
	}

	for (ll k = 3; k <= 26ll; k++) {	// k>=3인 경우
		for (ll n = k * 2ll; ; n++) {
			ll x = 1;
			for (int i = 0; i < 9; i++) {
				d[i] = 0;
				for (int j = 2; j <= k; j++) d[i] += b[j][i];
			}
			for (ll i = n - k + 1ll; i <= n; i++) {
				x *= i;
				for (int j = 0; j < 9; j++) while (d[j] > 0 && !(x % p[j])) { x /= p[j]; d[j]--; }
			}
			if (x == m) {
				ans.push_back({ n,k });
				ans.push_back({ n,n - k });
			}
			if (x > m) break;
		}
	}

	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());	// 중복 제거
	printf("%d\n", int(ans.size()));
	for (auto i : ans) printf("%lld %lld\n", i.f, i.s);
	return 0;
}