#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int x, y;
		cin >> x >> y;

		long long i = 1;
		while (i * i <= (y - x))
			i++;
		i--;

		long long remaining = (y - x) - (i * i);
		remaining = (long long)ceil((double)remaining / (double)i);

		cout << i * 2 - 1 + remaining << "\n";
	}

	return 0;
}