#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring> //memset

using namespace std;

const int MAX = 2000;
int N, M;
int arr[MAX + 1];
bool cache[MAX + 1][MAX + 1];

void palindrome(void)
{
	//���� 1
	for (int i = 1; i <= N; i++)
		cache[i][i] = true;

	//���� 2
	for (int i = 1; i < N; i++)
	{
		if (arr[i] == arr[i + 1])
			cache[i][i + 1] = true;
	}

	//���� 3 �̻�
	for (int i = 2; i < N; i++)
	{
		for (int j = 1; j <= N - i; j++)
			//�� �ڰ� ����, �� �� ���̿� �ִ� ������ �Ӹ������ ���
			if (arr[j] == arr[j + i] && cache[j + 1][j + i - 1])
				cache[j][j + i] = true;
	}
}

int main(void)
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	cin >> M;
	memset(cache, false, sizeof(cache));
	palindrome();

	for (int i = 0; i < M; i++)
	{
		int S, E;
		scanf("%d %d", &S, &E); //start, end
		printf("%d\n", cache[S][E]);
	}

	return 0;
}