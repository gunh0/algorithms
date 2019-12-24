#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define SIZE 10001

int isNotPrime[SIZE];

void eratosthenes() {
	for (int i = 2; i * i < SIZE; i++)
		if (!isNotPrime[i])
			for (int j = i * i; j < SIZE; j += i)
				isNotPrime[j] = 1;
	isNotPrime[1] = 1;
}

void goldBach(int n) {
	int i, j, mid = n >> 1;
	for (i = j = mid; i <= n; i--, j++)
		if (!isNotPrime[i] && !isNotPrime[j]) {
			printf("%d %d\n", i, j);
			return;
		}
}

int main() {
	eratosthenes();
	int n, t; scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		goldBach(n);
	}
	return 0;
}