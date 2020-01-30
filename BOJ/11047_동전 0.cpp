#include <iostream>
using namespace std;

int main()
{
	int i, n, m = 0, k, a[11];
	cin >> n >> k;
	for (i = 1; i <= n; i++)
		cin >> a[i];

	for (i = n; i > 0; i--)
	{
		m += k / a[i];
		k %= a[i];
	}

	cout << m << endl;
	return 0;
}