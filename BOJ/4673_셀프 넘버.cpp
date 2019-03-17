#include <iostream>

using namespace std;

int selfNum(int num)
{
	int result = num;
	while (num != 0)
	{
		result += num % 10;
		num /= 10;
	}
	return result;
}

int main()
{
	int arr[11111] = { 0, };
	for (int i = 1; i < 10001; i++)
	{
		arr[selfNum(i)] = 1;
		if (arr[i]==0)
			cout << i << endl;
	}

	return 0;
}