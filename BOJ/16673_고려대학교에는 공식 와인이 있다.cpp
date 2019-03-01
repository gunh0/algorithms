#include <iostream>

using namespace std;

int main()
{
	int C = 0, K = 0, P = 0;
	int result = 0;

	cin >> C >> K >> P;

	for (int i = 1; i <= C; i++)
	{
		result += (K*i + P*i*i);
	}
	cout << result << endl;
}