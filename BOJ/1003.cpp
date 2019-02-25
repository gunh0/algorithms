#include <iostream>
using namespace std;

int main()
{
	int a = 0, b = 0, pb = 0, n = 0, cnt=0;
	cin >> cnt;
	for (int j = 0; j < cnt; j++)
	{
		cin >> n;
		a = 0, b = 0, pb = 0;
		if (n == 0)
		{
			cout << "1 0" << endl;
			continue;
		}
		for (int i = 1; i <= n; i++)
		{
			if (i == 1)	b += 1;
			else
			{
				pb = b;
				b += a;
				a = pb;
			}
		}
		cout << a << " " << b << endl;
	}
	return 0;
}
