#include <iostream>

using namespace std;

int main()
{
	int x = 0,cnt=1, sum=2;
	cin >> x;
	while (cnt < x)
	{
		cnt += sum;
		sum += 1;
	}
	x = x - (cnt - (sum - 1));
	if (sum % 2 == 0)
		printf("%d/%d", sum - x, x);
	else
		printf("%d/%d", x, sum - x);
}