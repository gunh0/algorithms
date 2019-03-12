#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int m, d;
	printf("%.3s", "FRISATSUNMONTUEWEDTHU" - ((scanf("%d%d", &m, &d)<m) * 2 - d - m * 23 / 9) % 7 * 3);
	return 0;
}