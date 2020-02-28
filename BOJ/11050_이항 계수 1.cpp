#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int factorial_arr[11];

void factorial(void)
{
	int i; factorial_arr[0] = 1;
	for (i = 1; i <= 10; i++)
		factorial_arr[i] = factorial_arr[i - 1] * i;
	return;
}

int main(void)
{
	int N, K;
	scanf("%d", &N);
	scanf("%d", &K);
	if (K < 0 || K > N) {
		printf("0\n");
		return 0;
	}
	factorial();
	printf("%d\n", factorial_arr[N] / factorial_arr[K] / factorial_arr[N - K]);
	return 0;
}