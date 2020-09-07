#include <iostream>

using namespace std;

#define MEM 5005
#define sanic ios_base::sync_with_stdio(0)
#define MOD 1000000

typedef long long lld;
const int INF = 1e9 + 7;
int t;
int n;
int ls[MEM], dp[MEM][MEM], k[MEM][MEM];

int main() {
	sanic;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> ls[i];
			ls[i] += ls[i - 1];
		}
		for (int i = 1; i <= n; i++)
			dp[i - 1][i] = 0, k[i - 1][i] = i;
		for (int i = 2; i <= n; i++) {
			for (int l = 0; l <= n - i; l++) {
				int r = l + i;
				dp[l][r] = INF;
				for (int j = k[l][r - 1]; j <= k[l + 1][r]; j++) {
					int now = dp[l][j] + dp[j][r] + ls[r] - ls[l];
					if (dp[l][r] > now) {
						dp[l][r] = now;
						k[l][r] = j;
					}
				}
			}
		}
		cout << dp[0][n] << '\n';
	}

	return 0;
}