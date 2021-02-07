#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N, result = 0, i;
	scanf("%d", &N);
	getchar(); // 개행을 읽기 위해 넣음.
	for (i = 0; i < N; i++)
		result += getchar() - '0';
	printf("%d\n", result);
}