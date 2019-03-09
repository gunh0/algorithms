#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
	int numerator = 0;
	int denominator = 0;
	int reverse = 0;

	scanf("%d/%d", &numerator, &denominator);

	do{
		reverse = denominator / numerator;
		printf("1/%d + ", reverse + 1);
		numerator = numerator*(reverse + 1) - denominator;
		denominator = denominator*(reverse + 1);
	} while (numerator != 1);
	printf("1/%d\n", denominator);

	return 0;
}
