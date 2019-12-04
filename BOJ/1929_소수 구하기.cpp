#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
	int a, b;	// 1<=a<=b<=1,000,000

	scanf("%d %d", &a, &b);

	bool* check = new bool[b + 1];
	for (int i = 0; i < b + 1; i++) {
		check[i] = true;
	}

	int j;

	for (int i = 2; i < b + 1; i++) {
		if (check[i])
		{
			if ((unsigned int)pow(i, 2) > 1000001) {
				break;
			}
			else {
				for (j = (unsigned int)pow(i, 2); j < b + 1; j += i)
					check[j] = false;
			}
		}
	}

	if (a == 1)
		a++;

	for (int i = a; i < b + 1; i++) {
		if (check[i] && i >= a)
			printf("%d\n", i);
	}

	delete[] check;
	return 0;
}