#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N, result = 0, i;
	scanf("%d", &N); getchar();	//������ �б� ���� ����.
	for (i = 0; i < N; i++)
		result += getchar() - '0';
	printf("%d\n", result);
}