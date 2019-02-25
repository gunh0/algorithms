#include <iostream>

using namespace std;

int main()
{
	int n = 0, m = 0, cnt = 0, nn = 0;
	scanf_s("%d %d", &n, &m);
	nn = n;
	while (n > 0)
	{
		n /= 10;
		cnt++;
	}

	if (nn*cnt <= m)
	{
		for (int i = 0; i < nn; i++)
			printf("%d", nn);
	}
	else
	{
		for (int i = 0; i < m / cnt; i++)
			printf("%d", nn);
		m %= cnt;
		if (m != 0)
		{
			for (int i = 0; i < cnt - m; i++)
				nn /= 10;
			printf("%d", nn);
		}
	}
	return 0;
}