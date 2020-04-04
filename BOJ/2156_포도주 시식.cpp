#include <iostream>

using namespace std;

int get_max(int a, int b) { return a > b ? a : b; }

int main() {
	int n, i, ans = 0;

	cin >> n;
	int arr[10003] = { 0, };
	int dp[10003] = { 0, };

	for (i = 3; i < n + 3; i++) 
		cin >> arr[i];

	for (i = 3; i < n + 3; i++) {
		dp[i] = get_max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
		dp[i] = get_max(dp[i - 1], dp[i]);
		ans = get_max(ans, dp[i]);
	}

	printf("%d\n", ans);

	return 0;
}