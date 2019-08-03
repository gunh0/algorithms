#include <iostream>

using namespace std;

int main()
{
	int input1 = 0, input2 = 0;
	int mul_tmp = 0, result = 0;
	int cnt10 = 1;
	cin >> input1 >> input2;
	while (input2 != 0)
	{
		mul_tmp = (input2 % 10) * input1;
		input2 /= 10;
		cout << mul_tmp << endl;
		result += mul_tmp * cnt10;
		cnt10 *= 10;
	}
	cout << result << endl;
	return 0;
}
