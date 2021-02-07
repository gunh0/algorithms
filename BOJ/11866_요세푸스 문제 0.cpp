#include <iostream>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	int *arr = new int[N]{
		0,
	};
	int *order = new int[N];
	int point = -1;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < K; j++)
		{
			if (arr[(++point) % N] != 0)
				j--;
		}
		arr[point % N] = 1;
		order[i] = point % N + 1;
	}
	cout << '<' << order[0];
	for (size_t i = 1; i < N; i++)
		cout << ", " << order[i];
	cout << '>';
	return 0;
}