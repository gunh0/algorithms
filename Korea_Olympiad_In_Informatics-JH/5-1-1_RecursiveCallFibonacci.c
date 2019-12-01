#include <stdio.h>

int fibonacci(int n) {
	if (n == 1) return 0;
	else if (n == 2) return 1;
	else return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
	int n = 7, result;

	result = fibonacci(n);
	printf("%d", result);
}