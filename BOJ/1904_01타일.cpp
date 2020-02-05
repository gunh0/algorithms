#include <iostream>
#include <vector>

using namespace std;

#define MOD 15746

int main() {

	int n = 0;
	cin >> n;
	vector<long long int> dp;
	dp.push_back(0);
	dp.push_back(1);
	dp.push_back(2);

	for (int i = 3; i <= n; i++)
		dp.push_back((dp[i - 1] + dp[i - 2]) % MOD);
	cout << dp[n] << endl;

	return 0;
}