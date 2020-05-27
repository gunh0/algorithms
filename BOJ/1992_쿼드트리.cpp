#include <iostream>
#include <string>

using namespace std;

const int MAX = 64;
int N;
int arr[MAX][MAX];

void compress(int n, int y, int x)
{
	if (n == 1)
	{
		cout << arr[y][x];
		return;
	}

	bool zero = true, one = true;
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (arr[i][j])
				zero = false;
			else
				one = false;
		}
	}

	if (zero)
		cout << 0;
	else if (one)
		cout << 1;
	else
	{
		cout << "(";
		compress(n / 2, y, x);  //2사분면
		compress(n / 2, y, x + n / 2);  //1사분면
		compress(n / 2, y + n / 2, x);  //3사분면
		compress(n / 2, y + n / 2, x + n / 2);  //4사분면
		cout << ")";
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	bool zero = true, one = true;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < N; j++)
			arr[i][j] = s[j] - '0';
	}

	compress(N, 0, 0);
	cout << "\n";

	return 0;
}
