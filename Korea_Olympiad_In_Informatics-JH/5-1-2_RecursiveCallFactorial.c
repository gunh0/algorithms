#include <stdio.h>

int factorial(int n) {
	if (n == 0) return 1;
	else return n * factorial(n - 1);
}

int main()
{
	int n = 7, result;
	result = factorial(n);
	printf("%d", result);
	return 0;
}