#include <iostream>

using namespace std;

int main()
{
	int n = 0, check=1, cnt=0;
	cin >> n;
	while (1)
	{
		if (n <= check)
		{
			cout << cnt+1;
			break;
		}
		cnt++;
		check += cnt * 6;
	}
}