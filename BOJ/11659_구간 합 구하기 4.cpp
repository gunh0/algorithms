#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N = 0, M = 0;
	int vec[100001] = { 0, };

	scanf("%d %d", &N, &M);

	int input = 0;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &input);
		vec[i] = vec[i - 1] + input;
	}

	int a = 0, b = 0;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", vec[b] - vec[a - 1]);
	}

	return 0;
}