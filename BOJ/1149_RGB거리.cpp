#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001][4];
int a[1001][4];

int main() {
	int n = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> a[i][j];
		}
	}

	// 첫 번째 집 색칠 하는 가격 설정
	for (int i = 1; i <= 3; i++)
		dp[1][i] = a[1][i];

	for (int i = 2; i <= n; i++) {
		dp[i][2] = min(dp[i - 1][3], dp[i - 1][1]) + a[i][2];
		dp[i][1] = min(dp[i - 1][3], dp[i - 1][2]) + a[i][1];
		dp[i][3] = min(dp[i - 1][1], dp[i - 1][2]) + a[i][3];
	}

	printf("%d", min(min(dp[n][1], dp[n][2]), dp[n][3]));

	return 0;
}