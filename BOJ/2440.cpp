#include <iostream>

using namespace std;

int main()
{
	int cnt = 0;
	cin >> cnt;
	for (; cnt != 0; cnt--)	// 조건이 맞을때까지 실행
	{
		int stars = cnt;
		for (; stars != 0; stars--)
		{
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}

