#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	long long i, num;
	num = 600851475143;

	for (i = 2; i <= num; i++)
	{
		if (num%i == 0)
		{
			printf("%lld ", i);
			num = num / i;
		}
	}
	printf("\n");

	return 0;
}