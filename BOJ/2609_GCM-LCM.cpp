#include <iostream>

using namespace std;

int getGCD(int num1, int num2)
{
	int swp = 0;
	if (num2 > num1)
	{
		swp = num1;
		num1 = num2;
		num2 = swp;
	}
	while (num1%num2 != 0)
	{
		swp = num2;
		num2 = num1 % num2;
		num1 = swp;
	}
	return num2;
}

int main()
{
	int a = 0, b = 0;
	cin >> a >> b;

	int result = getGCD(a, b);
	cout << result << endl;
	cout << (a*b) / result << endl;
	return 0;
}