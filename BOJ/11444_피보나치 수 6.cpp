#include <iostream>

using namespace std;

struct M
{
	long long data[2][2];
};

M multiply(M a, M b)
{
	M c;
	c.data[0][0] = (a.data[0][0] * b.data[0][0] + a.data[0][1] * b.data[1][0]) % 1000000007;
	c.data[0][1] = (a.data[0][0] * b.data[0][1] + a.data[0][1] * b.data[1][1]) % 1000000007;
	c.data[1][0] = (a.data[1][0] * b.data[0][0] + a.data[1][1] * b.data[1][0]) % 1000000007;
	c.data[1][1] = (a.data[1][0] * b.data[0][1] + a.data[1][1] * b.data[1][1]) % 1000000007;
	return c;
}

M divide(M a, long long  x)
{
	if (x > 1)
	{
		a = divide(a, x / 2);
		a = multiply(a, a);
		if (x % 2 == 1)
		{
			M b;
			b.data[0][0] = 1; b.data[0][1] = 1;
			b.data[1][0] = 1; b.data[1][1] = 0;
			a = multiply(a, b);
		}
	}
	return a;
}

long long fibo(long long x)
{

	M a;
	a.data[0][0] = 1; a.data[0][1] = 1;
	a.data[1][0] = 1; a.data[1][1] = 0;
	a = divide(a, x);
	return a.data[0][1];
}

int main()
{
	long long n;
	cin >> n;
	if (n == 0) { cout << 0 << endl; return 0; }
	cout << fibo(n) << endl;
	return 0;
}