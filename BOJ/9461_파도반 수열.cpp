#include<iostream>

using namespace std;
typedef long long ll;

ll dp[5000];

ll solve(int n)
{
	if (n <= 1)return n;
	else if (dp[n])return dp[n];
	else return (dp[n] = solve(n - 2) + solve(n - 3));
}

int main()
{
	dp[1] = dp[2] = 1;
	int t;
	cin >> t;
	for (; t--;) {
		int n;
		cin >> n;
		cout << solve(n) << '\n';
	}
	return 0;
}
