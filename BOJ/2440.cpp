#include <iostream>

using namespace std;

int main()
{
	int cnt = 0;
	cin >> cnt;
	for (; cnt != 0; cnt--)	// ������ ���������� ����
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

