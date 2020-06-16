#include <iostream>
#include <algorithm>

#define MAX 101

using namespace std;

int n, m;
int memory[MAX];
int cost[MAX];
int dp[10001];
int sum;

int main(void) {
	sum = 0;
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0, a; i < n; i++)
		cin >> memory[i];

	for (int i = 0, b; i < n; i++) {
		cin >> cost[i];
		sum += cost[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = sum; j >= cost[i]; j--) {
			dp[j] = max(dp[j], dp[j - cost[i]] + memory[i]);
		}
	}

	int i = 0;
	for (i = 0; i < sum, dp[i] < m; i++);
	cout << i << endl;

	return 0;
}