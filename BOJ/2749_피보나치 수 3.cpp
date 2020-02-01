#include <iostream>
using namespace std;

long long a[1500050];
int INF = 1000000;

void fibonacci()
{
	a[0] = 0;
	a[1] = 1;
	for (int i = 0; i < 1500000; i++)
		a[i + 2] = (a[i + 1] + a[i]) % INF;
}

int main()
{
	long long n;
	cin >> n;
	fibonacci();
	cout << a[n % 1500000] << "\n";

	return 0;
}