#include <iostream>

using namespace std;

int main()
{
	int a = 0, b = 0, c = 0;
	unsigned int result = 0;
	int cnt[10] = { 0, };

	cin >> a >> b >> c;
	result = a * b * c;

	while (result != 0)
	{
		cnt[result % 10]++;
		result /= 10;
	}
	for (int i = 0; i < 10; i++)
		cout << cnt[i] << endl;

	return 0;
}