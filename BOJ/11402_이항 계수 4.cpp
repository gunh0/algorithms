#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long

using namespace std;

ll d[2020][2020], n, r, mod;

ll binomial(ll x, ll y) {
	if (x < y) return 0;
	if (y == 0 || y == x) return 1;
	ll& ret = d[x][y];
	if (ret != -1) return ret;
	ret = binomial(x - 1, y - 1) % mod + binomial(x - 1, y) % mod;
	ret %= mod;
	return ret;
}

int main() {
	memset(d, -1, sizeof(d));
	cin >> n >> r >> mod;
	ll ret = 1;
	while (n || r) {
		ret *= binomial(n % mod, r % mod);
		ret %= mod;
		n /= mod;
		r /= mod;
	}
	printf("%lld\n", ret);
}
