#include <iostream>
#define MOD 1000000000

using namespace std;

int a[2][12];

int main() {
	int n, ans = 9;

	cin >> n;

	for (int i = 2; i < 11; i++)
		a[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		ans = 0;
		for (int j = 1; j < 11; j++) {
			a[i % 2][j] = (a[(i - 1) % 2][j - 1] + a[(i - 1) % 2][j + 1]) % MOD;
			ans = (ans + a[i % 2][j]) % MOD;
		}
	}

	printf("%d", ans);

	return 0;
}