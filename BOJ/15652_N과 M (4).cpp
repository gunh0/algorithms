#include <iostream>
#include <vector>

using namespace std;

const int MAX = 8 + 1;

int N, M;
int arr[MAX];

void func(int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = (cnt == 0) ? 1 : arr[cnt - 1]; i <= N; i++)
	{
		arr[cnt] = i;
		func(cnt + 1);
	}
}

int main(void)
{
	cin >> N >> M;

	func(0);
	return 0;
}