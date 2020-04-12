#include <iostream>

using namespace std;

int main() {
	int T, n, i, j, cnt;
	int DP[11];

	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 4;

	cin >> T;

	for (i = 0; i < T; i++) {
		cin >> n;
		for (j = 4; j <= n; j++) {
			DP[j] = DP[j - 1] + DP[j - 2] + DP[j - 3];
		}
		printf("%d\n", DP[n]);
	}

	return 0;
}