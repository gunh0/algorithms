#include <iostream>
#include <vector>
using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

int min(int a, int b, int c)
{
	if (a < b && a < c)
		return a;
	if (b < c)
		return b;
	return c;
}

int main(void)
{
	int N;
	cin >> N;

	vector<int> vec(N + 1);
	vec[1] = 0;

	for (int i = 2; i <= N; i++)
	{
		if (i % 6 == 0)
			vec[i] = min(vec[i / 3], vec[i / 2], vec[i - 1]) + 1;
		else if (i % 3 == 0)
			vec[i] = min(vec[i / 3], vec[i - 1]) + 1;
		else if (i % 2 == 0)
			vec[i] = min(vec[i / 2], vec[i - 1]) + 1;
		else
			vec[i] = vec[i - 1] + 1;
	}

	cout << vec[N] << endl;

	return 0;
}