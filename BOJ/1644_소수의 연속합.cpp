#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
	int n;
	vector<int> primes;
	vector<bool> check;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	check.resize(n + 1, true);
	for (int i = 2; i * i <= n; i++)
	{
		if (!check[i]) continue;
		for (int j = i * i; j <= n; j += i)
			check[j] = false;
	}
	for (int i = 2; i <= n; i++)
		if (check[i]) primes.push_back(i);

	int result = 0, sum = 0, lo = 0, hi = 0;

	while (1)
	{
		if (sum >= n) {
			sum -= primes[lo++];
		}
		else if (hi == primes.size()) {
			break;
		}
		else {
			sum += primes[hi++];
		}

		if (sum == n) result++;
	}

	cout << result;
	return 0;
}