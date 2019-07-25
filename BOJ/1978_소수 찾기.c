#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int input = 0;
	int arr[100] = { 0, };
	int num = 0;
	int	result = 0;
	int checkPrime = 0;
	scanf("%d", &input);

	for (int i = 0; i < input; i++)
	{
		num = 0;
		scanf("%d", &num);
		arr[i] = num;
	}

	for (int i = 0; i < input; i++)
	{
		for (checkPrime = 2; checkPrime < arr[i]; checkPrime++)
			if (arr[i] % checkPrime == 0)	break;
		if (checkPrime == arr[i])
		{
			printf("%d is prime\n", arr[i]);
			result++;
		}
	}

	printf("%d", result);
	return 0;
}