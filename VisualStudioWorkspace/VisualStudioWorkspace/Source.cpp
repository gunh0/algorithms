#include <stdio.h>
#include <math.h>

int main()
{
	int number = 2, order = 0, a, i;
	while (order <= 50000) {
		a = 0;
		for (i = 1; i <= sqrt(number); i++)
		{
			if (number % i == 0)
				a++;
		}
		if (a == 1) {
			order++;
			if (order == 50000)
				printf("%d", number);
		}
		number++;
	}

	return 0;
}